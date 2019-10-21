#ifndef INCLUDE_ALGORITHM_GRAHAM_SCAN_HPP_
#define INCLUDE_ALGORITHM_GRAHAM_SCAN_HPP_

#include "geometry/point.hpp"
#include "geometry/point_collection.hpp"
#include "geometry/vector.hpp"

#include "algorithm/hull_algorithm.hpp"

class GrahamScanAlgorithm : public HullAlgorithm {
public:
	GrahamScanAlgorithm() = default;
	void buildHull(const std::vector <Point2D> &points, PointCollectionBuilder &builder);
};


#endif /* INCLUDE_ALGORITHM_GRAHAM_SCAN_HPP_ */
