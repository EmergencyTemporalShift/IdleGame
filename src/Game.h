#include <list>

#pragma once
#include "PointGenerator.h"

/*
 * Game.h
 *
 *  Created on: 2017-08-31
 *      Author: EmergencyTemporalShift
 */

#ifndef SRC_GAME_H_
#define SRC_GAME_H_

class Game {
public:
	Game( void );
	virtual ~Game( void );
	double gamePoints;                        // How many points this game has
	int numGenerators;                        // How many PointGenerators this game has
	std::list<PointGenerator> gameGenerators; // A list of all PointGenerators owned by this game


	void setPoints( double points );
	double getPoints( void );
	double addPoints( double points );
	double subtractPoints( double points );
	int getNumberOfGenerators( void );
	static double GenerateAllPoints( void );
};

#endif /* SRC_GAME_H_ */
