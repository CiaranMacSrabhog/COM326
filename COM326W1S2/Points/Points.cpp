/*
* Gambler.cpp
*
* Version information
* Author: Ciaran Mcstravick
* Date:25/09/2017
* Description: Solution to week 1 points challenge
*
* Copyright notice
*/

#include <iostream>
#include <random>

/*Function prototype - The function is below the main so the compiler won't know what the function is unless 
* you declare it in advance. There isn't a function body however
* see: http://www.learncpp.com/cpp-tutorial/17-forward-declarations/ */
int GenerateThrow();

int main(int argc, const char * argv[]) {

	int playerOneScore{ 12 }, playerTwoScore{ 12 };
	bool winner{ 0 };
	int score{ 0 }, numberThrows{ 0 };


	while (!winner) {
		score = 0;
		numberThrows++;
		score = GenerateThrow() + GenerateThrow() + GenerateThrow();
		std::cout << "\nPlayer One throws a: " << score << std::endl;
		if (score == 11) {
			playerOneScore++;
			playerTwoScore--;
		}
		numberThrows++;
		score = GenerateThrow() + GenerateThrow() + GenerateThrow();
		std::cout << "Player Two throws a: " << score << std::endl;
		if (score == 14) {
			playerOneScore--;
			playerTwoScore++;
		}
		std::cout << "Scores on the doors are: " << "\tPlayer one: " << playerOneScore << "\tPlayer two:" << playerTwoScore << std::endl;
		if (playerOneScore == 0 || playerTwoScore == 0) {
			winner = 1;
			std::cout << "\n\nThe total number of throws was: " << numberThrows << "\nWOW that's a lot!" << std::endl;
		}
		
		
	}


	return 0;
}

int GenerateThrow() {
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
	std::uniform_int_distribution<> dis(1, 6);
	
	//Generate the randome number passing in the mersenne_twister_engine generator
	return dis(gen);

}

