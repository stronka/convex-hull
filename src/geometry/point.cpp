#include "../../include/geometry/point.hpp"
#include <math.h>


double Point2D::getX() const {
	return x;
}

double Point2D::getY() const {
	return y;
}

double Point2D::getDistance(const Point2D &other) const {
	return pow(pow(x - other.getX(), 2) + pow(y - other.getY(), 2) , .5);
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


void PointVectorBuilder::reset(){
	points = std::vector <Point2D>();
};

void PointVectorBuilder::addPoint(Point2D &p){
	points.push_back(p);
};

std::vector <Point2D> PointVectorBuilder::build() const {
	return points;
}
