#include <ctestie.h>
#include "utils.hpp"

#include "algorithm/graham_scan.hpp"

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

RUN(
		test_BuildHull_EmptyVectorPassed_HullEmpty
);

