/*
 * point.hpp
 *
 *  Created on: 29 wrz 2019
 *      Author: Krzysztof
 */

#ifndef INCLUDE_POINT_HPP_
#define INCLUDE_POINT_HPP_

#include <vector>
#include <iostream>

class Point {

private:
	double x;
	double y;

public:
	Point() : x(0.), y(0.) {};
	Point(double x, double y) : x(x), y(y){
	};

	double GetX() const;
	double GetY() const;

	double GetDistance(Point const &other) const;

	bool operator==(Point &other) const;
	friend std::ostream &operator<<(std::ostream &stream, const Point &p);
};


class PointVectorBuilder {
private:
	std::vector <Point> points;

public:
	void reset();
	void addPoint(Point &p);
	std::vector <Point> build() const;
};


class Vector2D {
private:
	Point begin;
	Point end;

public:
	Vector2D(Point begin, Point end): begin(begin), end(end){};
	double CalculateTurnAngle(Vector2D &other) const;
	double CalculateLength() const;
	double CalculateXComponent() const;
	double CalculateYComponent() const;
};

#endif /* INCLUDE_POINT_HPP_ */
