/*
 * gift_wrapping.cpp
 *
 *  Created on: 29 wrz 2019
 *      Author: Krzysztof
 */

#include "algorithm/gift_wrapping.hpp"


std::vector <Point> GiftWrappingAlgorithm::FindHull(const std::vector <Point> points) {
	PointVectorBuilder b;

	if (points.empty()){
		return b.build();
	}

	Point pointOnHull = findLeftMostPoint(points);
	b.addPoint(pointOnHull);

	for (Point p : points){
		b.addPoint(p);
	}


	return b.build();
};

Point GiftWrappingAlgorithm::findLeftMostPoint(const std::vector <Point> points){
	Point left = points[0];
	for (Point const &p : points){
		if (p.GetX() < left.GetX()){
			left = p;
		}
	}
	return left;
}
