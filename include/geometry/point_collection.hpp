#ifndef INCLUDE_GEOMETRY_POINT_COLLECTION_HPP_
#define INCLUDE_GEOMETRY_POINT_COLLECTION_HPP_

#include <vector>
#include <memory>
#include "geometry/point.hpp"

class PointCollectionBuilder {
public:
	virtual void addPoint(const Point2D &p) = 0;

	virtual ~PointCollectionBuilder(){};
};


class PointVectorBuilder : public PointCollectionBuilder {
private:
	std::vector <Point2D> points;

public:
	std::vector <Point2D> build() const;
	void addPoint(const Point2D &p);
	void reset();
};

#endif /* INCLUDE_GEOMETRY_POINT_COLLECTION_HPP_ */
