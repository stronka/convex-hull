#include "ctestie.h"

#include "../src/point.cpp"

TEST test_Point_CreateFromCoords_ReturnPoint(){
	Point p = Point(1., 2.);
	ASSERT(true, "Fail.");
}

TEST test_Point_GetX_ReturnsX(){
	Point p = Point(1., 2.);

	double const x = p.GetX();
	ASSERT(x == 1., "Fail.");
}

TEST test_Point_GetY_ReturnsY(){
	Point p = Point(1., 2.);

	double const y = p.GetY();
	ASSERT(y == 2., "Fail.");
}

TEST test_PointEquals_PointsTheSame_ReturnTrue(){
	Point p1 = Point(1., 2.);
	Point p2 = Point(1., 2.);

	ASSERT(p1 == p2, "Fail.");
}

TEST test_PointEquals_PointsNotTheSame_ReturnFalse(){
	Point p1 = Point(1., 2.);
	Point p2 = Point(2., 2.);

	ASSERT(!(p1 == p2), "Fail.");
}

TEST test_PointVectorBuilder_Always_ReturnInstance(){
	PointVectorBuilder b = PointVectorBuilder();
	ASSERT(true, "Fail");
}

TEST test_PointVectorBuilderBuild_NoPoints_ReturnsEmptyList(){
	PointVectorBuilder b = PointVectorBuilder();
	std::vector<Point> points = b.build();

	ASSERT(points.empty(), "Fail.");
}

TEST test_PointVectorBuilderBuild_AddPoint_PointAdded(){
	PointVectorBuilder b = PointVectorBuilder();
	Point p = Point(1., 2.);
	b.addPoint(p);

	std::vector<Point> points = b.build();
	ASSERT(points[0] == p, "Fail.");
}

TEST test_PointVectorBuilderBuild_AddPointFewTimes_VectorSizeIsCorrect(){
	PointVectorBuilder b = PointVectorBuilder();
	Point p = Point(1., 2.);

	b.addPoint(p);
	b.addPoint(p);
	b.addPoint(p);
	b.addPoint(p);

	std::vector<Point> points = b.build();
	ASSERT(points.size() == 4, "Fail.");
}

RUN(
		test_Point_CreateFromCoords_ReturnPoint,
		test_Point_GetX_ReturnsX,
		test_Point_GetY_ReturnsY,
		test_PointEquals_PointsTheSame_ReturnTrue,
		test_PointEquals_PointsNotTheSame_ReturnFalse,

		test_PointVectorBuilder_Always_ReturnInstance,
		test_PointVectorBuilderBuild_NoPoints_ReturnsEmptyList,
		test_PointVectorBuilderBuild_AddPoint_PointAdded,
		test_PointVectorBuilderBuild_AddPointFewTimes_VectorSizeIsCorrect
);
