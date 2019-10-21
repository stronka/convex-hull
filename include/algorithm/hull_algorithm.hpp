#ifndef INCLUDE_ALGORITHM_HULL_ALGORITHM_HPP_
#define INCLUDE_ALGORITHM_HULL_ALGORITHM_HPP_

#include "geometry/point.hpp"
#include "geometry/point_collection.hpp"

class HullAlgorithm {
public:
	virtual void buildHull(const std::vector <Point2D> &points, PointCollectionBuilder &builder) = 0;
	virtual ~HullAlgorithm(){};
};

#endif /* INCLUDE_ALGORITHM_HULL_ALGORITHM_HPP_ */
