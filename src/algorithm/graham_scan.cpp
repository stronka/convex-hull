#include "algorithm/graham_scan.hpp"
#include <algorithm>
#include <math.h>
#include <deque>

void GrahamScanAlgorithm::buildHull(const std::vector <Point2D> &points, PointCollectionBuilder &builder){
	if (isDegeneratedCase(points)){
		buildDegeneratedHull(points, builder);
		return;
	}

	std::vector <Point2D> sorted = points;

	sorter.setOrigin(find_lowest_y_point(sorted));
	sorter.sort(sorted);

	std::deque <Point2D> stack;

	for (auto &p : sorted){
		std::cout << p << std::endl;
	}

	for (auto &p : sorted){
		while (stack.size() > 1 and ccw(stack[1], stack[0], p) < 0){
			stack.pop_front();
		}
		stack.push_front(p);
	}

	for (auto &p : stack){
		builder.addPoint(p);
	}
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

	if (v1.calculateTurnAngle(v2) < M_PI or origin.getDistance(p2) < 1e-6){
		return false;
	} else {
		return true;
	}
}

Point2D *find_lowest_y_point(std::vector <Point2D> points){
	Point2D *lowest = &points[0];

	for (auto &p : points){
		if (p.getY() < lowest->getY()){
			lowest = &p;
		}
	}

	return lowest;
};

int ccw(Point2D &p1, Point2D &p2, Point2D &p3){
	Vector2D v1(p1, p2);
	Vector2D v2(p2, p3);

	const double angle = v1.calculateTurnAngle(v2);

	if (angle > M_PI){
		return 1;
	} else if (angle < M_PI) {
		return -1;
	} else {
		return 0;
	}
}
