#ifndef INCLUDE_GEOMETRY_POINT_COLLECTION_HPP_
#define INCLUDE_GEOMETRY_POINT_COLLECTION_HPP_

#include <vector>
#include "geometry/point.hpp"

class PointCollection {
};


class OrderedPointCollection : public PointCollection {
private:
	std::vector <Point2D> points;
public:
	OrderedPointCollection(){};
	OrderedPointCollection(std::vector<Point2D> points) : points(points) {};

	const Point2D &get(const int index) const;
	const Point2D &operator[](const int index) const;
	bool operator==(const OrderedPointCollection &other) const;

	friend std::ostream &operator<<(std::ostream &stream, const OrderedPointCollection &collection);
};

#endif /* INCLUDE_GEOMETRY_POINT_COLLECTION_HPP_ */
