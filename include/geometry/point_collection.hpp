#ifndef INCLUDE_GEOMETRY_POINT_COLLECTION_HPP_
#define INCLUDE_GEOMETRY_POINT_COLLECTION_HPP_

#include <vector>
#include <memory>
#include "geometry/point.hpp"

class PointCollection {
};


class OrderedPointCollection : public PointCollection {
private:
	std::vector <Point2D> points;
public:
	OrderedPointCollection(){};
	OrderedPointCollection(std::vector<Point2D> points) : points(points) {};

	const int size() const;
	const bool empty() const;

	const Point2D &get(const int index) const;
	const Point2D &operator[](const int index) const;
	bool operator==(const OrderedPointCollection &other) const;

	friend std::ostream &operator<<(std::ostream &stream, const OrderedPointCollection &collection);
};


class PointCollectionBuilder {
public:
	virtual void addPoint(const Point2D &p) = 0;
	virtual std::shared_ptr <const OrderedPointCollection> build() const = 0;

	virtual ~PointCollectionBuilder(){};
};


class OrderedPointCollectionBuilder : public PointCollectionBuilder {
public:
	virtual void addPoint(const Point2D &p);
	virtual std::shared_ptr <const OrderedPointCollection> build() const;
private:
	std::vector <Point2D> points;
};

#endif /* INCLUDE_GEOMETRY_POINT_COLLECTION_HPP_ */
