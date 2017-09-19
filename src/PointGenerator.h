/*
 * PointGenerator.h
 *
 *  Created on: Aug 14, 2017
 *      Author: EmergencyTemporalShift
 */

#include <list>
//#include "Game.h"

#ifndef SRC_POINTGENERATOR_H_
#define SRC_POINTGENERATOR_H_

class PointGenerator {
public:
	PointGenerator(Game game, float cost, float pointRate);
	virtual ~PointGenerator( void );
	static int numGenerators;
	// The compiler complains when these are defined here.
	//static std::list<PointGenerator> allGenerators;
	//static std::list<PointGenerator>::iterator genIter;

	int index;
	int amount;       // How many of this PointGenerator are owned
	double cost;      // How much does this PointGenerator cost
	double pointRate; // How many points does this PointGenerator give
	Game game;        // Reference? to the game object

	void collapseAllGenerators( void );

	int AddAmount( int number );
	int Add ( void );
	int SubtractAmount( int number );
	int Subtract( void );
	int BuyUpTo( int number );
	bool BuyAmount( int number);
	bool Buy( void );
	int BuyMax( void );
	int BuyPercentMax( float partOfMax );
	static double GenerateAllPoints( void );
	static double GeneratePoints( PointGenerator pointGenerator );
	double GeneratePoints( void );
	int getAmount( void );
	void setAmount(int amount );
};

#endif /* SRC_POINTGENERATOR_H_ */
