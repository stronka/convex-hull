/*
 * gift_wrapping.cpp
 *
 *  Created on: 29 wrz 2019
 *      Author: Krzysztof
 */

#include "algorithm/gift_wrapping.hpp"
#include <math.h>


std::vector <Point> GiftWrappingAlgorithm::FindHull(const std::vector <Point> points) {
	std::vector <Point> hull;

	if (points.size() < 4){
		for (Point p : points){
			hull.push_back(p);
		}
		return hull;
	}

	Point point_on_hull = findLeftMostPoint(points);

	int i = 0;
	Point endpoint;
	Point candidate;

	do {
		hull.push_back(point_on_hull);
		endpoint = points[0];

		Vector2D line = Vector2D(hull[i], endpoint);
		for (int j = 1; j < points.size(); ++j){
			candidate = points[j];
			Vector2D candidate_line = Vector2D(point_on_hull, candidate);
			if ((endpoint == point_on_hull) or (line.CalculateTurnAngle(candidate_line) < M_PI)){
				endpoint = candidate;
			};
		}
		++i;
		point_on_hull = endpoint;
	} while (!(hull[0] == endpoint));



	return hull;
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
