// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"
//Static mesh include file
#include "Components/SkeletalMeshComponent.h"
#include"Kismet/GameplayStatics.h"
#include"DrawDebugHelpers.h"
#include "GameFramework/DamageType.h"
#include <Engine/DamageEvents.h>


// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("ROOT"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);

}

void AGun::PullTrigger()
{
	UE_LOG(LogTemp, Warning, TEXT("You've have been shot!"));
	UGameplayStatics::SpawnEmitterAttached(MuzzleFlash,Mesh, TEXT("MuzzleFLashSocket"));

	APawn* OwnerPawn=Cast<APawn>(GetOwner());

	if (OwnerPawn == nullptr)return;

	AController* OwnerController = OwnerPawn->GetController();
	if (OwnerController == nullptr)return;

	FVector Location;
	FRotator Rotation;
	OwnerController->GetPlayerViewPoint(Location, Rotation);

	FVector End = Location + Rotation.Vector()*MaxRange;

	//LineTracing

	//DrawDebugPoint(GetWorld(), Location, 20, FColor::Red, true);

	FHitResult Hit;
	bool bSuccess = GetWorld()->LineTraceSingleByChannel(Hit, Location, End, ECollisionChannel::ECC_GameTraceChannel1);
	if (bSuccess)
	{
		FVector ShortDirection = -Rotation.Vector();
		// DrawDebugPoint(GetWorld(), Hit.Location, 20, FColor::Red, true);
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactEffect, Hit.Location, ShortDirection.Rotation());

		AActor* HitActor = Hit.GetActor();
		if (HitActor != nullptr)
		{
			FPointDamageEvent DamageEvent(Damage, Hit, ShortDirection, nullptr);
			HitActor->TakeDamage(Damage, DamageEvent, OwnerController, this);
		}

	}
	//DrawDebugCamera(GetWorld(), Location, Rotation, 90, 2, FColor::Red, true);//Viewportlocation
}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

