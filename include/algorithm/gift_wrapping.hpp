/*
 * gift_wrapping.hpp
 *
 *  Created on: 29 wrz 2019
 *      Author: Krzysztof
 */

#ifndef INCLUDE_ALGORITHM_GIFT_WRAPPING_HPP_
#define INCLUDE_ALGORITHM_GIFT_WRAPPING_HPP_

#include <vector>
#include "point.hpp"

class GiftWrappingAlgorithm {

public:
	static std::vector <Point> FindHull(const std::vector <Point> points);

private:
	static Point findLeftMostPoint(const std::vector <Point> points);
};

#endif /* INCLUDE_ALGORITHM_GIFT_WRAPPING_HPP_ */
