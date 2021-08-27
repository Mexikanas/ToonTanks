// Fill out your copyright notice in the Description page of Project Settings.


#include "TankGameModeBase.h"

void ATankGameModeBase::BeginPlay()
{
	//get references and game win/lose conditions.

	//call HandleGameStart() to intialise the start countdown, turret activation, pawn check etc.
}

void ATankGameModeBase::HandleGameStart()
{
	// initalise the start countdown, turret activation, pawn check etc.
	// call blueprint version GameStart()
}

void ATankGameModeBase::HandleGameOver(bool PlayerWon)
{
	// see if the player has destroyed all the turrets, show win result
	// else if turret destroyed player, show lose result
	//call blueprint version GameOver(bool)
}

void ATankGameModeBase::ActorDied(AActor* DeadActor)
{
	// check what type of Actor died. if turret, tally. if player -> got to lose condition
}

