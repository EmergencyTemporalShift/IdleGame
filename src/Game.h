#include <stdlib.h>
#include <chrono>
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
	Game();
	virtual ~Game();
	double gamePoints;
	std::chrono::_V2::system_clock::time_point newTime;
	std::chrono::_V2::system_clock::time_point oldTime;
	std::chrono::_V2::system_clock::duration deltaTime;
	void updateDelta();
	void setPoints( double points );
	double getPoints();
	double addPoints( double points );
	double subtractPoints( double points );
};

#endif /* SRC_GAME_H_ */
