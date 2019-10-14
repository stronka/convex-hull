#include "geometry/point_collection.hpp"
#include <stdexcept>


void PointVectorBuilder::reset(){
	points = std::vector <Point2D>();
};

void PointVectorBuilder::addPoint(const Point2D &p){
	points.push_back(p);
};

std::vector <Point2D> PointVectorBuilder::build() const {
	return points;
}
