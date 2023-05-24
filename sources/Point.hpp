#pragma once


namespace ariel {

    class Point {
    private:
        double x, y;

    public:
        Point();
        Point(double, double);
        double distance(Point const &other) const;
        void print() const;
        Point moveTowards(Point source, Point dest, double distance) const;
    };
}