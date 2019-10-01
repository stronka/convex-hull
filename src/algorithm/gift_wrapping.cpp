#include "algorithm/gift_wrapping.hpp"
#include <math.h>

void GiftWrappingAlgorithm::buildHull(
		const std::vector <Point2D> &points, PointCollectionBuilder &builder
) {
	if (isDegeneratedCase(points)) {
		for (const Point2D &p : points){\
			builder.addPoint(p);
		}
		return;
	}

	Point2D leftmost = findLeftMostPoint(points);
	Point2D pointOnHull = leftmost;

	do {
		builder.addPoint(pointOnHull);
		Point2D endpoint = chooseFirstEndpoint(pointOnHull, points);
		pointOnHull = scanCandidates(pointOnHull, endpoint, points);
	} while (leftmost != pointOnHull);
};

bool GiftWrappingAlgorithm::isDegeneratedCase( const std::vector<Point2D> &points) {
	return points.size() < 3;
}

Point2D GiftWrappingAlgorithm::findLeftMostPoint(const std::vector <Point2D> &points) {
	Point2D left = points[0];
	for (Point2D const &p : points){
		if (p.getX() < left.getX()){
			left = p;
		}
	}
	return left;
}

Point2D GiftWrappingAlgorithm::chooseFirstEndpoint(const Point2D &pointOnHull, const std::vector<Point2D> &points) {
	Point2D endpoint = points[0];
	if (endpoint == pointOnHull) {
		endpoint = points[1];
	}
	return endpoint;
}

Point2D GiftWrappingAlgorithm::scanCandidates(const Point2D &pointOnHull, Point2D &endpoint, const std::vector<Point2D> &points) {
	Vector2D line(pointOnHull, endpoint);

	for (Point2D candidate : points) {
		Vector2D candidateLine(pointOnHull, candidate);

		if (isCandidateOnLeftOfLine(line, candidateLine)) {
			endpoint = candidate;
			line = candidateLine;
		}
	}

	return endpoint;
}

bool GiftWrappingAlgorithm::isCandidateOnLeftOfLine(const Vector2D &line, const Vector2D &candidateLine) {
	return line.calculateTurnAngle(candidateLine) < M_PI;
}
