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
	std::vector <Point2D> expected = {p1, p3, p4, p2};

	s.setOrigin(&p1);
	s.sort(points);

	ASSERT(points == expected, "Fail.");
}

TEST test_FindLowestYPoint_UnorderedPoints_ReturnCorrectPointer(){

	Point2D p1(0., 0.);
	Point2D p2(1., 0.);
	Point2D p3(0., -1.);
	Point2D p4(2., 2.);

	std::vector <Point2D> points = {p1, p2, p3, p4};

	Point2D *actual = find_lowest_y_point(points);

	ASSERT(actual->getDistance(p3) < 1e-3, "Fail.");
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


RUN(
		test_PointSorterSortPoints_UnorderedPoints_SortByPolarAngle,
		test_FindLowestYPoint_UnorderedPoints_ReturnCorrectPointer,
		test_BuildHull_EmptyVectorPassed_HullEmpty,
		test_BuildHull_OnePointVectorPassed_HullSizeIsOne,
		test_BuildHull_TwoPointVectorPassed_HullSizeIsTwo,
		test_BuildHull_ThreePointVectorPassed_HullSizeIsThree,
//		test_BuildHull_FourPointVectorPassed_HullSizeIsFour,
		test_BuildHull_PointInsideHullPassed_HullDoesNotContainPoint
);

