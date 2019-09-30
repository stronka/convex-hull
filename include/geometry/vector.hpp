#ifndef INCLUDE_GEOMETRY_POINT_HPP_
#define INCLUDE_GEOMETRY_POINT_HPP_

#include <iostream>
#include "point.hpp"

class Vector2D {
private:
	Point2D begin;
	Point2D end;

public:
	Vector2D(Point2D begin, Point2D end): begin(begin), end(end){};
	double CalculateTurnAngle(const Vector2D &other) const;
	double CalculateLength() const;
	double CalculateXComponent() const;
	double CalculateYComponent() const;

	friend std::ostream &operator<<(std::ostream &stream, const Vector2D &v);
};


#endif /* INCLUDE_GEOMETRY_POINT_HPP_ */
