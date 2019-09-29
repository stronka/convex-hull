/*
 * point.cpp
 *
 *  Created on: 29 wrz 2019
 *      Author: Krzysztof
 */

#include "point.hpp"


double Point::GetX() const {
	return x;
}

double Point::GetY() const {
	return y;
}


bool Point::operator==(Point &other) const {
	return x == other.GetX() && y == other.GetY();
}


void PointVectorBuilder::addPoint(Point &p){
	points.push_back(p);
};

std::vector <Point> PointVectorBuilder::build() const {
	return points;
}

