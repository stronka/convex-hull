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

	double GetDistance(Point2D const &other) const;

	bool operator==(Point2D &other) const;
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

#endif /* INCLUDE_GEOMETRY_HPP_ */
