#include "ctestie.h"
#include "../src/algorithm/gift_wrapping.cpp"

class MockPointCollectionBuilder : public PointCollectionBuilder {
public:
	std::vector <Point2D> points;

	void addPoint(const Point2D &p) { points.push_back(p); };
};


TEST test_BuildHull_EmptyVectorPassed_HullEmpty(){
	MockPointCollectionBuilder mockBuilder;

	std::vector <Point2D> points;
	GiftWrappingAlgorithm::buildHull(points, mockBuilder);

	ASSERT(mockBuilder.points.empty(), "Fail.");
}

TEST test_BuildHull_OneElement_HullContainsOneElement(){
	MockPointCollectionBuilder mockBuilder;

	Point2D p(1., 2.);
	PointVectorBuilder b;
	b.addPoint(p);

	GiftWrappingAlgorithm::buildHull(b.build(), mockBuilder);

	ASSERT(mockBuilder.points.size() == 1, "Fail.");
}

TEST test_BuildHull_TwoElements_HullContainsTwoElements(){
	MockPointCollectionBuilder mockBuilder;

	Point2D p1(1., 2.);
	Point2D p2(2., 2.);
	PointVectorBuilder b;
	b.addPoint(p1);
	b.addPoint(p2);

	GiftWrappingAlgorithm::buildHull(b.build(), mockBuilder);

	ASSERT(mockBuilder.points.size() == 2, "Fail.");
}

TEST test_BuildHull_ThreeElements_HullContainsThreeElements(){
	MockPointCollectionBuilder mockBuilder;

	Point2D p1(1., 2.);
	Point2D p2(2., 2.);
	Point2D p3(2., 3.);

	PointVectorBuilder b;
	b.addPoint(p1);
	b.addPoint(p2);
	b.addPoint(p3);

	GiftWrappingAlgorithm::buildHull(b.build(), mockBuilder);

	ASSERT(mockBuilder.points.size() == 3, "Fail.");
}

TEST test_BuildHull_AllElementsOnAHull_HullContainsAllElements(){
	MockPointCollectionBuilder mockBuilder;

	Point2D p1(0., 0.);
	Point2D p2(1., 0.);
	Point2D p3(2., 1.);
	Point2D p4(1., 2.);
	Point2D p5(0., 2.);
	PointVectorBuilder b;
	b.addPoint(p1);
	b.addPoint(p2);
	b.addPoint(p3);
	b.addPoint(p4);
	b.addPoint(p5);


	std::vector <Point2D> points = b.build();
	GiftWrappingAlgorithm::buildHull(points, mockBuilder);

	ASSERT(mockBuilder.points.size() == 5, "Fail. Got %d, want %d", mockBuilder.points.size(), points.size());
}

TEST test_BuildHull_OneElementInsideull_HullSizeIsLessThanPointsSizeByOne(){
	MockPointCollectionBuilder mockBuilder;

	Point2D p1(0., 0.);
	Point2D p2(2., 0.);
	Point2D p3(2., 2.);
	Point2D p4(1., 1.);
	Point2D p5(0., 2.);

	PointVectorBuilder b;
	b.addPoint(p1);
	b.addPoint(p2);
	b.addPoint(p3);
	b.addPoint(p4);
	b.addPoint(p5);

	std::vector <Point2D> points = b.build();
	GiftWrappingAlgorithm::buildHull(points, mockBuilder);

	ASSERT(mockBuilder.points.size() == points.size() - 1, "Fail. Got %d, want %d", mockBuilder.points.size(), points.size() - 1);
}

TEST test_BuildHull_ManyElementsInsideull_HullSizeIsCorrect(){
	MockPointCollectionBuilder mockBuilder;

	// hull points
	Point2D p1(0., 0.);
	Point2D p2(2., 0.);
	Point2D p3(2., 2.);
	Point2D p4(0., 2.);
	//remaining points
	Point2D p5(1., 1.);
	Point2D p6(1., 1.1);
	Point2D p7(1.1, 1.1);
	Point2D p8(1.1, 1.);
	Point2D p9(1.2, 1.);
	Point2D p10(1.2, 1.2);

	PointVectorBuilder b;
	b.addPoint(p1);
	b.addPoint(p2);
	b.addPoint(p3);
	b.addPoint(p4);
	b.addPoint(p5);
	b.addPoint(p6);
	b.addPoint(p7);
	b.addPoint(p8);
	b.addPoint(p9);
	b.addPoint(p10);

	std::vector <Point2D> points = b.build();
	GiftWrappingAlgorithm::buildHull(points, mockBuilder);

	ASSERT(mockBuilder.points.size() == 4, "Fail. Got %d, want %d", mockBuilder.points.size(), 4);
}

TEST test_BuildHull_FirstElementIsLeftmost_HullSizeIsCorrect(){
	MockPointCollectionBuilder mockBuilder;

	// hull points
	Point2D p1(-1., 0.);
	Point2D p2(2., 0.);
	Point2D p3(2., 2.);
	Point2D p4(0., 2.);
	//remaining points
	Point2D p5(1., 1.);

	PointVectorBuilder b;
	b.addPoint(p1);
	b.addPoint(p2);
	b.addPoint(p3);
	b.addPoint(p4);
	b.addPoint(p5);

	std::vector <Point2D> points = b.build();
	GiftWrappingAlgorithm::buildHull(points, mockBuilder);

	ASSERT(mockBuilder.points.size() == 4, "Fail. Got %d, want %d", mockBuilder.points.size(), 4);
}

TEST test_FindHull_FirstElementIsLeftmost_HullIsCorrect(){
	MockPointCollectionBuilder mockBuilder;

	// hull points
	Point2D p1(-1., 0.);
	Point2D p2(2., 0.);
	Point2D p3(2., 2.);
	Point2D p4(0., 2.);
	//remaining points
	Point2D p5(1., 1.);

	PointVectorBuilder b;

	b.addPoint(p1);
	b.addPoint(p2);
	b.addPoint(p3);
	b.addPoint(p4);
	b.addPoint(p5);

	std::vector <Point2D> points = b.build();

	b.reset();
	b.addPoint(p1);
	b.addPoint(p4);
	b.addPoint(p3);
	b.addPoint(p2);

	std::vector <Point2D> expected = b.build();

	GiftWrappingAlgorithm::buildHull(points, mockBuilder);
	ASSERT(mockBuilder.points == expected, "Fail.");
}

RUN(
		test_BuildHull_EmptyVectorPassed_HullEmpty,
		test_BuildHull_OneElement_HullContainsOneElement,
		test_BuildHull_TwoElements_HullContainsTwoElements,
		test_BuildHull_ThreeElements_HullContainsThreeElements,
		test_BuildHull_AllElementsOnAHull_HullContainsAllElements,
		test_BuildHull_OneElementInsideull_HullSizeIsLessThanPointsSizeByOne,
		test_BuildHull_ManyElementsInsideull_HullSizeIsCorrect,
		test_BuildHull_FirstElementIsLeftmost_HullSizeIsCorrect,
		test_FindHull_FirstElementIsLeftmost_HullIsCorrect
);
