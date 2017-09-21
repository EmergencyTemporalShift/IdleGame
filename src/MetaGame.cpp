/*
 * MetaGame.cpp
 *
 *  Created on: 2017-09-21
 *      Author: EmergencyTemporalShift
 */

#include "MetaGame.h"




MetaGame::MetaGame( void ) {
	//std::chrono::high_resolution_clock Clock;

	std::chrono::_V2::system_clock::time_point newTime   = std::chrono::high_resolution_clock::now();
	std::chrono::_V2::system_clock::time_point oldTime   = newTime;
	std::chrono::_V2::system_clock::duration   deltaTime = newTime - oldTime;
}

MetaGame::~MetaGame( void ) {
	// TODO Auto-generated destructor stub
}

void MetaGame::updateDelta( void ) {
	this->oldTime   = newTime;
	this->newTime   = std::chrono::_V2::system_clock::now();
	this->deltaTime = newTime - oldTime;
}
