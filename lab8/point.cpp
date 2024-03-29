#include "point.h"
#include <iostream>
#include <cmath>

Point::Point(): x_(0.0), y_(0.0) {}

Point::Point(double x, double y) : x_(x), y_(y) {}

Point::Point(std::istream &is) {
	is >> x_ >> y_;
}
Point::Point(const Point& other) : x_(other.x_), y_(other.y_) {}

double Point::dist(Point& other) {
    double dx = (other.x_ - x_);
    double dy = (other.y_ - y_);
    return std::sqrt(dx*dx + dy*dy);
}

std::istream& operator>>(std::istream& is, Point& p) {
	is >> p.x_ >> p.y_;
	return is;
}

std::ostream& operator<<(std::ostream& os, Point& p) {
	os << "(" << p.x_ << ", " << p.y_ << ")";
	return os;
}
bool Point::operator==(const Point& other) {
    return (x_ == other.x_ && y_ == other.y_);
}