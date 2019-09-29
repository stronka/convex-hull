/*
 * gift_wrapping.hpp
 *
 *  Created on: 29 wrz 2019
 *      Author: Krzysztof
 */

#ifndef INCLUDE_ALGORITHM_GIFT_WRAPPING_HPP_
#define INCLUDE_ALGORITHM_GIFT_WRAPPING_HPP_

#include <list>
#include "point.hpp"

class GiftWrappingAlgorithm {

public:
	GiftWrappingAlgorithm(){};
	std::list <Point> FindHull(const std::list <Point> points) const;

};

#endif /* INCLUDE_ALGORITHM_GIFT_WRAPPING_HPP_ */
