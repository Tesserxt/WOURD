#pragma once
#include <string>


class WORD
{
public:
	std::string mask_word();
	void fetch_word();
	void take_input();
	bool verify_input();
	bool isGameOver();
private:
	bool gameOver = false;
	int score = 0;
	int attempts = 3;
    int seekby = 0; //to store address of file pointer to fetch next word.
	std::string fetched_word;
	std::string guessed_word;
};