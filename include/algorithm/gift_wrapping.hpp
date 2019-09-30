/*
 * gift_wrapping.hpp
 *
 *  Created on: 29 wrz 2019
 *      Author: Krzysztof
 */

#ifndef INCLUDE_ALGORITHM_GIFT_WRAPPING_HPP_
#define INCLUDE_ALGORITHM_GIFT_WRAPPING_HPP_

#include <vector>

#include "../geometry/point.hpp"

class GiftWrappingAlgorithm {

public:
	static std::vector <Point2D> FindHull(const std::vector <Point2D> &points);

private:
	static bool IsDegeneratedCase(const std::vector<Point2D> &points);
	static Point2D FindLeftMostPoint(const std::vector <Point2D> &points);
	static Point2D ChooseFirstEndpoint(const Point2D &point_on_hull, const std::vector<Point2D> &points);
	static Point2D ScanCandidates(const Point2D &point_on_hull, Point2D &endpoint, const std::vector<Point2D> &points);
};

#endif /* INCLUDE_ALGORITHM_GIFT_WRAPPING_HPP_ */
