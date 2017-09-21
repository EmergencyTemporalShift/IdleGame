/*
 * MetaGame.cpp
 *
 *  Created on: Sep 21, 2017
 *      Author: EmergencyTemporalShift
 */

#include "MetaGame.h"




MetaGame::MetaGame() {
	//std::chrono::high_resolution_clock Clock;

	std::chrono::_V2::system_clock::time_point newTime   = std::chrono::high_resolution_clock::now();
	std::chrono::_V2::system_clock::time_point oldTime   = newTime;
	std::chrono::_V2::system_clock::duration   deltaTime = newTime - oldTime;
}

MetaGame::~MetaGame() {
	// TODO Auto-generated destructor stub
}

void MetaGame::updateDelta() {
	this->oldTime   = newTime;
	this->newTime   = std::chrono::_V2::system_clock::now();
	this->deltaTime = newTime - oldTime;
}
