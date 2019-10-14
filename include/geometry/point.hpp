#ifndef INCLUDE_GEOMETRY_POINT_HPP_
#define INCLUDE_GEOMETRY_POINT_HPP_

#include <iostream>


class Point2D {

private:
	double x;
	double y;

public:
	Point2D() : x(0.), y(0.) {};
	Point2D(double x, double y) : x(x), y(y){};

	double getX() const;
	double getY() const;

	double getDistance(const Point2D &other) const;

	bool operator==(const Point2D &other) const;
	bool operator!=(const Point2D &other) const;
	friend std::ostream &operator<<(std::ostream &stream, const Point2D &p);
};


#endif /* INCLUDE_GEOMETRY_POINT_HPP_ */
