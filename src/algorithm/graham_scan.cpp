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

	sorter.setOrigin(*find_leftmost_lowest_y_point(points));
	sorter.sort(sorted);

	std::deque <Point2D> stack;

	for (auto &p : sorted){
		while (stack.size() > 1 and ccw(stack[1], stack[0], p) > 0){
			stack.pop_front();
		}
		stack.push_front(p);
	}

	for (typename std::deque<Point2D>::reverse_iterator it = stack.rbegin(); it < stack.rend(); ++it){
		builder.addPoint(*it);
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

void PointPolarAngleSorter::setOrigin(Point2D p0){
	origin = p0;
}


void PointPolarAngleSorter::sort(std::vector <Point2D> &points) const {
	std::sort(points.begin(), points.end(), ComparePointsAngle(origin));
	filterCollinear(points);
}

template <class T> static inline std::vector<T> stack_to_vector(std::deque<T> stack);

void PointPolarAngleSorter::filterCollinear( std::vector<Point2D> &points) const {
	std::deque<Point2D> filtered;

	for (auto &p : points) {

		if (filtered.size() > 1) {
			Vector2D v1(origin, filtered[0]);
			Vector2D v2(origin, p);
			double angle = v1.calculateTurnAngle(v2);
			if (fabs(angle - M_PI) < 1e-3
					&& v1.calculateLength() < v2.calculateLength()) {
				filtered.pop_front();
			}
		}

		filtered.push_front(p);
	}

	points = stack_to_vector<Point2D>(filtered);
}

bool PointPolarAngleSorter::ComparePointsAngle::operator ()(Point2D p1, Point2D p2) const {
	if (origin.getDistance(p1) < 1e-6){
		return true;
	} else if (origin.getDistance(p2) < 1e-6){
		return false;
	}

	Vector2D v1(origin, p1);
	Vector2D v2(origin, p2);
	double const angle = v1.calculateXComponent()/v1.calculateLength() / (v2.calculateXComponent()/v2.calculateLength());

	if (angle < 1){
		return false;
	} else {
		return true;
	}
}

template <class T>
static inline std::vector<T> stack_to_vector(std::deque<T> stack){
	std::vector <T> result;

	for (typename std::deque<T>::reverse_iterator it = stack.rbegin(); it < stack.rend(); ++it){
		result.push_back(*it);
	}

	return result;
}

Point2D *find_leftmost_lowest_y_point(std::vector <Point2D> points){
	Point2D *lowest = &points[0];

	for (auto &p : points){
		if (p.getY() < lowest->getY() or (p.getY() == lowest->getY() and p.getX() < lowest->getX())){
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
