/*
 * vector.cpp
 *
 *  Created on: 30 wrz 2019
 *      Author: Krzysztof
 */

#include "geometry/vector.hpp"
#include <math.h>

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
