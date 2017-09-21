#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include <signal.h>


#include "PointGenerator.h"

/*
 * Game.cpp
 *
 *  Created on: Aug 31, 2017
 *      Author: EmergencyTemporalShift
 */

#include "Game.h"

// These complain if defined in the header and don't if defined here
std::list<PointGenerator> allGenerators;
// I'm going to be honest, I have no idea what the iterator is for.
//static std::list<PointGenerator>::iterator genIter = allGenerators.begin();

Game::Game() {
	numGenerators = 0;
	gamePoints = 0;
}

Game::~Game() {
	// TODO Auto-generated destructor stub
}


void Game::setPoints( double points) {
	this->gamePoints = points;
}

double Game::getPoints( void ) {
	return this->gamePoints;
}

double Game::addPoints( double points ) {
	return this->gamePoints += points;
}

double Game::subtractPoints( double points ) {
	return this->gamePoints -= points;
}

int Game::getNumberOfGenerators( void ) {
	return numGenerators;
}
