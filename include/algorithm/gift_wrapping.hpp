#ifndef INCLUDE_ALGORITHM_GIFT_WRAPPING_HPP_
#define INCLUDE_ALGORITHM_GIFT_WRAPPING_HPP_

#include <vector>

#include "../geometry/point.hpp"
#include "geometry/vector.hpp"

class GiftWrappingAlgorithm {

public:
	static std::vector <Point2D> FindHull(const std::vector <Point2D> &points);

private:
	static bool IsDegeneratedCase(const std::vector<Point2D> &points);
	static Point2D FindLeftMostPoint(const std::vector <Point2D> &points);
	static Point2D ChooseFirstEndpoint(const Point2D &point_on_hull, const std::vector<Point2D> &points);
	static Point2D ScanCandidates(const Point2D &point_on_hull, Point2D &endpoint, const std::vector<Point2D> &points);
	static bool IsCandidateOnLeftOffLine(const Vector2D &line, const Vector2D &candidate_line);
};

#endif /* INCLUDE_ALGORITHM_GIFT_WRAPPING_HPP_ */
