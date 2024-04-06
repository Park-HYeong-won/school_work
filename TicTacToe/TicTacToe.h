#pragma once
#include <iostream>

using namespace std;

class TicTacToe {
public:
	int full();
	int correct();
	int pick();
	void show();

	char tic_array[3][3];
};