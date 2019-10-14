/*
* Gambler.cpp
*
* Version information
* Author: Ciaran Mcstravick
* Date:25/09/2017
* Description: Solution to week 1 Gambler's Ruin challenge
*
* Copyright notice
*/

#include <iostream>
#include <random>

/*Function prototype - The function is below the main so the compiler won't know what the function is unless
* you declare it in advance. There isn't a function body however
* see: http://www.learncpp.com/cpp-tutorial/17-forward-declarations/ */
float GenerateRandomNumber();

int main(int argc, const char * argv[]) {

	//int stake{ 0 };
	int goal{ 0 };
	int num_games{ 0 };
	int cash{ 0 };
	int stake{ 0 };
	int bets{ 0 };
	int wins{ 0 };

	char playAgain{ 'y' };

	while(playAgain=='y'){
		num_games++;
		std::cout << "Please enter the players initial cash: ";
		std::cin >> cash;

		std::cout << "\nPlease enter the goal: ";
		std::cin >> goal;

		std::cout << "\nGame: "<< num_games << std::endl;

		while (cash > 0 && cash < goal) {
			bets++;

			//allow gamble to enter stakes for every round
			std::cout << "Please enter your bet for this round: ";
			std::cin >> stake;	

			//set default if not stake is not an integer > 1
			if (int(stake) < 0) {
				stake = 1;
			}

			if (GenerateRandomNumber() < 0.5)
				cash += stake;
			else
				cash -= stake;

			std::cout << " cash: " << cash << std::endl;
		}
		if (cash == goal)
			wins++;

		std::cout << "\nDo you want to play again? Y/N: "; 
		std::cin >> playAgain;
		std::cout << std::endl;
	} 

	std::cout << "\nThe total number of bet(s): " << bets << " for " << num_games << " game(s)"; 
	std::cout << "\nTotal wins: " << wins;
	std::cout << "\nPercentage of " << (100 * wins / num_games) << " % wins" << std::endl;
	

	return 0;
}


float GenerateRandomNumber() {

	/* Some of you asked how this works. You really need to read the documentation for the deep dive explanation.
	* If you want to know what is happening here I have added some comments
	* This will become clearer when we talk about classes and objects in week 3
	*/


	//Taken from: http://en.cppreference.com/w/cpp/numeric/random/uniform_real_distribution
	//Define an instance (aka an object) of the random_device Class and call the object rd
	std::random_device rd; //The random number device. Will be used to obtain a seed for the random number engine
						   //Call the constructor of the object rd and use the RD engine to create a mersenne_twister_engine
						   //The mersenne_twister_engine is based on the Mersenne twister algorithm
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
							//Create a new distribution object with min and max values. So the range the random number should fall between
	std::uniform_real_distribution<> dis(0, 1);

	//Generate the randome number passing in the mersenne_twister_engine generator
	float outcome = dis(gen);
	std::cout << "*** Outcome " << outcome;

	return outcome;
}


