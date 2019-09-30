/*
 * point.hpp
 *
 *  Created on: 29 wrz 2019
 *      Author: Krzysztof
 */

#ifndef INCLUDE_GEOMETRY_HPP_
#define INCLUDE_GEOMETRY_HPP_

#include <vector>
#include <iostream>


class Point2D {

private:
	double x;
	double y;

public:
	Point2D() : x(0.), y(0.) {};
	Point2D(double x, double y) : x(x), y(y){
	};

	double GetX() const;
	double GetY() const;

	double GetDistance(const Point2D &other) const;

	bool operator==(const Point2D &other) const;
	bool operator!=(const Point2D &other) const;
	friend std::ostream &operator<<(std::ostream &stream, const Point2D &p);
};


class PointVectorBuilder {
private:
	std::vector <Point2D> points;

public:
	void Reset();
	void AddPoint(Point2D &p);
	std::vector <Point2D> build() const;
};


#endif /* INCLUDE_GEOMETRY_HPP_ */
