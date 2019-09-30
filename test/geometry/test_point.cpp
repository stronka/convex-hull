#include "ctestie.h"

#include "../../src/geometry/point.cpp"

TEST test_Point_CreateFromCoords_ReturnPoint(){
	Point2D p = Point2D(1., 2.);
	ASSERT(true, "Fail.");
}

TEST test_Point_GetX_ReturnsX(){
	Point2D p = Point2D(1., 2.);

	double const x = p.getX();
	ASSERT(x == 1., "Fail.");
}

TEST test_Point_GetY_ReturnsY(){
	Point2D p = Point2D(1., 2.);

	double const y = p.getY();
	ASSERT(y == 2., "Fail.");
}

TEST test_PointEquals_PointsTheSame_ReturnTrue(){
	Point2D p1 = Point2D(1., 2.);
	Point2D p2 = Point2D(1., 2.);

	ASSERT(p1 == p2, "Fail.");
}

TEST test_PointEquals_PointsNotTheSame_ReturnFalse(){
	Point2D p1 = Point2D(1., 2.);
	Point2D p2 = Point2D(2., 2.);

	ASSERT(!(p1 == p2), "Fail.");
}

TEST test_PointNotEquals_PointsNotTheSame_ReturnTrue(){
	Point2D p1 = Point2D(1., 2.);
	Point2D p2 = Point2D(2., 4.);

	ASSERT(p1 != p2, "Fail.");
}

TEST test_PointNotEquals_PointsTheSame_ReturnFalse(){
	Point2D p1 = Point2D(1., 2.);
	Point2D p2 = Point2D(1., 2.);

	ASSERT(!(p1 != p2), "Fail.");
}

TEST test_PointNotEquals_PointsXTheSame_ReturnTrue(){
	Point2D p1 = Point2D(1., 2.);
	Point2D p2 = Point2D(1., 3.);

	ASSERT((p1 != p2), "Fail.");
}

TEST test_PointVectorBuilder_Always_ReturnInstance(){
	PointVectorBuilder b = PointVectorBuilder();
	ASSERT(true, "Fail");
}

TEST test_PointVectorBuilderBuild_NoPoints_ReturnsEmptyList(){
	PointVectorBuilder b = PointVectorBuilder();
	std::vector<Point2D> points = b.build();

	ASSERT(points.empty(), "Fail.");
}

TEST test_PointVectorBuilderBuild_AddPoint_PointAdded(){
	PointVectorBuilder b = PointVectorBuilder();
	Point2D p = Point2D(1., 2.);
	b.addPoint(p);

	std::vector<Point2D> points = b.build();
	ASSERT(points[0] == p, "Fail.");
}

TEST test_PointVectorBuilderBuild_AddPointFewTimes_VectorSizeIsCorrect(){
	PointVectorBuilder b = PointVectorBuilder();
	Point2D p = Point2D(1., 2.);

	b.addPoint(p);
	b.addPoint(p);
	b.addPoint(p);
	b.addPoint(p);

	std::vector<Point2D> points = b.build();
	ASSERT(points.size() == 4, "Fail.");
}

TEST test_PointVectorBuilderReset_AddPointFewTimes_VectorSizeIsEmpty(){
	PointVectorBuilder b = PointVectorBuilder();
	Point2D p = Point2D(1., 2.);

	b.addPoint(p);
	b.addPoint(p);
	b.addPoint(p);
	b.addPoint(p);
	b.reset();

	std::vector<Point2D> points = b.build();
	ASSERT(points.empty(), "Fail.");
}


RUN(
		test_Point_CreateFromCoords_ReturnPoint,
		test_Point_GetX_ReturnsX,
		test_Point_GetY_ReturnsY,
		test_PointEquals_PointsTheSame_ReturnTrue,
		test_PointEquals_PointsNotTheSame_ReturnFalse,
		test_PointNotEquals_PointsNotTheSame_ReturnTrue,
		test_PointNotEquals_PointsTheSame_ReturnFalse,
		test_PointNotEquals_PointsXTheSame_ReturnTrue,

		test_PointVectorBuilder_Always_ReturnInstance,
		test_PointVectorBuilderBuild_NoPoints_ReturnsEmptyList,
		test_PointVectorBuilderBuild_AddPoint_PointAdded,
		test_PointVectorBuilderBuild_AddPointFewTimes_VectorSizeIsCorrect,
		test_PointVectorBuilderReset_AddPointFewTimes_VectorSizeIsEmpty
);
