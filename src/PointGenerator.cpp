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
	allGenerators.insert(genIter, this);
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

int PointGenerator::SubAmount( int number ) {
	return this->amount -= number;
}

int PointGenerator::Sub( void ) {
	return PointGenerator::SubAmount( 1 );
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

double PointGenerator::GeneratePoints( void ) { // PointGenerator pointGenerator ) {
	// TODO: Make this iterate over all generators in allGenerators
	// TODO: Make this use delta time;
	double pointsGenned = this->amount * this->pointRate;
	globalPoints += pointsGenned;
	return pointsGenned;
	}

int PointGenerator::getAmount( void ) {
	return this->amount;
}

void PointGenerator::setAmount( int amount ) {
	this->amount = amount;
}
