/*
 * PointGenerator.h
 *
 *  Created on: Aug 14, 2017
 *      Author: minerva
 */

#include <list>

#ifndef SRC_POINTGENERATOR_H_
#define SRC_POINTGENERATOR_H_

class PointGenerator {
public:
	PointGenerator(float cost, float pointRate, int index);
	virtual ~PointGenerator();
	static int numGenerators;
	// The compiler complains when these are defined here.
	//static std::list<PointGenerator> allGenerators;
	//static std::list<PointGenerator>::iterator genIter;

	int index;
	int amount;       // How many of this PointGenerator are owned
	double cost;      // How much does this PointGenerator cost
	double pointRate; // How many points does this PointGenerator give
	int AddAmount( int number );
	int Add ( void );
	int SubAmount( int number );
	int Sub( void );
	bool BuyAmount( int number);
	bool Buy( void );
	int BuyMax( void );
	double GeneratePoints( void );
	int getAmount( void );
	void setAmount(int amount );
};

#endif /* SRC_POINTGENERATOR_H_ */
