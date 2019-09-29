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


RUN(
		test_Point_CreateFromCoords_ReturnPoint,
		test_Point_GetX_ReturnsX,
		test_Point_GetY_ReturnsY
);
