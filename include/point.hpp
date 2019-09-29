/*
 * point.hpp
 *
 *  Created on: 29 wrz 2019
 *      Author: Krzysztof
 */

#ifndef INCLUDE_POINT_HPP_
#define INCLUDE_POINT_HPP_

class Point {

private:
	double x;
	double y;

public:
	Point(double x, double y) : x(x), y(y){
	};

	double GetX() const;
	double GetY() const;
};


#endif /* INCLUDE_POINT_HPP_ */
