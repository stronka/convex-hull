/*
 * point.hpp
 *
 *  Created on: 29 wrz 2019
 *      Author: Krzysztof
 */

#ifndef INCLUDE_POINT_HPP_
#define INCLUDE_POINT_HPP_

#include <vector>


class Point {

private:
	double x;
	double y;

public:
	Point(double x, double y) : x(x), y(y){
	};

	double GetX() const;
	double GetY() const;

	bool operator==(Point &other) const;
};


class PointVectorBuilder {
private:
	std::vector <Point> points;

public:
	void addPoint(Point &p);
	std::vector <Point> build() const;
};


#endif /* INCLUDE_POINT_HPP_ */
