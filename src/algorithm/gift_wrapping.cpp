/*
 * gift_wrapping.cpp
 *
 *  Created on: 29 wrz 2019
 *      Author: Krzysztof
 */

#include "algorithm/gift_wrapping.hpp"
#include <math.h>


std::vector <Point2D> GiftWrappingAlgorithm::FindHull(const std::vector <Point2D> points) {
	std::vector <Point2D> hull;

	if (points.size() < 4){
		for (Point2D p : points){
			hull.push_back(p);
		}
		return hull;
	}

	Point2D point_on_hull = FindLeftMostPoint(points);

	int i = 0;

	do {
		hull.push_back(point_on_hull);
		Point2D endpoint = points[0];
		if (endpoint == point_on_hull){
			endpoint = points[1];
		}

		Vector2D line = Vector2D(point_on_hull, endpoint);
		for (Point2D candidate : points){
			if (candidate == point_on_hull or candidate == endpoint or point_on_hull == endpoint) {
				continue;
			}

			Vector2D candidate_line = Vector2D(point_on_hull, candidate);
			if (line.CalculateTurnAngle(candidate_line) < M_PI){
				endpoint = candidate;
				line = candidate_line;
			}
		}

		++i;
		point_on_hull = endpoint;
	} while (!(hull[0] == point_on_hull));

	return hull;
};

Point2D GiftWrappingAlgorithm::FindLeftMostPoint(const std::vector <Point2D> points){
	Point2D left = points[0];
	for (Point2D const &p : points){
		if (p.GetX() < left.GetX()){
			left = p;
		}
	}
	return left;
}
