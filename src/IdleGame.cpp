#include <signal.h>
#include <stdio.h>
#include <chrono>
#include <thread>

#include "Game.h"
#include "MetaGame.h"
#include "PointGenerator.h"

/*
 * Idle Game
 *
 *  Created on: 2017-08-14
 *      Author: EmergencyTemporalShift
 *
 *      The purpose of this is to make a simple iteration/idle game
 *      that can be used with some form of machine learning and do
 *      cool stuff.
 */

int STEPTIME = 15;

// For Interrupts (Doesn't work)
static volatile sig_atomic_t flag = 0;
void sigint(int sig) { // can be called asynchronously
	flag = 1; // set flag
}

// Define the game
MetaGame mGame = MetaGame();
Game     game  = Game();

int main(int argc, char** argv) {
	// This causes a segfault in bash and does nothing in eclipse
	signal(SIGINT, sigint);
	// Define the first generator
	PointGenerator p(&game, 1, 1);

	/* Give a free generator to get started out.
	 * After all, manual collection is silly because it just
	 * would be as fast as the computer could trigger it
	 */
	p.Add();
	// Infinite loop. Turns out you can just skip the test in a for loop
	for (int i; i<10000; i++) {
		// Figure out deltaTime
		mGame.updateDelta();

		/*
		 * Prints how many points are generated (by generating them) and
		 * how many gamePoints there are every ten loops.
		 * TODO: Make dependent on time (Event driven?)
		 */
		if(i%10==0) {
			printf("New Points: %li, ", (long int) p.GeneratePoints( ));
			/*
			 * %f shows 0.000000, but %g shows really small numbers like 1.97626e-323
			 * Does this have to do with the way doubles are stored?
			 * TODO: Find a way to display globalPoints properly
			 * This only works for one pointGenerator
			 *  TODO fix (Use pointers?)
			 */
			printf("Total Points: %g\n", game.getPoints());

			/*
			 * Buy as many PointGenerators as it can and prints how many it bought
			 * (It's broken into two lines do to weird run order.)
			 */
			if(i%100==0) {
				p.BuyPercentMax(5);
				//printf("Bought %i PointGenerators for a total of ", p.BuyPartMax(0.1));
				//printf("%i\n", p.getAmount());
			}
		}
			if(flag) {
				// '\b\b' Removes the ^C it adds.
				printf("\b\bInterupt Detected, finishing.\n");
				break;
			}
		// TODO: Find out how to take an input while spamming the console with junk.
		// Save a string maybe?

		// Sleep for a tenth of a seconds
		std::this_thread::sleep_for(std::chrono::milliseconds (STEPTIME));
		//printf("%li\n", deltaTime); // TODO: Find out how to print durations
	}
	// Broken out of the loop, finish up.
	printf("Game Done\n");
	printf("There are %i PointGenerators.\n", p.getAmount());
	printf("There are %f gamePoints.\n", game.getPoints());

	if(flag) {
		printf("Control C pressed");
		return 1;
	}
	return 0;
}


