#include <stdlib.h>
#include <chrono>
#include <list>
//#ifndef PointGenerator
	#include "PointGenerator.h"
//#endif


/*
 * Game.h
 *
 *  Created on: Aug 31, 2017
 *      Author: EmergencyTemporalShift
 */

#ifndef SRC_GAME_H_
#define SRC_GAME_H_

class Game {
public:
	Game( void );
	virtual ~Game( void );
	double gamePoints; // How many points this game has
	std::list<PointGenerator> gameGenerators;

	std::chrono::_V2::system_clock::time_point newTime;
	std::chrono::_V2::system_clock::time_point oldTime;
	std::chrono::_V2::system_clock::duration deltaTime;
	void updateDelta( void );
	void setPoints( double points );
	double getPoints( void );
	double addPoints( double points );
	double subtractPoints( double points );
};

#endif /* SRC_GAME_H_ */
