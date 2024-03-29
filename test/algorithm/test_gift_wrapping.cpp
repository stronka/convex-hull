#include <ctestie.h>
#include "utils.hpp"

#include "algorithm/gift_wrapping.hpp"

void build_hull(const std::vector <Point2D> &points, PointCollectionBuilder &builder){
	GiftWrappingAlgorithm algorithm;
	algorithm.buildHull(points, builder);
}

TEST test_BuildHull_EmptyVectorPassed_HullEmpty(){
	MockPointCollectionBuilder mockBuilder;
	std::vector <Point2D> points;

	build_hull(points, mockBuilder);

	ASSERT(mockBuilder.points.empty(), "Fail.");
}

TEST test_BuildHull_OneElement_HullContainsOneElement(){
	MockPointCollectionBuilder mockBuilder;
	std::vector <Point2D> points = {Point2D(1., 2.)};

	build_hull(points, mockBuilder);

	ASSERT(mockBuilder.points.size() == 1, "Fail.");
}

TEST test_BuildHull_TwoElements_HullContainsTwoElements(){
	MockPointCollectionBuilder mockBuilder;
	std::vector <Point2D> points = {
		Point2D(1., 2.), Point2D(2., 2.)
	};

	build_hull(points, mockBuilder);

	ASSERT(mockBuilder.points.size() == 2, "Fail.");
}

TEST test_BuildHull_ThreeElements_HullContainsThreeElements(){
	MockPointCollectionBuilder mockBuilder;
	std::vector <Point2D> points = {
		Point2D(1., 2.),
		Point2D(2., 2.),
		Point2D(2., 3.)
	};

	build_hull(points, mockBuilder);

	ASSERT(mockBuilder.points.size() == 3, "Fail.");
}

TEST test_BuildHull_AllElementsOnAHull_HullContainsAllElements(){
	MockPointCollectionBuilder mockBuilder;
	std::vector <Point2D> points = {
		Point2D(0., 0.),
		Point2D(1., 0.),
		Point2D(2., 1.),
		Point2D(1., 2.),
		Point2D(0., 2.)
	};

	build_hull(points, mockBuilder);

	ASSERT(mockBuilder.points.size() == 5, "Fail. Got %d, want %d", mockBuilder.points.size(), points.size());
}

TEST test_BuildHull_OneElementInsideull_HullSizeIsLessThanPointsSizeByOne(){
	MockPointCollectionBuilder mockBuilder;
	std::vector <Point2D> points = {
		Point2D(0., 0.),
		Point2D(2., 0.),
		Point2D(2., 2.),
		Point2D(1., 1.),
		Point2D(0., 2.)
	};

	build_hull(points, mockBuilder);

	ASSERT(mockBuilder.points.size() == points.size() - 1, "Fail. Got %d, want %d", mockBuilder.points.size(), points.size() - 1);
}

TEST test_BuildHull_ManyElementsInsideull_HullSizeIsCorrect(){
	MockPointCollectionBuilder mockBuilder;
	std::vector <Point2D> points = {
		// hull points
		Point2D(0., 0.),
		Point2D(2., 0.),
		Point2D(2., 2.),
		Point2D(0., 2.),
		//remaining points
		Point2D(1., 1.),
		Point2D(1., 1.1),
		Point2D(1.1, 1.1),
		Point2D(1.1, 1.),
		Point2D(1.2, 1.),
		Point2D(1.2, 1.2)
	};

	build_hull(points, mockBuilder);

	ASSERT(mockBuilder.points.size() == 4, "Fail. Got %d, want %d", mockBuilder.points.size(), 4);
}

TEST test_BuildHull_FirstElementIsLeftmost_HullSizeIsCorrect(){
	MockPointCollectionBuilder mockBuilder;
	std::vector <Point2D> points = {
		// hull points
		Point2D(-1., 0.),
		Point2D(2., 0.),
		Point2D(2., 2.),
		Point2D(0., 2.),
		//remaining points
		Point2D(1., 1.)
	};

	build_hull(points, mockBuilder);

	ASSERT(mockBuilder.points.size() == 4, "Fail. Got %d, want %d", mockBuilder.points.size(), 4);
}

TEST test_FindHull_FirstElementIsLeftmost_HullIsCorrect(){
	MockPointCollectionBuilder mockBuilder;
	// hull points
	Point2D p1(-1., 0.);
	Point2D p2(2., 0.);
	Point2D p3(2., 2.);
	Point2D p4(0., 2.);
	//remaining points
	Point2D p5(1., 1.);

	std::vector <Point2D> points = {
		p1, p2, p3, p4, p5
	};

	std::vector <Point2D> expected = {
		p1, p4, p3, p2
	};

	build_hull(points, mockBuilder);

	ASSERT(mockBuilder.points == expected, "Fail.");
}

RUN(
		test_BuildHull_EmptyVectorPassed_HullEmpty,
		test_BuildHull_OneElement_HullContainsOneElement,
		test_BuildHull_TwoElements_HullContainsTwoElements,
		test_BuildHull_ThreeElements_HullContainsThreeElements,
		test_BuildHull_AllElementsOnAHull_HullContainsAllElements,
		test_BuildHull_OneElementInsideull_HullSizeIsLessThanPointsSizeByOne,
		test_BuildHull_ManyElementsInsideull_HullSizeIsCorrect,
		test_BuildHull_FirstElementIsLeftmost_HullSizeIsCorrect,
		test_FindHull_FirstElementIsLeftmost_HullIsCorrect
);
