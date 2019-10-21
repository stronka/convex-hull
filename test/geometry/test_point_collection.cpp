#include <ctestie.h>
#include <stdexcept>

#include "geometry/point_collection.hpp"

TEST test_PointVectorBuilder_Always_ReturnInstance(){
	PointVectorBuilder b;
	ASSERT(true, "Fail");
}

TEST test_PointVectorBuilderBuild_NoPoints_ReturnsEmptyList(){
	PointVectorBuilder b;
	std::vector<Point2D> points = b.build();

	ASSERT(points.empty(), "Fail.");
}

TEST test_PointVectorBuilderBuild_AddPoint_PointAdded(){
	PointVectorBuilder b;
	Point2D p(1., 2.);
	b.addPoint(p);

	std::vector<Point2D> points = b.build();
	ASSERT(points[0] == p, "Fail.");
}

TEST test_PointVectorBuilderBuild_AddPointFewTimes_VectorSizeIsCorrect(){
	PointVectorBuilder b;
	Point2D p(1., 2.);

	b.addPoint(p);
	b.addPoint(p);
	b.addPoint(p);
	b.addPoint(p);

	std::vector<Point2D> points = b.build();
	ASSERT(points.size() == 4, "Fail.");
}

TEST test_PointVectorBuilderReset_AddPointFewTimes_VectorSizeIsEmpty(){
	PointVectorBuilder b;
	Point2D p(1., 2.);

	b.addPoint(p);
	b.addPoint(p);
	b.addPoint(p);
	b.addPoint(p);
	b.reset();

	std::vector<Point2D> points = b.build();
	ASSERT(points.empty(), "Fail.");
}



RUN(
	test_PointVectorBuilder_Always_ReturnInstance,
	test_PointVectorBuilderBuild_NoPoints_ReturnsEmptyList,
	test_PointVectorBuilderBuild_AddPoint_PointAdded,
	test_PointVectorBuilderBuild_AddPointFewTimes_VectorSizeIsCorrect,
	test_PointVectorBuilderReset_AddPointFewTimes_VectorSizeIsEmpty
);
