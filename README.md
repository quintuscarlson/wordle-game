# Wordle Game (C++)

## Overview
This project is a C++ implementation of a Wordle-style word guessing game. The program selects a random 5-letter word from a provided word list and gives the player six attempts to guess it. After each guess, the game outputs feedback showing which letters are correct, present in the word but misplaced, or not in the word at all.

## Features
- Randomly selects a secret word from `wordbank.txt`
- Accepts 5-letter uppercase or lowercase guesses
- Provides immediate feedback using:
  - `*` correct letter in correct position  
  - `!` correct letter in wrong position  
  - `-` letter not in the word
- Allows up to 6 total guesses
- Displays win/lose message at the end

## How It Works
The game flow:
1. Load all words from `wordbank.txt`
2. Randomly select one secret word and convert it to uppercase
3. Prompt the user for guesses until:
   - They guess correctly, OR  
   - They use all 6 attempts
4. After each guess, generate a feedback string indicating letter accuracy
5. Display final results

## File Requirements
Place a file named `wordbank.txt` in the same directory as the program.  
Each line should contain one valid 5-letter word.  
Example:  
apple  
crane  
spice  
table  

## How To Run
Compile and run using any C++ compiler:
g++ -std=c++11 wordle.cpp -o wordle
./wordle

## Example Output
Enter Your Guess: train
--*-!
Enter Your Guess: plane
PLANE
*----
...
You guessed the Word!

## Project Structure
- `wordle.cpp` — main program logic
- `wordbank.txt` — list of valid 5-letter words

## Skills Demonstrated
- File I/O  
- String processing  
- Control flow  
- Randomization  
- Input validation  
- Basic game logic  
- Use of vectors, loops, and helper functions

## Notes on Originality
This project was completed as an academic assignment and included a starter skeleton provided by the course instructor. I implemented the majority of the logic myself, but the starter structure was provided. This README does not claim exclusive authorship over the original skeleton, only over the work I added.
