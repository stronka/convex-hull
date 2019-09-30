/*
 * vector.hpp
 *
 *  Created on: 30 wrz 2019
 *      Author: Krzysztof
 */

#ifndef SRC_GEOMETRY_VECTOR_HPP_
#define SRC_GEOMETRY_VECTOR_HPP_

#include "geometry/geometry.hpp"
#include <iostream>

class Vector2D {
private:
	Point2D begin;
	Point2D end;

public:
	Vector2D(Point2D begin, Point2D end): begin(begin), end(end){};
	double CalculateTurnAngle(Vector2D &other) const;
	double CalculateLength() const;
	double CalculateXComponent() const;
	double CalculateYComponent() const;

	friend std::ostream &operator<<(std::ostream &stream, const Vector2D &v);
};


#endif /* SRC_GEOMETRY_VECTOR_HPP_ */
