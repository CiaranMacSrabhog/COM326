/*
* Trunsletur.cpp
*
* Version information
* Author: Ciaran Mcstravick
* Date: 
* Description: A quick translator program (Disclaimer: Basic rules and not comprehensive)
* Copyright notice
*/

#include <iostream>
#include <string>

using namespace std;

//Forward function prototuype declarations 
int DisplayMessage(); 
string GetSentence();
string TranslateToSwedish(string sentence);
string TranslateToEnglish(string sentence);

int main() {

	char reply{ ' ' };
	int option{0};
	string sentence = "";

	option = DisplayMessage();
	sentence = GetSentence();
	switch (option) {
	case 1:
		cout << "The Swedish Chef says: " << TranslateToSwedish(sentence) << endl;
		break;
	case 2:
		cout << "I think the Swedish Chef was saying: " << TranslateToEnglish(sentence) << endl;
		break;
	}
	return 0;
}

int DisplayMessage() {

	int option{ 0 };
	cout << "Hello and welcome to the Swedish Chef text translator. What would you like to do today?" << endl;
	cout << "\nApplication options" << endl;
	cout << "1. \tEnglish to Swedish Chef" << endl;
	cout << "2. \tSwedish Chef to English" << endl;
	cout << "\nPlease enter your option: ";
	cin >> option;
	cin.ignore(); //Clear the input buffer 
	cin.clear();

	return option;
}

string GetSentence() {
	string sentence;
	cout << "\nPlease enter your sentence for translation: ";
	getline(cin, sentence);
	return TranslateToSwedish(sentence);
}

string TranslateToSwedish(string sentence) {
	string translation;
	char character;
	int index;

	for (index = 0; index <= sentence.length() - 1; index++) {
		//Get the ASCII value
		int asciiValue = (int)sentence[index];
		character = sentence.at(index);
		if (asciiValue >= 65 && asciiValue <= 90) {
			//We have an A=Z 
			switch (character) {
			case 'A': translation.append("E");
				break;
			case 'F': translation.append("Ff");
				break;
			case 'I': translation.append("Ee");
				break;
			case 'O': translation.append("U");
				break;
			case 'U': translation.append("Oo");
				break;
			case 'V': translation.append("F");
				break;
			case 'W': translation.append("V");
				break;
			default: translation += character;
				break;	
			}
		}
		else if (asciiValue >= 97 && asciiValue <= 122) {
			switch (character) {
			case 'a': translation.append("e");
				break;
			case 'f': translation.append("ff");
				break;
			case 'i': translation.append("ee");
				break;
			case 'o': translation.append("u");
				break;
			case 'u': translation.append("oo");
				break;
			case 'v': translation.append("f");
				break;
			case 'w': translation.append("v");
				break;
			default: translation += character;
				break;
			}
		}
		else if (character == ' ' )
		{
			translation.append(" ");
		}
		else 
			translation += character;
	}
	return translation;
}

	/*
	abcdefghijklmnopqrstuvwxyz
    ebcdeffgheejklmnupqrstoofvxyz 
	*/
	//For each character in the sentence
	//examine the character and swap

string TranslateToEnglish(string sentence) {
	/*In the translation from English to Swedish we sometimes replaces a single character with 
	multiple characters. For example 'i' was replaced with 'ee'

	When we translate back we need to 'peek' ahead if we get an 'e' to see if there is another 'e'
	if so we replace the first character and increment the index. The for loop will then skip the
	second 'e' and not convert or replace it.

	We have to do this for several characters
	
	*/
	
	string translation;
	char character;
	int index;

	for (index = 0; index <= sentence.length() - 1; index++) {
		//Get the ASCII value
		int asciiValue = (int)sentence[index];
		character = sentence.at(index);
		if (asciiValue >= 65 && asciiValue <= 90) {
			//We have an A=Z 
			switch (character) {
			case 'E': 
				if(sentence[(__int64)index + 1] == 'e') {
					translation.append("I");
					index++;
				}else{ translation.append("A"); }
				break;
			case 'F': 
				if (sentence[(__int64)index + 1] == 'f') {
					translation.append("F");
					index++;
				}
				else { translation.append("V"); }
				break;
			case 'U': translation.append("O");
				break;
			case 'O': translation.append("U");
				if (sentence[(__int64)index + 1] == 'o') {
					index++;
				}
				break;
			case 'V': translation.append("W");
				break;
			default: translation += character;
				break;
			}
		}
		else if (asciiValue >= 97 && asciiValue <= 122) {
				//We have an A=Z 
			switch (character) {
			case 'e': 
				if(sentence[(__int64)index + 1] == 'e') {
					translation.append("i");
					index++;
				}else{ translation.append("a"); }
				break;
			case 'f': 
				if (sentence[(__int64)index + 1] == 'f') {
					translation.append("f");
					index++;
				}
				else { translation.append("v"); }
				break;
			case 'u': translation.append("o");
				break;
			case 'o': translation.append("u");
				if (sentence[(__int64)index + 1] == 'o') {
					index++;
				}
				break;
			case 'v': translation.append("w");
				break;
			default: translation += character;
				break;
			}
		}
		else if (character == ' ')
		{
			translation.append(" ");
		}
		else
			translation += character;
	}
	return translation;
}

