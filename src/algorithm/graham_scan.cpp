#include "algorithm/graham_scan.hpp"
#include <algorithm>
#include <math.h>

void GrahamScanAlgorithm::buildHull(const std::vector <Point2D> &points, PointCollectionBuilder &builder){
	if (isDegeneratedCase(points)){
		buildDegeneratedHull(points, builder);
	}

	std::vector <Point2D> sorted = points;

}

bool GrahamScanAlgorithm::isDegeneratedCase(const std::vector <Point2D> &points) const {
	if (points.size() < 4) {
		return true;
	} else {
		return false;
	}
}

void GrahamScanAlgorithm::buildDegeneratedHull( const std::vector<Point2D> &points, PointCollectionBuilder &builder) const {
	for (const auto &p : points) {
		builder.addPoint(p);
	}
}

void PointPolarAngleSorter::setOrigin(const Point2D *p0){
	origin = p0;
}

void PointPolarAngleSorter::sort(std::vector <Point2D> &points) const {
	std::sort(points.begin(), points.end(), ComparePointsAngle(*origin));
}

bool PointPolarAngleSorter::ComparePointsAngle::operator ()(Point2D p1, Point2D p2) const {
	Vector2D v1(origin, p1);
	Vector2D v2(origin, p2);

	if (v1.calculateTurnAngle(v2) > M_PI){
		return true;
	} else {
		return false;
	}
}
