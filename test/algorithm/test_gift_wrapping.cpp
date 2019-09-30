#include "ctestie.h"
#include "../src/algorithm/gift_wrapping.cpp"


TEST test_FindHull_EmptyVectorPassed_ReturnsEmptyList(){
	std::vector <Point2D> points;
	std::vector <Point2D> hull = GiftWrappingAlgorithm::findHull(points);

	ASSERT(hull.empty(), "Fail.");
}

TEST test_FindHull_OneElement_HullContainsOneElement(){
	Point2D p = Point2D(1., 2.);

	PointVectorBuilder b;
	b.addPoint(p);

	std::vector <Point2D> hull = GiftWrappingAlgorithm::findHull(b.build());

	ASSERT(hull.size() == 1, "Fail.");
}

TEST test_FindHull_TwoElements_HullContainsTwoElements(){
	Point2D p1 = Point2D(1., 2.);
	Point2D p2 = Point2D(2., 2.);

	PointVectorBuilder b;
	b.addPoint(p1);
	b.addPoint(p2);

	std::vector <Point2D> hull = GiftWrappingAlgorithm::findHull(b.build());

	ASSERT(hull.size() == 2, "Fail.");
}

TEST test_FindHull_ThreeElements_HullContainsThreeElements(){
	Point2D p1 = Point2D(1., 2.);
	Point2D p2 = Point2D(2., 2.);
	Point2D p3 = Point2D(2., 3.);

	PointVectorBuilder b;
	b.addPoint(p1);
	b.addPoint(p2);
	b.addPoint(p3);

	std::vector <Point2D> hull = GiftWrappingAlgorithm::findHull(b.build());

	ASSERT(hull.size() == 3, "Fail.");
}

TEST test_FindHull_AllElementsOnAHull_HullContainsAllElements(){
	Point2D p1 = Point2D(0., 0.);
	Point2D p2 = Point2D(1., 0.);
	Point2D p3 = Point2D(2., 1.);
	Point2D p4 = Point2D(1., 2.);
	Point2D p5 = Point2D(0., 2.);

	PointVectorBuilder b;
	b.addPoint(p1);
	b.addPoint(p2);
	b.addPoint(p3);
	b.addPoint(p4);
	b.addPoint(p5);


	std::vector <Point2D> points = b.build();
	std::vector <Point2D> hull = GiftWrappingAlgorithm::findHull(points);

	ASSERT(hull.size() == 5, "Fail. Got %d, want %d", hull.size(), points.size());
}

TEST test_FindHull_OneElementInsideull_HullSizeIsLessThanPointsSizeByOne(){
	Point2D p1 = Point2D(0., 0.);
	Point2D p2 = Point2D(2., 0.);
	Point2D p3 = Point2D(2., 2.);
	Point2D p4 = Point2D(1., 1.);
	Point2D p5 = Point2D(0., 2.);

	PointVectorBuilder b;
	b.addPoint(p1);
	b.addPoint(p2);
	b.addPoint(p3);
	b.addPoint(p4);
	b.addPoint(p5);

	std::vector <Point2D> points = b.build();
	std::vector <Point2D> hull = GiftWrappingAlgorithm::findHull(points);

	ASSERT(hull.size() == points.size() - 1, "Fail. Got %d, want %d", hull.size(), points.size() - 1);
}

TEST test_FindHull_ManyElementsInsideull_HullSizeIsCorrect(){
	// hull points
	Point2D p1 = Point2D(0., 0.);
	Point2D p2 = Point2D(2., 0.);
	Point2D p3 = Point2D(2., 2.);
	Point2D p4 = Point2D(0., 2.);
	//remaining points
	Point2D p5 = Point2D(1., 1.);
	Point2D p6 = Point2D(1., 1.1);
	Point2D p7 = Point2D(1.1, 1.1);
	Point2D p8 = Point2D(1.1, 1.);
	Point2D p9 = Point2D(1.2, 1.);
	Point2D p10 = Point2D(1.2, 1.2);

	PointVectorBuilder b;
	b.addPoint(p1);
	b.addPoint(p2);
	b.addPoint(p3);
	b.addPoint(p4);
	b.addPoint(p5);
	b.addPoint(p6);
	b.addPoint(p7);
	b.addPoint(p8);
	b.addPoint(p9);
	b.addPoint(p10);

	std::vector <Point2D> points = b.build();
	std::vector <Point2D> hull = GiftWrappingAlgorithm::findHull(points);

	ASSERT(hull.size() == 4, "Fail. Got %d, want %d", hull.size(), 4);
}

TEST test_FindHull_FirstElementIsLeftmost_HullSizeIsCorrect(){
	// hull points
	Point2D p1 = Point2D(-1., 0.);
	Point2D p2 = Point2D(2., 0.);
	Point2D p3 = Point2D(2., 2.);
	Point2D p4 = Point2D(0., 2.);
	//remaining points
	Point2D p5 = Point2D(1., 1.);

	PointVectorBuilder b;
	b.addPoint(p1);
	b.addPoint(p2);
	b.addPoint(p3);
	b.addPoint(p4);
	b.addPoint(p5);

	std::vector <Point2D> points = b.build();
	std::vector <Point2D> hull = GiftWrappingAlgorithm::findHull(points);

	ASSERT(hull.size() == 4, "Fail. Got %d, want %d", hull.size(), 4);
}

TEST test_FindHull_FirstElementIsLeftmost_HullIsCorrect(){
	// hull points
	Point2D p1 = Point2D(-1., 0.);
	Point2D p2 = Point2D(2., 0.);
	Point2D p3 = Point2D(2., 2.);
	Point2D p4 = Point2D(0., 2.);
	//remaining points
	Point2D p5 = Point2D(1., 1.);

	PointVectorBuilder b;

	b.addPoint(p1);
	b.addPoint(p2);
	b.addPoint(p3);
	b.addPoint(p4);
	b.addPoint(p5);

	std::vector <Point2D> points = b.build();

	b.reset();
	b.addPoint(p1);
	b.addPoint(p2);
	b.addPoint(p3);
	b.addPoint(p4);

	std::vector <Point2D> expected = b.build();
	std::vector <Point2D> hull = GiftWrappingAlgorithm::findHull(points);

	ASSERT(hull == expected, "Fail.");
}

RUN(
		test_FindHull_EmptyVectorPassed_ReturnsEmptyList,
		test_FindHull_OneElement_HullContainsOneElement,
		test_FindHull_TwoElements_HullContainsTwoElements,
		test_FindHull_ThreeElements_HullContainsThreeElements,
		test_FindHull_AllElementsOnAHull_HullContainsAllElements,
		test_FindHull_OneElementInsideull_HullSizeIsLessThanPointsSizeByOne,
		test_FindHull_ManyElementsInsideull_HullSizeIsCorrect,
		test_FindHull_FirstElementIsLeftmost_HullSizeIsCorrect,
		test_FindHull_FirstElementIsLeftmost_HullIsCorrect
);
