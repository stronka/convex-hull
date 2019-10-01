#ifndef INCLUDE_ALGORITHM_GIFT_WRAPPING_HPP_
#define INCLUDE_ALGORITHM_GIFT_WRAPPING_HPP_

#include <vector>
#include <memory>

#include "geometry/point.hpp"
#include "geometry/point_collection.hpp"
#include "geometry/vector.hpp"

class GiftWrappingAlgorithm {

public:
	static void buildHull(const std::vector <Point2D> &points, PointCollectionBuilder &builder);

private:
	static bool isDegeneratedCase(const std::vector<Point2D> &points);
	static Point2D findLeftMostPoint(const std::vector <Point2D> &points);
	static Point2D chooseFirstEndpoint(const Point2D &pointOnHull, const std::vector<Point2D> &points);
	static Point2D scanCandidates(const Point2D &pointOnHull, Point2D &endpoint, const std::vector<Point2D> &points);
	static bool isCandidateOnLeftOfLine(const Vector2D &line, const Vector2D &candidateLine);
	static void buildDegeneratedHull(const std::vector<Point2D> &points, PointCollectionBuilder &builder);
	static void doJarvisScan(const std::vector<Point2D> &points, PointCollectionBuilder &builder);
};

#endif /* INCLUDE_ALGORITHM_GIFT_WRAPPING_HPP_ */
