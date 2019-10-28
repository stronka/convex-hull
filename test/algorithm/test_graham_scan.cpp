#include <ctestie.h>
#include "utils.hpp"

#include "algorithm/graham_scan.hpp"

TEST test_PointSorterSortPoints_UnorderedPoints_SortByPolarAngle(){
	PointPolarAngleSorter s;

	Point2D p1(0., 0.);
	Point2D p2(1., 0.);
	Point2D p3(0., 1.);
	Point2D p4(2., 2.);

	std::vector <Point2D> points = {p1, p2, p3, p4};
	std::vector <Point2D> expected = {p1, p2, p4, p3};

	s.setOrigin(p1);
	s.sort(points);

	ASSERT(points == expected, "Fail.");
}

TEST test_PointSorterSortPoints_CollinearPoints_DropCollinear(){
	PointPolarAngleSorter s;

	Point2D p1(0., 0.);
	Point2D p2(1., 0.);
	Point2D p3(0., 1.);
	Point2D p4(2., 2.);
	Point2D p5(1., 1.);
	Point2D p6(.5, .5);

	std::vector <Point2D> points = {p1, p2, p3, p4, p5, p6};
	std::vector <Point2D> expected = {p1, p2, p4, p3};

	s.setOrigin(p1);
	s.sort(points);

	ASSERT(points == expected, "Fail.");
}

TEST test_FindLeftmostLowestYPoint_UnorderedPoints_ReturnCorrectPointer(){

	Point2D p1(0., 0.);
	Point2D p2(1., 0.);
	Point2D p3(0., -1.);
	Point2D p4(2., 2.);

	std::vector <Point2D> points = {p1, p2, p3, p4};

	Point2D *actual = find_leftmost_lowest_y_point(points);

	ASSERT(actual->getDistance(p3) < 1e-3, "Fail.");
}

TEST test_FindLeftmostLowestYPoint_UnorderedPointsManyOnBottom_ReturnCorrectPointer(){

	Point2D p1(0., 0.);
	Point2D p2(1., 0.);
	Point2D p3(-1., -1.);
	Point2D p4(0., -1.);
	Point2D p5(0.1, -1.);
	Point2D p6(0.2, -1.);
	Point2D p7(-1.3, -1.);
	Point2D p8(2., 2.);

	std::vector <Point2D> points = {p1, p2, p3, p4, p5, p6, p7, p8};

	Point2D *actual = find_leftmost_lowest_y_point(points);

	ASSERT(actual->getDistance(p7) < 1e-3, "Fail.");
}

TEST test_ccw_CounterClockwiseTurn_ReturnNegativeOne(){
	Point2D p1(0., 0.);
	Point2D p2(1., 0.);
	Point2D p3(1., 1.);

	int actual = ccw(p1, p2, p3);

	ASSERT(actual == -1, "Fail.");
}

TEST test_ccw_NoTurn_ReturnZero(){
	Point2D p1(0., 0.);
	Point2D p2(1., 0.);
	Point2D p3(2., 0.);

	int actual = ccw(p1, p2, p3);

	ASSERT(actual == 0, "Fail.");
}

TEST test_ccw_ClockwiseTurn_ReturnOne(){
	Point2D p1(0., 0.);
	Point2D p2(1., 0.);
	Point2D p3(1., -1.);

	int actual = ccw(p1, p2,p3);

	ASSERT(actual == 1, "Fail.");
}

void build_hull(const std::vector <Point2D> &points, PointCollectionBuilder &builder){
	GrahamScanAlgorithm algorithm;
	algorithm.buildHull(points, builder);
}


TEST test_BuildHull_EmptyVectorPassed_HullEmpty(){
	MockPointCollectionBuilder mockBuilder;
	std::vector <Point2D> points;

	build_hull(points, mockBuilder);

	ASSERT(mockBuilder.points.empty(), "Fail.");
}

TEST test_BuildHull_OnePointVectorPassed_HullSizeIsOne(){
	MockPointCollectionBuilder mockBuilder;
	std::vector <Point2D> points = {
		Point2D(1., 1)
	};

	build_hull(points, mockBuilder);

	ASSERT(mockBuilder.points.size() == 1, "Fail.");
}

TEST test_BuildHull_TwoPointVectorPassed_HullSizeIsTwo(){
	MockPointCollectionBuilder mockBuilder;
	std::vector <Point2D> points = {
		Point2D(1., 1),
		Point2D(2., 1)
	};

	build_hull(points, mockBuilder);

	ASSERT(mockBuilder.points.size() == 2, "Fail.");
}

TEST test_BuildHull_ThreePointVectorPassed_HullSizeIsThree(){
	MockPointCollectionBuilder mockBuilder;
	std::vector <Point2D> points = {
		Point2D(1., 1),
		Point2D(2., 1),
		Point2D(2., 2)
	};



	build_hull(points, mockBuilder);

	ASSERT(mockBuilder.points.size() == 3, "Fail.");
}

TEST test_BuildHull_FourPointVectorPassed_HullSizeIsFour(){
	MockPointCollectionBuilder mockBuilder;
	std::vector <Point2D> points = {
		Point2D(1., 1),
		Point2D(2., 1),
		Point2D(2., 2.),
		Point2D(1., 2.)
	};



	build_hull(points, mockBuilder);

	ASSERT(mockBuilder.points.size() == 4, "Fail.");
}

TEST test_BuildHull_PointInsideHullPassed_HullDoesNotContainPoint(){
	MockPointCollectionBuilder mockBuilder;

	Point2D p1(1., 1);
	Point2D p2(2., 1);
	Point2D p3(2., 2.);
	Point2D p4(1., 2.);

	Point2D p5(1.5, 1.5);

	std::vector <Point2D> points = {p1, p2, p3, p4, p5};
	std::vector <Point2D> expected = {p1, p2, p3, p4};

	build_hull(points, mockBuilder);


	ASSERT(mockBuilder.points == expected, "Fail.");
}

TEST test_BuildHull_GeneralHullExample_HullIsCorrect(){
	MockPointCollectionBuilder mockBuilder;

	Point2D p1(-1., -1.);
	Point2D p2(1., -1.);
	Point2D p3(1., 1.);
	Point2D p4(0., 1.);
	Point2D p5(-1., 1.);

	Point2D p6(0., 0.);
	Point2D p7(0.1, 0.);
	Point2D p8(0.1, 0.1);
	Point2D p9(0.1, -0.1);
	Point2D p10(0.5, -0.1);
	Point2D p11(-0.7, -0.1);
	Point2D p12(-0.7, .9);

	std::vector <Point2D> points = {p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12};
	std::vector <Point2D> expected = {p1, p2, p3, p4, p5};

	build_hull(points, mockBuilder);

	ASSERT(mockBuilder.points == expected, "Fail.");
}


RUN(
		test_PointSorterSortPoints_UnorderedPoints_SortByPolarAngle,
		test_PointSorterSortPoints_CollinearPoints_DropCollinear,
		test_FindLeftmostLowestYPoint_UnorderedPoints_ReturnCorrectPointer,
		test_FindLeftmostLowestYPoint_UnorderedPointsManyOnBottom_ReturnCorrectPointer,
		test_ccw_CounterClockwiseTurn_ReturnNegativeOne,
		test_ccw_NoTurn_ReturnZero,
		test_ccw_ClockwiseTurn_ReturnOne,
		test_BuildHull_EmptyVectorPassed_HullEmpty,
		test_BuildHull_OnePointVectorPassed_HullSizeIsOne,
		test_BuildHull_TwoPointVectorPassed_HullSizeIsTwo,
		test_BuildHull_ThreePointVectorPassed_HullSizeIsThree,
		test_BuildHull_FourPointVectorPassed_HullSizeIsFour,
		test_BuildHull_PointInsideHullPassed_HullDoesNotContainPoint,
		test_BuildHull_GeneralHullExample_HullIsCorrect
);

