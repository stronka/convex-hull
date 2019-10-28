#include <math.h>
#include <iostream>
#include "geometry/vector.hpp"

double Vector2D::calculateTurnAngle(const Vector2D &other) const {
	double const length_product = calculateLength() * other.calculateLength();
	double const component_products = \
			calculateXComponent()*other.calculateYComponent() - \
			other.calculateXComponent()*calculateYComponent();

	return M_PI - asin(component_products/length_product);
}

double Vector2D::calculateLength() const {
	return begin.getDistance(end);
}

double Vector2D::calculateXComponent() const {
	return end.getX() - begin.getX();
}

double Vector2D::calculateYComponent() const {
	return end.getY() - begin.getY();
}

std::ostream &operator<<(std::ostream &stream, const Vector2D &v){
	std::cout << "Vector: "<< std::endl << v.begin << v.end;
	return stream;
}
