/*
 * Generator.cpp
 *
 *  Created on: Aug 14, 2017
 *      Author: EmergencyTemporalShift
 */

#include "PointGenerator.h"
#include "stdio.h"
#include <list>

#include "Game.h"

extern Game game;

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

// I think this works, test later
int PointGenerator::BuyUpTo( int number ) {
	int max = ( game.getPoints() / this->cost );
	if (number > max) {
		PointGenerator::BuyAmount( max );
		return max;
	} else {
		PointGenerator::BuyAmount( number );
		return number;
	}
}

bool PointGenerator::BuyAmount( int number ) {
	// Might make cost increase after each one, for diminishing returns.
	if ( game.getPoints() >= (number * this->cost)) {
		game.subtractPoints(number * this->cost);
		this->amount += number;
		return true;
	} else {
		// I might want to buy as many as possible under the number specified.
		// Use BuyMax for that
		fprintf(stderr, "Not Enough Points;\n");
		fprintf(stderr, "There are %f points available,\n", game.getPoints());
		fprintf(stderr, "but you tried to buy %i PointGenerators for %f points\n", number, number * this->cost);
		return false;
	}
}

bool PointGenerator::Buy( void ) {
	return PointGenerator::BuyAmount( 1 );
}

int PointGenerator::BuyMax( void ) {
	// This won't work if price doesn't remain constant.
	int numberToBuy = game.getPoints() / this->cost;
	PointGenerator::BuyAmount( numberToBuy );
	return numberToBuy;
}

int PointGenerator::BuyPartMax( float partOfMax ) {
	int numberToBuy = game.getPoints() * partOfMax / this->cost + 1; // Round up
	PointGenerator::BuyAmount( numberToBuy );
	return numberToBuy;
}

static double GenerateAllPoints( void ) {
	double totalPointsGenerated = 0;
	std::list<PointGenerator>::iterator genIter;
	for (genIter = allGenerators.begin(); genIter != allGenerators.end(); ++genIter) {
		//How do you use iterators?
		//totalPointsGenerated += *genIterGeneratePoints(  );//GeneratePoints( genIter* );
	}
	return totalPointsGenerated;
}
// One of the next two functions might be better?
static double GeneratePoints( PointGenerator pointGenerator ) {
	// TODO: Make this use delta time;
	double pointsGenerated = pointGenerator.amount * pointGenerator.pointRate;
	game.addPoints( pointsGenerated );
	return pointsGenerated;
	}

double PointGenerator::GeneratePoints( void ) {
	// TODO: Make this use delta time;
	double pointsGenerated = this->amount * this->pointRate;
	game.addPoints( pointsGenerated );
	return pointsGenerated;
	}

int PointGenerator::getAmount( void ) {
	return this->amount;
}

void PointGenerator::setAmount( int amount ) {
	this->amount = amount;
}
