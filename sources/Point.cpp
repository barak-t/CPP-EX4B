#include "Point.hpp"
#include "math.h"

using namespace ariel;
using namespace std;

Point::Point(): x(0), y(0) {}
Point::Point(double x, double y): x(x), y(y) {}
double Point::distance(Point const &other) const {
    double dx = pow(other.x - this->x, 2);
    double dy = pow(other.y - this->y, 2);

    return sqrt(dx + dy);
}
void Point::print() const {
    return;
}
Point Point::moveTowards(Point source, Point dest, double distance) {
    if (distance < 0) {
        throw invalid_argument("Can't be negative distance");
    }
    double s2d = source.distance(dest);
    if (s2d < distance) {
        return dest;
    }
    double x = source.x + (distance * (dest.x - source.x) / s2d);
    double y = source.y + (distance * (dest.y - source.y) / s2d);
    return Point(x, y);
}
