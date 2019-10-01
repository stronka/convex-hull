#include "ctestie.h"

#include "../../src/geometry/point_collection.cpp"

#include <stdexcept>
static PointVectorBuilder b;

TEST test_OrderedPointCollectionCreate_Always_CreateObject(){
	OrderedPointCollection collection;
	ASSERT(true, "Fail.");
}

TEST test_OrderedPointCollectionGet_IndexInRange_ReturnsReferenceToPoint(){
	Point2D p = Point2D(1., 2.);

	b.reset();
	b.addPoint(p);

	OrderedPointCollection collection = OrderedPointCollection(b.build());
	ASSERT(collection.get(0) == p, "Fail.");
}

TEST test_OrderedPointCollectionGet_IndexNotInRange_Throws(){
	Point2D p = Point2D(1., 2.);

	b.reset();
	b.addPoint(p);

	OrderedPointCollection collection = OrderedPointCollection(b.build());

	try {
		collection.get(1);
		ASSERT(false, "Exception not raised.");
	} catch (const std::out_of_range &e) {
		ASSERT(true, "");
	} catch (const std::exception &e){
		ASSERT(false, "Wrong exception raised: %s", e.what());
	}

}

TEST test_OrderedPointCollectionGetOperator_IndexInRange_ReturnsReferenceToPoint(){
	Point2D p = Point2D(1., 2.);

	b.reset();
	b.addPoint(p);

	OrderedPointCollection collection = OrderedPointCollection(b.build());
	ASSERT(collection[0] == p, "Fail.");
}

TEST test_OrderedPointCollectionGetOperator_IndexNotInRange_Throws(){
	Point2D p = Point2D(1., 2.);

	b.reset();
	b.addPoint(p);

	OrderedPointCollection collection = OrderedPointCollection(b.build());

	try {
		collection[1];
		ASSERT(false, "Exception not raised.");
	} catch (const std::out_of_range &e) {
		ASSERT(true, "");
	} catch (const std::exception &e){
		ASSERT(false, "Wrong exception raised: %s", e.what());
	}

}

TEST test_OrderedPointCollectionEqualOperator_CollectionsTheSame_ReturnTrue(){
	Point2D p1 = Point2D(1., 2.);
	Point2D p2 = Point2D(2., 2.);

	b.reset();
	b.addPoint(p1);
	b.addPoint(p2);

	std::vector <Point2D> points1 = b.build();
	std::vector <Point2D> points2 = b.build();
	ASSERT(OrderedPointCollection(points1) == OrderedPointCollection(points2), "Fail");
}

TEST test_OrderedPointCollectionEqualOperator_CollectionsDifferentSize_ReturnFalse(){
	Point2D p1 = Point2D(1., 2.);
	Point2D p2 = Point2D(2., 2.);

	b.reset();
	b.addPoint(p1);
	b.addPoint(p2);
	std::vector <Point2D> points1 = b.build();

	b.reset();
	b.addPoint(p1);
	std::vector <Point2D> points2 = b.build();

	ASSERT(!(OrderedPointCollection(points1) == OrderedPointCollection(points2)), "Fail");
}

TEST test_OrderedPointCollectionEqualOperator_CollectionsTheSameSizeButDifferentPoints_ReturnFalse(){
	Point2D p1 = Point2D(1., 2.);
	Point2D p2 = Point2D(3., 2.);
	Point2D p3 = Point2D(2., 2.);

	b.reset();
	b.addPoint(p1);
	b.addPoint(p2);
	std::vector <Point2D> points1 = b.build();

	b.reset();
	b.addPoint(p1);
	b.addPoint(p3);
	std::vector <Point2D> points2 = b.build();
	ASSERT(!(OrderedPointCollection(points1) == OrderedPointCollection(points2)), "Fail");
}

TEST test_OrderedPointCollectionEqualOperator_CollectionsDifferentOrder_ReturnFalse(){
	Point2D p1 = Point2D(1., 2.);
	Point2D p2 = Point2D(2., 2.);

	b.reset();
	b.addPoint(p1);
	b.addPoint(p2);
	std::vector <Point2D> points1 = b.build();

	b.reset();
	b.addPoint(p2);
	b.addPoint(p1);
	std::vector <Point2D> points2 = b.build();
	ASSERT(!(OrderedPointCollection(points1) == OrderedPointCollection(points2)), "Fail");
}

TEST test_OrderedPointCollectionSize_CollectionEmpty_ReturnZero(){
	OrderedPointCollection collection;
	ASSERT(collection.size() == 0, "Fail");
}

TEST test_OrderedPointCollectionSize_CollectionNotEmpty_ReturnSize(){
	Point2D p1 = Point2D(1., 2.);
	Point2D p2 = Point2D(2., 2.);

	b.reset();
	b.addPoint(p1);
	b.addPoint(p2);
	OrderedPointCollection collection = OrderedPointCollection(b.build());
	ASSERT(collection.size() == 2, "Fail");
}

TEST test_OrderedPointCollectionEmpty_CollectionEmpty_ReturnTrue(){
	OrderedPointCollection collection = OrderedPointCollection();
	ASSERT(collection.empty(), "Fail");
}

TEST test_OrderedPointCollectionEmpty_CollectionNotEmpty_ReturnFalse(){
	Point2D p1 = Point2D(1., 2.);
	Point2D p2 = Point2D(2., 2.);

	b.reset();
	b.addPoint(p1);
	b.addPoint(p2);
	OrderedPointCollection collection = OrderedPointCollection(b.build());
	ASSERT(not collection.empty(), "Fail");
}


TEST test_OrderedPointCollectionBuilderBuild_NoPointsAdded_ReturnEmptyCollection(){
	OrderedPointCollectionBuilder builder;
	ASSERT(builder.build()->empty(), "Fail.");
}


RUN(
		test_OrderedPointCollectionGet_IndexInRange_ReturnsReferenceToPoint,
		test_OrderedPointCollectionGet_IndexNotInRange_Throws,
		test_OrderedPointCollectionGetOperator_IndexInRange_ReturnsReferenceToPoint,
		test_OrderedPointCollectionGetOperator_IndexNotInRange_Throws,
		test_OrderedPointCollectionEqualOperator_CollectionsTheSame_ReturnTrue,
		test_OrderedPointCollectionEqualOperator_CollectionsDifferentSize_ReturnFalse,
		test_OrderedPointCollectionEqualOperator_CollectionsTheSameSizeButDifferentPoints_ReturnFalse,
		test_OrderedPointCollectionEqualOperator_CollectionsDifferentOrder_ReturnFalse,
		test_OrderedPointCollectionSize_CollectionEmpty_ReturnZero,
		test_OrderedPointCollectionSize_CollectionNotEmpty_ReturnSize,
		test_OrderedPointCollectionEmpty_CollectionEmpty_ReturnTrue,
		test_OrderedPointCollectionEmpty_CollectionNotEmpty_ReturnFalse,
		test_OrderedPointCollectionBuilderBuild_NoPointsAdded_ReturnEmptyCollection
);
