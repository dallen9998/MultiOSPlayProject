// Fill out your copyright notice in the Description page of Project Settings.


#include "MP_MultiplayerUtils.h"

void UMP_MultiplayerUtils::PrintLocalNetRole(AActor *Actor)
{
    if(Actor->HasAuthority())
    {
        UE_LOG(LogTemp, Warning, TEXT("Actor [%s] has authority."), *Actor->GetName());
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Actor [%s] does not have authority."), *Actor->GetName());
    }

    switch(Actor->GetLocalRole())
    {
    case ROLE_None:
        UE_LOG(LogTemp, Warning, TEXT("Actor Role - None"));
        break;

    case ROLE_SimulatedProxy:
        UE_LOG(LogTemp, Warning, TEXT("Actor Role - SimulatedProxy"));
        break;  

    case ROLE_AutonomousProxy:
        UE_LOG(LogTemp, Warning, TEXT("Actor Role - AutonomousProxy"));
        break;

    case ROLE_Authority:
        UE_LOG(LogTemp, Warning, TEXT("Actor Role - Authority"));
        break;

    default:
        UE_LOG(LogTemp, Warning, TEXT("Actor Role - Unknown"));
        break;
    }

}

void UMP_MultiplayerUtils::PrintRemoteNetRole(AActor *Actor)
{
    if(Actor->HasAuthority())
    {
        UE_LOG(LogTemp, Warning, TEXT("Actor [%s] has authority."), *Actor->GetName());
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Actor [%s] does not have authority."), *Actor->GetName());
    }

    switch(Actor->GetRemoteRole())
    {
    case ROLE_None:
        UE_LOG(LogTemp, Warning, TEXT("Actor Remote Role - None"));
        break;

    case ROLE_SimulatedProxy:
        UE_LOG(LogTemp, Warning, TEXT("Actor Remote Role - SimulatedProxy"));
        break;  

    case ROLE_AutonomousProxy:
        UE_LOG(LogTemp, Warning, TEXT("Actor Remote Role - AutonomousProxy"));
        break;

    case ROLE_Authority:
        UE_LOG(LogTemp, Warning, TEXT("Actor Remote Role - Authority"));
        break;

    default:
        UE_LOG(LogTemp, Warning, TEXT("Actor Remote Role - Unknown"));
        break;
    }
}
