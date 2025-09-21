#include "LAN/MP_LANMenu.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "Kismet/GameplayStatics.h"

void UMP_LANMenu::NativeOnInitialized()
{

    Super::NativeOnInitialized();

    FInputModeUIOnly InputMode;
    GetOwningPlayer()->SetInputMode(InputMode);
    GetOwningPlayer()->SetShowMouseCursor(true);

    Button_Host->OnClicked.AddDynamic(this, &ThisClass::HostButtonClicked);
    Button_Join->OnClicked.AddDynamic(this, &ThisClass::JoinButtonClicked);
}

void UMP_LANMenu::HostButtonClicked()
{

    FInputModeGameOnly InputMode;
    GetOwningPlayer()->SetInputMode(InputMode);
    GetOwningPlayer()->SetShowMouseCursor(false);

    UGameplayStatics::OpenLevelBySoftObjectPtr(this, HostingLevel, true, TEXT("listen"));

}

void UMP_LANMenu::JoinButtonClicked()
{

    FInputModeGameOnly InputMode;
    GetOwningPlayer()->SetInputMode(InputMode);
    GetOwningPlayer()->SetShowMouseCursor(false);

    FString Address = TextBox_IpAddress->GetText().ToString();
    UGameplayStatics::OpenLevel(this, *Address);
}