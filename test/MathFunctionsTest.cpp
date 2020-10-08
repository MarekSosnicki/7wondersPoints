#include "doctest.h"
#include <MathFunctions.hpp>


TEST_CASE("add test") {
	// Given
	int a = 10;
	int b = 20;

	// When
	int res = add(a, b);

	// Then
	CHECK(res == 30);
}

TEST_CASE("add test") {
	CHECK(add(10, 20) == 30);
}

TEST_CASE("No points") {
	CHECK(calculatePoints(0) == 0);
}


TEST_CASE("Given only blue cards shall give blue cards value") {
	CHECK(calculatePoints(10) == 10);
}


TEST_CASE("Given only one point from wins shall return its sum") {
	CHECK(calculatePoints(0, {1}) == 1);
}


TEST_CASE("Given multiple points from win shall return its sum") {
	CHECK(calculatePoints(0, {1, 3}) == 4);
}


TEST_CASE("Given red and blue shall add them") {
	CHECK(calculatePoints(5, {1, 3}) == 9);
}

TEST_CASE("Given some number of looses shall subtract it") {
	CHECK(calculatePoints(0, {}, 5) == -5);
}


TEST_CASE("Given one green card shall add 1 point") {
	CHECK(calculatePoints(0, {}, 0, {'a'}) == 1);
}


TEST_CASE("Given two a's shall return its square") {
	CHECK(calculatePoints(0, {}, 0, {'a', 'a', 'a'}) == 9);
}

TEST_CASE("Given two a's and b values shall return squares of both separately") {
	CHECK(calculatePoints(0, {}, 0, {'a', 'a', 'b'}) == 5);
}


TEST_CASE("Should work for c") {
	CHECK(calculatePoints(0, {}, 0, {'c', 'c'}) == 4);
}

TEST_CASE("Should add bonus for sets when having one of each type") {
	CHECK(calculatePoints(0, {}, 0, {'a', 'b', 'c'}) == 10);
}

TEST_CASE("Should add bonus for sets when having two of each type") {
	CHECK(calculatePoints(0, {}, 0, {'a', 'b', 'c', 'a', 'b', 'c'}) == 26);
}

TEST_CASE("Should add bonus for sets when having one of each type and some extras") {
	CHECK(calculatePoints(0, {}, 0, {'a', 'b', 'c', 'a', 'a', 'b'}) == 21);
}

