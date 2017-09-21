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

// TODO: Refactor to use a game as an argument
// That way multiple games can run at once
//extern Game game;



PointGenerator::PointGenerator(Game *game, float cost, float pointRate) {
	this->game = &game;
	this->cost = cost;
	this->amount = 0;
	this->pointRate = pointRate;
	this->index = *game::numGenerators;
	Game::numGenerators += 1;

	// Here is where my problem is. What are the correct arguments for this function?
	// TODO: XXX: Fix arguments.
	//allGenerators.insert(genIter, this);
}

PointGenerator::~PointGenerator() {
	// TODO: Deconstruct stuff? Going to be honest, I have no idea what to do here.

	// Decrease the total amount of generators
	this->game::numGenerators -= 1;
	// TODO: Change genIter to point to the wanted PointGenerator maybe?
	//allGenerators.erase(genIter);
}

void PointGenerator::collapseAllGenerators( void ) {
	/* This method will take the indexes of all the pointGenerators in
	 * allGenerators and make them sequential
	 */

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
	int max = ( *game.getPoints() / this->cost );
	if (number > max) {
		PointGenerator::BuyAmount( max );
		return max;
	} else {
		PointGenerator::BuyAmount( number );
		return number;
	}
}

bool PointGenerator::BuyAmount( int number ) {
	// Might make cost increase for each bought, for diminishing returns.
	if ( game.getPoints() >= (number * this->cost) ) {
		game.subtractPoints(number * this->cost);
		this->amount += number;
		printf("\n");
		printf("Bought %i PointGenerators\n", number);
		printf("With a cost totaling %i\n", (int) (number * this->cost));
		printf("Making for a total of %i.\n\n", (int) this->amount);
		return true;
	} else {
		// I might want to buy as many as possible under the number specified.
		// Use BuyMax for that
		fprintf(stderr, "\n");
		fprintf(stderr, "Not Enough Points;\n");
		fprintf(stderr, "You have %i points available,\n", (int) this->game.getPoints());
		fprintf(stderr, "but you tried to buy %i PointGenerators for %i points\n\n", number, (int) (number * this->cost));
		return false;
	}
}

bool PointGenerator::Buy( void ) {
	return PointGenerator::BuyAmount( 1 );
}

int PointGenerator::BuyMax( void ) {
	// This won't work if price doesn't remain constant.
	int numberToBuy = this->game.getPoints() / this->cost;
	PointGenerator::BuyAmount( numberToBuy );
	return numberToBuy;
}

int PointGenerator::BuyPercentMax( float percentOfMax ) { // Never buys. TODO: Fix. Wait, does it?
	int numberToBuy = this->*game.getPoints() * (percentOfMax / 100) / this->cost;
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
/*
static double GeneratePoints( PointGenerator pointGenerator ) {
	// TODO: Make this use delta time;
	double pointsGenerated = pointGenerator.amount * pointGenerator.pointRate;
	this->game.addPoints( pointsGenerated );
	return pointsGenerated;
	}
*/

double PointGenerator::GeneratePoints( void ) {
	// TODO: Make this use delta time;
	double pointsGenerated = this->amount * this->pointRate;
	this->game.addPoints( pointsGenerated );
	return pointsGenerated;
	}

int PointGenerator::getAmount( void ) {
	return this->amount;
}

void PointGenerator::setAmount( int amount ) {
	this->amount = amount;
}
