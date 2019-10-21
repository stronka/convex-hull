#include "geometry/point.hpp"
#include "geometry/point_collection.hpp"

class MockPointCollectionBuilder : public PointCollectionBuilder {
public:
	std::vector <Point2D> points;

	void addPoint(const Point2D &p) { points.push_back(p); };
};

