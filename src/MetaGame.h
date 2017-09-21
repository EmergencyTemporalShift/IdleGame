/*
 * MetaGame.h
 *
 *  Created on: Sep 21, 2017
 *      Author: EmergencyTemporalShift
 */

#ifndef SRC_METAGAME_H_
#define SRC_METAGAME_H_

static class MetaGame {
public:
	MetaGame( void );
	virtual ~MetaGame( void );

	std::chrono::_V2::system_clock::time_point newTime;
	std::chrono::_V2::system_clock::time_point oldTime;
	std::chrono::_V2::system_clock::duration deltaTime;
	void updateDelta( void );
};

#endif /* SRC_METAGAME_H_ */
