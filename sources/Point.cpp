#include "Point.hpp"

using namespace ariel;

Point::Point(): x(0), y(0) {}
Point::Point(double x, double y): x(x), y(y) {}
double Point::distance(Point const &other) const {
    return 0;
}
void Point::print() const {
    return;
}
Point Point::moveTowards(Point source, Point dest, double distance) const {
    return Point();
}