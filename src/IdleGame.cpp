#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <thread>


#include "PointGenerator.h"

/*
 * Idle Game
 *
 *  Created on: Aug 14, 2017
 *      Author: EmergencyTemporalShift
 *
 *      The purpose of this is to make a simple iteration/idle game
 *      that can be used with some form of machine learning and do
 *      cool stuff.
 */

double globalPoints = 0; // This is how many points we have
std::chrono::high_resolution_clock Clock;

// This apparently assigns the right type to these variables
//std::chrono::milliseconds newTime;
auto newTime =  (std::chrono::high_resolution_clock::now());
auto oldTime = newTime;
auto deltaTime = newTime-oldTime;


int main(int argc, char** argv) {
	// Define the first generator
	PointGenerator p(16, 1, 0);

	/* Give a free generator to get started out.
	 * After all, manual collection is silly because it just
	 * would be as fast as the computer could trigger it
	 */
	p.Add();
	// Infinite loop. Turns out you can just skip the condition in a for loop
	for (int i; ;i++) {
		// Figure out deltaTime
		oldTime = newTime;
		newTime =  (std::chrono::high_resolution_clock::now());
		deltaTime = newTime - oldTime;

		/*
		 * Prints how many points are generated (by generating them) and
		 * how many globalPoints there are every ten loops.
		 * TODO: Make dependent on time (Event driven?)
		 */
		if(i%10==0) {
			printf("New Points: %f, ", p.GeneratePoints( ));
			printf("Total Points: %g\r\n", globalPoints);
		}

		/*
		 * Buys as many PointGenerators as it can and prints how many it bought
		 * (It's broken into two lines do to weird run order.)
		 */
		if(i%100==0) {
			printf("Bought %i PointGenerators for a total of ", p.BuyMax( ));
			printf("%i\r\n", p.getAmount());
		}

		//TODO: Find out how to take an input while spamming the console with junk.

		// Sleep for a tenth of a seconds
		std::this_thread::sleep_for(std::chrono::milliseconds (100));
		//printf("%li\n", deltaTime); // TODO: Find out how to print durations
	}
	return 0;
}


