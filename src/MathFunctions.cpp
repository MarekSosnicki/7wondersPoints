#include "MathFunctions.hpp"

int add(int l, int r){
	return l + r;
}


int getPointsFromWins(std::vector<int> pointsFromWins) {
	int sum = 0;
	for (int points: pointsFromWins) {
		sum += points;
	}
	return sum;
}

int calculate(std::vector<char> greenCards, char wanted) {
	int count = 0;
	for (int card : greenCards) {
		if (card == wanted)
		{
			count = count +1;
		}
	}
	return count;
}

int getPointsFromGreenCards(std::vector<char> greenCards) {
	int aCount = calculate(greenCards, 'a');
	int bCount = calculate(greenCards, 'b');
	int cCount = calculate(greenCards, 'c');

	int bonusCount = aCount;
	if (bCount < bonusCount ) {
		bonusCount = bCount;
	} 
	if (cCount < bonusCount) {
		bonusCount = cCount;
	}

	if (aCount == bCount) {
		if (bCount == cCount)
		{
			bonusCount = aCount;
		}
	}
	return  aCount*aCount 
			+ bCount * bCount
			+ cCount * cCount
			+ 7 * bonusCount;
}

int calculatePoints(
	int pointsFromBlueCards,
	std::vector<int> pointsFromWins,
	int noOfLooses,
	std::vector<char> greenCards) 
{
	return pointsFromBlueCards
		   + getPointsFromWins(pointsFromWins) 
		   - noOfLooses
		   + getPointsFromGreenCards(greenCards);
}