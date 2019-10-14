#include <ctestie.h>

#include "../../src/geometry/point.cpp"

TEST test_Point_CreateFromCoords_ReturnPoint(){
	Point2D p(1., 2.);
	ASSERT(true, "Fail.");
}

TEST test_Point_GetX_ReturnsX(){
	Point2D p(1., 2.);

	double const x = p.getX();
	ASSERT(x == 1., "Fail.");
}

TEST test_Point_GetY_ReturnsY(){
	Point2D p(1., 2.);

	double const y = p.getY();
	ASSERT(y == 2., "Fail.");
}

TEST test_PointEquals_PointsTheSame_ReturnTrue(){
	Point2D p1(1., 2.);
	Point2D p2(1., 2.);

	ASSERT(p1 == p2, "Fail.");
}

TEST test_PointEquals_PointsNotTheSame_ReturnFalse(){
	Point2D p1(1., 2.);
	Point2D p2(2., 2.);

	ASSERT(!(p1 == p2), "Fail.");
}

TEST test_PointNotEquals_PointsNotTheSame_ReturnTrue(){
	Point2D p1(1., 2.);
	Point2D p2(2., 4.);

	ASSERT(p1 != p2, "Fail.");
}

TEST test_PointNotEquals_PointsTheSame_ReturnFalse(){
	Point2D p1(1., 2.);
	Point2D p2(1., 2.);

	ASSERT(!(p1 != p2), "Fail.");
}

TEST test_PointNotEquals_PointsXTheSame_ReturnTrue(){
	Point2D p1(1., 2.);
	Point2D p2(1., 3.);

	ASSERT((p1 != p2), "Fail.");
}


RUN(
		test_Point_CreateFromCoords_ReturnPoint,
		test_Point_GetX_ReturnsX,
		test_Point_GetY_ReturnsY,
		test_PointEquals_PointsTheSame_ReturnTrue,
		test_PointEquals_PointsNotTheSame_ReturnFalse,
		test_PointNotEquals_PointsNotTheSame_ReturnTrue,
		test_PointNotEquals_PointsTheSame_ReturnFalse,
		test_PointNotEquals_PointsXTheSame_ReturnTrue
);
