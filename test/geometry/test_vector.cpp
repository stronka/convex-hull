#include <ctestie.h>
#include "../src/geometry/vector.cpp"

TEST test_PointVectorCalculatorCalculateTurnAngle_CaseColinearVectors_ReturnPi(){
	Point2D p1(0., 0.);
	Point2D p2(0., 1.);
	Point2D p3(0., 2.);

	Vector2D v1(p1, p2);
	Vector2D v2(p2, p3);

	double angle = v1.calculateTurnAngle(v2);

	ASSERT(angle == M_PI, "Fail. Got %2.4f, want %2.4f", angle, M_PI);
}

TEST test_PointVectorCalculatorCalculateTurnAngle_CaseVectorsAtRightAngle_ReturnPiTimesOneAndAHalf(){
	Point2D p1(0., 0.);
	Point2D p2(0., 1.);
	Point2D p3(1., 1.);

	Vector2D v1(p1, p2);
	Vector2D v2(p2, p3);

	double angle = v1.calculateTurnAngle(v2);

	ASSERT(angle == 1.5*M_PI, "Fail. Got %2.4f, want %2.4f", angle, 1.5*M_PI);
}

RUN(
		test_PointVectorCalculatorCalculateTurnAngle_CaseColinearVectors_ReturnPi,
		test_PointVectorCalculatorCalculateTurnAngle_CaseVectorsAtRightAngle_ReturnPiTimesOneAndAHalf
);
