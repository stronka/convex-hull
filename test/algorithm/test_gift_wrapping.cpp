/*
 * test_gift_wrapping.c
 *
 *  Created on: 29 wrz 2019
 *      Author: Krzysztof
 */
#include "ctestie.h"
#include "../src/algorithm/gift_wrapping.cpp"


TEST test_FindHull_EmptyVectorPassed_ReturnsEmptyList(){
	std::vector <Point2D> points;
	std::vector <Point2D> hull = GiftWrappingAlgorithm::FindHull(points);

	ASSERT(hull.empty(), "Fail.");
}

TEST test_FindHull_OneElement_HullContainsOneElement(){
	Point2D p = Point2D(1., 2.);

	PointVectorBuilder b;
	b.AddPoint(p);

	std::vector <Point2D> hull = GiftWrappingAlgorithm::FindHull(b.build());

	ASSERT(hull.size() == 1, "Fail.");
}

TEST test_FindHull_TwoElements_HullContainsTwoElements(){
	Point2D p1 = Point2D(1., 2.);
	Point2D p2 = Point2D(2., 2.);

	PointVectorBuilder b;
	b.AddPoint(p1);
	b.AddPoint(p2);

	std::vector <Point2D> hull = GiftWrappingAlgorithm::FindHull(b.build());

	ASSERT(hull.size() == 2, "Fail.");
}

TEST test_FindHull_ThreeElements_HullContainsThreeElements(){
	Point2D p1 = Point2D(1., 2.);
	Point2D p2 = Point2D(2., 2.);
	Point2D p3 = Point2D(2., 3.);

	PointVectorBuilder b;
	b.AddPoint(p1);
	b.AddPoint(p2);
	b.AddPoint(p3);

	std::vector <Point2D> hull = GiftWrappingAlgorithm::FindHull(b.build());

	ASSERT(hull.size() == 3, "Fail.");
}

TEST test_FindHull_AllElementsOnAHull_HullContainsAllElements(){
	Point2D p1 = Point2D(0., 0.);
	Point2D p2 = Point2D(1., 0.);
	Point2D p3 = Point2D(2., 1.);
	Point2D p4 = Point2D(1., 2.);
	Point2D p5 = Point2D(0., 2.);

	PointVectorBuilder b;
	b.AddPoint(p1);
	b.AddPoint(p2);
	b.AddPoint(p3);
	b.AddPoint(p4);
	b.AddPoint(p5);


	std::vector <Point2D> points = b.build();
	std::vector <Point2D> hull = GiftWrappingAlgorithm::FindHull(points);

	ASSERT(hull.size() == 5, "Fail. Got %d, want %d", hull.size(), points.size());
}

TEST test_FindHull_OneElementInsideull_HullSizeIsLessThanPointsSizeByOne(){
	Point2D p1 = Point2D(0., 0.);
	Point2D p2 = Point2D(2., 0.);
	Point2D p3 = Point2D(2., 2.);
	Point2D p4 = Point2D(1., 1.);
	Point2D p5 = Point2D(0., 2.);

	PointVectorBuilder b;
	b.AddPoint(p1);
	b.AddPoint(p2);
	b.AddPoint(p3);
	b.AddPoint(p4);
	b.AddPoint(p5);

	std::vector <Point2D> points = b.build();
	std::vector <Point2D> hull = GiftWrappingAlgorithm::FindHull(points);

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
