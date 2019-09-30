#include "algorithm/gift_wrapping.hpp"
#include <math.h>


std::vector <Point2D> GiftWrappingAlgorithm::FindHull(const std::vector <Point2D> &points) {
	if (IsDegeneratedCase(points)) {
		return points;
	}

	std::vector <Point2D> hull;
	Point2D point_on_hull = FindLeftMostPoint(points);

	do {
		hull.push_back(point_on_hull);
		Point2D endpoint = ChooseFirstEndpoint(point_on_hull, points);
		point_on_hull = ScanCandidates(point_on_hull, endpoint, points);
	} while (hull[0] != point_on_hull);

	return hull;
};

bool GiftWrappingAlgorithm::IsDegeneratedCase( const std::vector<Point2D> &points) {
	return points.size() < 3;
}

Point2D GiftWrappingAlgorithm::FindLeftMostPoint(const std::vector <Point2D> &points) {
	Point2D left = points[0];
	for (Point2D const &p : points){
		if (p.GetX() < left.GetX()){
			left = p;
		}
	}
	return left;
}

Point2D GiftWrappingAlgorithm::ChooseFirstEndpoint(const Point2D &point_on_hull, const std::vector<Point2D> &points) {
	Point2D endpoint = points[0];
	if (endpoint == point_on_hull) {
		endpoint = points[1];
	}
	return endpoint;
}

Point2D GiftWrappingAlgorithm::ScanCandidates(const Point2D &point_on_hull, Point2D &endpoint, const std::vector<Point2D> &points) {
	Vector2D line = Vector2D(point_on_hull, endpoint);

	for (Point2D candidate : points) {
		Vector2D candidate_line = Vector2D(point_on_hull, candidate);

		if (IsCandidateOnLeftOfLine(line, candidate_line)) {
			endpoint = candidate;
			line = candidate_line;
		}
	}

	return endpoint;
}

bool GiftWrappingAlgorithm::IsCandidateOnLeftOfLine(const Vector2D &line, const Vector2D &candidate_line) {
	return line.CalculateTurnAngle(candidate_line) < M_PI;
}
