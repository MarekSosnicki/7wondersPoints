#pragma once

#include<vector>

int add(int l, int r);


int calculatePoints(
	int pointsFromBlueCards,
	std::vector<int> pointsFromWins = {},
	int noOfLooses = 0,
	std::vector<char> greenCards = {}
);