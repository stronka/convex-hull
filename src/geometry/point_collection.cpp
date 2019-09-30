#include "geometry/point_collection.hpp"

const Point2D &OrderedPointCollection::get(const int index) const {
	return points[index];
};

bool OrderedPointCollection::operator ==(const OrderedPointCollection &other) const {
	return points == other.points;
}

std::ostream &operator<<(std::ostream &stream, const OrderedPointCollection &collection){
	stream << "OrderedPointCollection of size " << collection.points.size() << std::endl;
	for (const Point2D &p : collection.points){
		stream << p;
	}
	return stream;
};
