#ifndef INCLUDE_ALGORITHM_GRAHAM_SCAN_HPP_
#define INCLUDE_ALGORITHM_GRAHAM_SCAN_HPP_

#include "geometry/point.hpp"
#include "geometry/point_collection.hpp"
#include "geometry/vector.hpp"

#include "algorithm/hull_algorithm.hpp"

Point2D *find_lowest_y_point(std::vector <Point2D> points);

class PointPolarAngleSorter {
public:
	PointPolarAngleSorter() = default;
	void setOrigin(const Point2D *p0);
	void sort(std::vector <Point2D> &points) const;
private:
	const Point2D *origin = NULL;

	class ComparePointsAngle {
	public:
		ComparePointsAngle(Point2D p0) : origin(p0) {};
		bool operator()(Point2D p1, Point2D p2) const;
	private:
		Point2D origin;
	};
};

class GrahamScanAlgorithm : public HullAlgorithm {
public:
	GrahamScanAlgorithm() : sorter(PointPolarAngleSorter()) {};
	void buildHull(const std::vector <Point2D> &points, PointCollectionBuilder &builder);

private:
	PointPolarAngleSorter sorter;

	bool isDegeneratedCase(const std::vector <Point2D> &points) const;
	void buildDegeneratedHull(const std::vector<Point2D> &points, PointCollectionBuilder &builder) const;
};

#endif /* INCLUDE_ALGORITHM_GRAHAM_SCAN_HPP_ */