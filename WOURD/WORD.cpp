#include "WORD.h"
#include <random>
#include <fstream>
#include <iostream>
#include <string.h>

std::string WORD::mask_word()
{
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> dist(0, 4);
    int randN = dist(rng);

    std::string word = fetched_word;
    std::string masked_word = word;
    masked_word[randN] = '_';
    std::cout << "WORD:  " << masked_word << std::endl;
    return masked_word;
}

void WORD::fetch_word()
{
    std::ifstream wordsFile("../sgb-words.txt");
    if (!wordsFile.is_open())
    {
        std::cout << "error opening wordsFIle!\n";
    }
    wordsFile.seekg(seekby);
    std::string line;
    wordsFile >> line;
    wordsFile.close();
  
    seekby += 6;  //adding 6 to jump seek by 5 letters + 1st letter fetched word
    fetched_word = line;
}

void WORD::take_input()
{
    std::cout << "GUESS: ";
    std::string inWord;
    std::cin >> inWord;
    guessed_word = inWord;
}

bool WORD::verify_input() //const
{
    if(guessed_word == fetched_word)
    {
        std::cout << "Correct guess!\n" << std::endl;
        score += 1;
    }
    else
    {
        std::cout << "Incorrect guess!" << std::endl;
        attempts--;
        std::cout << "Attempts remaining: " << attempts << std::endl << '\n';
        seekby -= 6; //If a wrong word is guessed, adjust the seekby pointer to the most last fetched word.
    }
    return guessed_word == fetched_word ? true : false;
}

bool WORD::isGameOver()
{
    if (attempts == 0)
    {
        std::cout << "\nGame over! The word was: " << fetched_word << std::endl;
        std::cout << "Congratulation! You scored " << score << std::endl;
        gameOver = true;
    }
    return gameOver;
}
