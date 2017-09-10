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

//std::chrono::high_resolution_clock Clock;

std::chrono::_V2::system_clock::time_point newTime   = std::chrono::high_resolution_clock::now();
std::chrono::_V2::system_clock::time_point oldTime   = newTime;
std::chrono::_V2::system_clock::duration   deltaTime = newTime - oldTime;


Game::Game() {
	gamePoints = 0;
}

Game::~Game() {
	// TODO Auto-generated destructor stub
}




void Game::updateDelta() {
	this->oldTime   = newTime;
	this->newTime   = std::chrono::_V2::system_clock::now();
	this->deltaTime = newTime - oldTime;
}


void Game::setPoints( double points) {
	this->gamePoints = points;
}

double Game::getPoints() {
	return this->gamePoints;
}

double Game::addPoints( double points ) {
	return this->gamePoints += points;
}

double Game::subtractPoints( double points ) {
	return this->gamePoints -= points;
}
