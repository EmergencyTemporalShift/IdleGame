//#include <stdio.h>
//#include <stdlib.h>
//#include <chrono>
//#include <thread>
//#include <signal.h>


#include "PointGenerator.h"
#include "Game.h"

/*
 * Game.cpp
 *
 *  Created on: 2017-08-31
 *      Author: EmergencyTemporalShift
 */


Game::Game() {
	numGenerators = 0;
	gamePoints = 0;
	std::list<PointGenerator> gameGenerators;
	// I'm going to be honest, I have no idea what the iterator is for.
	//static std::list<PointGenerator>::iterator genIter = allGenerators.begin();

}

Game::~Game() {
	// TODO Auto-generated destructor stub
}


void Game::setPoints( double points) {
	gamePoints = points;
}

double Game::getPoints( void ) {
	return gamePoints;
}

double Game::addPoints( double points ) {
	return gamePoints += points;
}

double Game::subtractPoints( double points ) {
	return gamePoints -= points;
}

int Game::getNumberOfGeneratorTypes( void ) {
	return numGenerators;
}

double Game::GenerateAllPoints( void ) {
	double totalPointsGenerated = 0;
	std::list<PointGenerator>::iterator genIter;
	for (genIter = gameGenerators.begin(); genIter != gameGenerators.end(); ++genIter) {
		//How do you use iterators?
		//totalPointsGenerated += *genIterGeneratePoints(  );//GeneratePoints( genIter* );
	}
	return totalPointsGenerated;
}
