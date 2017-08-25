/*
 * Generator.cpp
 *
 *  Created on: Aug 14, 2017
 *      Author: EmergencyTemporalShift
 */

#include "PointGenerator.h"
#include "stdio.h"
#include <list>

extern int globalPoints;

int PointGenerator::numGenerators = 0;
// These complain if defined in the header and don't if defined here
static std::list<PointGenerator> allGenerators;
// I'm going to be honest, I have no idea what the iterator is for.
static std::list<PointGenerator>::iterator genIter = allGenerators.begin();

PointGenerator::PointGenerator(float cost, float pointRate, int index) {
	this->cost = cost;
	this->pointRate = pointRate;
	// I don't actually know how to auto allocate indexes
	// that play well with deleting PointGenerators/Elements.
	// So I'm manually specifying the index instead.
	this->index = index;
	this->amount = 0;
	PointGenerator::numGenerators += 1;
	// Here is where my problem is. What are the correct arguments for this function?
	// TODO: XXX: Fix arguments.
	//allGenerators.insert(genIter, this);
}

PointGenerator::~PointGenerator() {
	// TODO: Deconstruct stuff? Going to be honest, I have no idea what to do here.

	// Decrease the total amount of generators
	PointGenerator::numGenerators -= 1;
	// TODO: Change genIter to point to the wanted PointGenerator maybe?
	allGenerators.erase(genIter);
}

int PointGenerator::AddAmount( int number ) {
	return this->amount += number;
}

int PointGenerator::Add( void ) {
	return PointGenerator::AddAmount( 1 );
}

int PointGenerator::SubtractAmount( int number ) {
	return this->amount -= number;
}

int PointGenerator::Subtract( void ) {
	return PointGenerator::SubtractAmount( 1 );
}

bool PointGenerator::BuyAmount( int number ) {
	// Might make cost increase after each one, for diminishing returns.
	if (globalPoints >= (number * this->cost)) {
		globalPoints -= (number * this->cost);
		this->amount += number;
		return true;
	} else {
		// I might want to buy as many as possible under the number specified.
		fprintf(stderr, "Not Enough Points\n");
		return false;
	}
}

bool PointGenerator::Buy( void ) {
	return PointGenerator::BuyAmount( 1 );
}

int PointGenerator::BuyMax( void ) {
	int numberToBuy = globalPoints / this->cost;
	PointGenerator::BuyAmount( numberToBuy );
	return numberToBuy;
}

static double GenerateAllPoints( void ) {
	double totalPointsGenerated = 0;
	std::list<PointGenerator>::iterator genIter;
	for (genIter = allGenerators.begin(); genIter != allGenerators.end(); ++genIter) {
		//How do you use iterators?
		//totalPointsGenerated += GeneratePoints( genIter );
	}
	return totalPointsGenerated;
}
// One of the next two functions might be better?
static double GeneratePoints( PointGenerator pointGenerator ) { // PointGenerator pointGenerator ) {
	// TODO: Make this use delta time;
	double pointsGenerated = pointGenerator.amount * pointGenerator.pointRate;
	globalPoints += pointsGenerated;
	return pointsGenerated;
	}

double PointGenerator::GeneratePoints( void ) {
	// TODO: Make this use delta time;
	double pointsGenerated = this->amount * this->pointRate;
	globalPoints += pointsGenerated;
	return pointsGenerated;
	}

int PointGenerator::getAmount( void ) {
	return this->amount;
}

void PointGenerator::setAmount( int amount ) {
	this->amount = amount;
}
