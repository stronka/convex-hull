#include <math.h>
#include "geometry/point.hpp"


double Point2D::getX() const {
	return x;
}

double Point2D::getY() const {
	return y;
}

double Point2D::getDistance(const Point2D &other) const {
	return sqrt(pow(x - other.getX(), 2) + pow(y - other.getY(), 2));
};

bool Point2D::operator==(const Point2D &other) const {
	return x == other.getX() and y == other.getY();
}

bool Point2D::operator!=(const Point2D &other) const {
	return x != other.getX() or y != other.getY();
}

std::ostream &operator<<(std::ostream &stream, const Point2D &p){
	stream << "Point (" << p.getX() << ", " << p.getY() << ")" << std::endl;
	return stream;

};

