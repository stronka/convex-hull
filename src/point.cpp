/*
 * point.cpp
 *
 *  Created on: 29 wrz 2019
 *      Author: Krzysztof
 */

#include "point.hpp"
#include <math.h>

double Point::GetX() const {
	return x;
}

double Point::GetY() const {
	return y;
}


double Point::GetDistance(Point const &other) const {
	return pow(pow(x - other.GetX(), 2) + pow(y - other.GetY(), 2) , .5);
};

std::ostream &operator<<(std::ostream &stream, const Point &p){
	stream << "Point (" << p.GetX() << ", " << p.GetY() << ")" << std::endl;
	return stream;

};

bool Point::operator==(Point &other) const {
	return x == other.GetX() && y == other.GetY();
}


void PointVectorBuilder::reset(){
	std::vector <Point> new_vector;
	points = new_vector;
};

void PointVectorBuilder::addPoint(Point &p){
	points.push_back(p);
};

std::vector <Point> PointVectorBuilder::build() const {
	return points;
}

double Vector2D::CalculateTurnAngle(Vector2D &other) const {
	double const length_product = CalculateLength() * other.CalculateLength();
	double const component_products = \
			CalculateXComponent()*other.CalculateYComponent() - \
			other.CalculateXComponent()*CalculateYComponent();

	return M_PI - asin(component_products/length_product);
}

double Vector2D::CalculateLength() const {
	return begin.GetDistance(end);
}

double Vector2D::CalculateXComponent() const {
	return end.GetX() - begin.GetX();
}

double Vector2D::CalculateYComponent() const {
	return end.GetY() - begin.GetY();
}
//
//double PointVectorCalculator::calculateVectorLength(std::vector <Point> &v) {
//	return v[0].GetDistance(v[1]);
//}
//
//double PointVectorCalculator::getXComponent(std::vector <Point> &v){
//	return v[1].GetX() - v[0].GetX();
//};
//
//double PointVectorCalculator::getYComponent(std::vector <Point> &v){
//	return v[1].GetY() - v[0].GetY();
//}

//double PointVectorCalculator::calculateTurnAngle(std::vector <Point> &v1, std::vector <Point> &v2){
//	return asin();
//}
