/*
 * gift_wrapping.cpp
 *
 *  Created on: 29 wrz 2019
 *      Author: Krzysztof
 */

#include "algorithm/gift_wrapping.hpp"


std::vector <Point> GiftWrappingAlgorithm::FindHull(const std::vector <Point> points) {
	PointVectorBuilder b;

	for (Point p : points){
		b.addPoint(p);
	}


	return b.build();
};
