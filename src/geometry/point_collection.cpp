#include "geometry/point_collection.hpp"
#include <stdexcept>

const Point2D &OrderedPointCollection::get(const int index) const {
	if (index < points.size()){
		return points[index];
	} else {
		throw std::out_of_range("Index out of range.");
	}
};

const Point2D &OrderedPointCollection::operator[](const int index) const {
	return get(index);
}

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
