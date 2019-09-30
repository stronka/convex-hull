#include "ctestie.h"

#include "../src/geometry/geometry.cpp"

TEST test_Point_CreateFromCoords_ReturnPoint(){
	Point2D p = Point2D(1., 2.);
	ASSERT(true, "Fail.");
}

TEST test_Point_GetX_ReturnsX(){
	Point2D p = Point2D(1., 2.);

	double const x = p.GetX();
	ASSERT(x == 1., "Fail.");
}

TEST test_Point_GetY_ReturnsY(){
	Point2D p = Point2D(1., 2.);

	double const y = p.GetY();
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
	b.AddPoint(p);

	std::vector<Point2D> points = b.build();
	ASSERT(points[0] == p, "Fail.");
}

TEST test_PointVectorBuilderBuild_AddPointFewTimes_VectorSizeIsCorrect(){
	PointVectorBuilder b = PointVectorBuilder();
	Point2D p = Point2D(1., 2.);

	b.AddPoint(p);
	b.AddPoint(p);
	b.AddPoint(p);
	b.AddPoint(p);

	std::vector<Point2D> points = b.build();
	ASSERT(points.size() == 4, "Fail.");
}

TEST test_PointVectorBuilderReset_AddPointFewTimes_VectorSizeIsEmpty(){
	PointVectorBuilder b = PointVectorBuilder();
	Point2D p = Point2D(1., 2.);

	b.AddPoint(p);
	b.AddPoint(p);
	b.AddPoint(p);
	b.AddPoint(p);
	b.Reset();

	std::vector<Point2D> points = b.build();
	ASSERT(points.empty(), "Fail.");
}

TEST test_PointVectorCalculatorCalculateTurnAngle_CaseColinearVectors_ReturnPi(){
	Point2D p1 = Point2D(0., 0.);
	Point2D p2 = Point2D(0., 1.);
	Point2D p3 = Point2D(0., 2.);

	Vector2D v1 = Vector2D(p1, p2);
	Vector2D v2 = Vector2D(p2, p3);

	double angle = v1.CalculateTurnAngle(v2);

	ASSERT(angle == M_PI, "Fail. Got %2.4f, want %2.4f", angle, M_PI);
}

TEST test_PointVectorCalculatorCalculateTurnAngle_CaseVectorsAtRightAngle_ReturnPiTimesOneAndAHalf(){
	Point2D p1 = Point2D(0., 0.);
	Point2D p2 = Point2D(0., 1.);
	Point2D p3 = Point2D(1., 1.);

	Vector2D v1 = Vector2D(p1, p2);
	Vector2D v2 = Vector2D(p2, p3);

	double angle = v1.CalculateTurnAngle(v2);

	ASSERT(angle == 1.5*M_PI, "Fail. Got %2.4f, want %2.4f", angle, 1.5*M_PI);
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
		test_PointVectorBuilderBuild_AddPointFewTimes_VectorSizeIsCorrect,
		test_PointVectorBuilderReset_AddPointFewTimes_VectorSizeIsEmpty,

		test_PointVectorCalculatorCalculateTurnAngle_CaseColinearVectors_ReturnPi,
		test_PointVectorCalculatorCalculateTurnAngle_CaseVectorsAtRightAngle_ReturnPiTimesOneAndAHalf
);
