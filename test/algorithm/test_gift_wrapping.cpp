/*
 * test_gift_wrapping.c
 *
 *  Created on: 29 wrz 2019
 *      Author: Krzysztof
 */
#include "ctestie.h"
#include "../src/algorithm/gift_wrapping.cpp"


TEST test_FindHull_EmptyVectorPassed_ReturnsEmptyList(){
	std::vector <Point> points;
	std::vector <Point> hull = GiftWrappingAlgorithm::FindHull(points);

	ASSERT(hull.empty(), "Fail.");
}

TEST test_FindHull_OneElement_HullContainsOneElement(){
	Point p = Point(1., 2.);

	PointVectorBuilder b;
	b.addPoint(p);

	std::vector <Point> hull = GiftWrappingAlgorithm::FindHull(b.build());

	ASSERT(hull.size() == 1, "Fail.");
}

TEST test_FindHull_TwoElements_HullContainsTwoElements(){
	Point p1 = Point(1., 2.);
	Point p2 = Point(2., 2.);

	PointVectorBuilder b;
	b.addPoint(p1);
	b.addPoint(p2);

	std::vector <Point> hull = GiftWrappingAlgorithm::FindHull(b.build());

	ASSERT(hull.size() == 2, "Fail.");
}

TEST test_FindHull_ThreeElements_HullContainsThreeElements(){
	Point p1 = Point(1., 2.);
	Point p2 = Point(2., 2.);
	Point p3 = Point(2., 3.);

	PointVectorBuilder b;
	b.addPoint(p1);
	b.addPoint(p2);
	b.addPoint(p3);

	std::vector <Point> hull = GiftWrappingAlgorithm::FindHull(b.build());

	ASSERT(hull.size() == 3, "Fail.");
}

TEST test_FindHull_AllElementsOnAHull_HullContainsAllElements(){
	Point p1 = Point(0., 0.);
	Point p2 = Point(1., 0.);
	Point p3 = Point(2., 1.);
	Point p4 = Point(1., 2.);
	Point p5 = Point(0., 2.);

	PointVectorBuilder b;
	b.addPoint(p1);
	b.addPoint(p2);
	b.addPoint(p3);
	b.addPoint(p4);
	b.addPoint(p5);

	std::vector <Point> hull = GiftWrappingAlgorithm::FindHull(b.build());

	ASSERT(hull.size() == 5, "Fail.");
}

TEST test_FindHull_OneElementInsideull_HullSizeIsLessThanPointsSizeByOne(){
	Point p1 = Point(0., 0.);
	Point p2 = Point(2., 0.);
	Point p3 = Point(2., 2.);
	Point p4 = Point(1., 1.);
	Point p5 = Point(0., 2.);

	PointVectorBuilder b;
	b.addPoint(p1);
	b.addPoint(p2);
	b.addPoint(p3);
	b.addPoint(p4);
	b.addPoint(p5);

	std::vector <Point> points = b.build();
	std::vector <Point> hull = GiftWrappingAlgorithm::FindHull(points);

	ASSERT(hull.size() == points.size() - 1, "Fail. Got %d, want %d", hull.size(), points.size() - 1);
}

RUN(
		test_FindHull_EmptyVectorPassed_ReturnsEmptyList,
		test_FindHull_OneElement_HullContainsOneElement,
		test_FindHull_TwoElements_HullContainsTwoElements,
		test_FindHull_ThreeElements_HullContainsThreeElements,
		test_FindHull_AllElementsOnAHull_HullContainsAllElements,
		test_FindHull_OneElementInsideull_HullSizeIsLessThanPointsSizeByOne
);
