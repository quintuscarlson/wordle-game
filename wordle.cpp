//Quin Carlson 10/1/24
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cctype>
using namespace std;

// program constants
const string FILENAME = "wordbank.txt";
const int NUM_LETTERS = 5;
const int NUM_GUESSES = 6;

// helper function declarations
string getWord();
string getGuess();
string processRequest(string guess, string secret);

/* program takes user guesses compares them to a random word from the list
and outputs what letters and placements they got correct */
int main() {

//outputs instructions to play the game
cout << "\nWelcome to wordle! Try to guess a 5-letter word.\nWhen you guess, the program will report whether each letter:\n  * is in the correct spot\n  ! is in the word in the wrong spot\n  - is not in the word\nE.g., if the secret were PLANE a guess and response might be:\n  train\n  --*-!"<< endl;
string secret = getWord();

//keeps track of user guesses and wether or not they guessed the correct word
int tries = 1;
bool win = false;

while (tries <= 6 && win == false){
	string current = processRequest(getGuess(), secret);
	if (current == secret){
		win = true;
	}
	tries++;
}

//checks if the user won the game and outputs text accordingly
if (win == true){
	cout<<"\nYou guessed the Word!"<<endl;
}
else{
	cout<<"\nYou ran out of guesses before guessing the word: "<<secret<<endl;
}

return 0;
}

// helper function definitions
// picks a random word from the specified file
string getWord() {

// open the file
ifstream f(FILENAME);

// read words line-by-line into a vector
vector<string> allWords;
string word;
while (getline(f,word)) {
allWords.push_back(word);
}

// close the file
f.close();

// pick a random word from the vector and capitalize its letters
srand(time(nullptr));
word = allWords[rand()%allWords.size()];
for (int i=0; i<word.length(); i++) {
word[i] = toupper(word[i]);
}

return word;
}

//processes a user inputed guess
string getGuess(){
	string Guess;

	//makes sure guess is 5 letters long
	while (Guess.length() != NUM_LETTERS) {
 		cout<<"\nEnter Your Guess: ";
		cin>>Guess;
 			if (Guess.length() != NUM_LETTERS){
 				cout<<"Your guess must be "<<NUM_LETTERS<<" letters"<<endl;
 				}
			}

	//makes sure guess is stored in all uppercase letters
	for (int n = 0; n < Guess.length(); n++){
		char curL = toupper(Guess[n]);
		Guess[n] = curL;
	}


return Guess;
}


//processes a user guess and returns how correct it was
string processRequest(string guess, string secret){

string response;

//checks each character of the guess and determines the symbol to output
for (int j = 0; j < guess.length(); j++){
		char letter = guess[j];

		if (secret[j] == letter){
			response += "*";
		}
		else{

		bool inWord = false;

		for (int k = 0; k < guess.length(); k++){

		if (secret[k] == letter){
        inWord = true;
		}

	}
	if (inWord == true){
		response += "!";
	}
	else{
		response += "-";
	}}

}
	
	cout<<"\n"<<guess<<"\n"<<response<<endl;

	return guess;
}
