/*
 * point.cpp
 *
 *  Created on: 29 wrz 2019
 *      Author: Krzysztof
 */

#include "../include/geometry.hpp"

#include <math.h>

double Point2D::GetX() const {
	return x;
}

double Point2D::GetY() const {
	return y;
}


double Point2D::GetDistance(Point2D const &other) const {
	return pow(pow(x - other.GetX(), 2) + pow(y - other.GetY(), 2) , .5);
};

std::ostream &operator<<(std::ostream &stream, const Point2D &p){
	stream << "Point (" << p.GetX() << ", " << p.GetY() << ")" << std::endl;
	return stream;

};

bool Point2D::operator==(Point2D &other) const {
	return x == other.GetX() && y == other.GetY();
}


void PointVectorBuilder::Reset(){
	std::vector <Point2D> new_vector;
	points = new_vector;
};

void PointVectorBuilder::AddPoint(Point2D &p){
	points.push_back(p);
};

std::vector <Point2D> PointVectorBuilder::build() const {
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

std::ostream &operator<<(std::ostream &stream, const Vector2D &v){
	std::cout << "Vector: "<< std::endl << v.begin << v.end;
	return stream;
}
