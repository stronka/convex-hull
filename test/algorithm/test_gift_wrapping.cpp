/*
 * test_gift_wrapping.c
 *
 *  Created on: 29 wrz 2019
 *      Author: Krzysztof
 */
#include "ctestie.h"
#include "../src/algorithm/gift_wrapping.cpp"

TEST test_CreateAlgorithm_Always_ReturnsAlgorithm(){
	GiftWrappingAlgorithm algorithm = GiftWrappingAlgorithm();
	ASSERT(true, "Fail.");
}

TEST test_FindHull_EmptyListPassed_ReturnsEmptyList(){
	GiftWrappingAlgorithm algorithm = GiftWrappingAlgorithm();

	std::list <Point> points;
	std::list <Point> hull = algorithm.FindHull(points);

	ASSERT(hull.empty(), "Fail.");
}

RUN(
		test_CreateAlgorithm_Always_ReturnsAlgorithm,
		test_FindHull_EmptyListPassed_ReturnsEmptyList
);
