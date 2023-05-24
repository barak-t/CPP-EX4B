
#include "doctest.h"
#include "sources/Team.hpp"
#include "sources/Character.hpp"
#include "sources/Point.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("check point") {

    Point p1(0,0);
    Point p2(1,0);
    Point p3(1,1);
    CHECK_NOTHROW(p1.print());
    CHECK(p1.distance(p2) == 1);
    CHECK(p2.distance(p1) == 1);
    CHECK_NOTHROW(p1.moveTowards(p2, p3, 11));
    CHECK_THROWS(p1.moveTowards(p2, p1, 11));
    CHECK_THROWS(p1.moveTowards(p2, p2, 11));
    CHECK_THROWS(p1.moveTowards(p2, p3, -10));
}

TEST_CASE("check team") {

    Point p1(0,0);
    Point p2(1,0);

    Cowboy *c1 = new Cowboy("kobi", p1);
    OldNinja *c2 = new OldNinja("avi", p2);
    Team t1(c1);

    CHECK_THROWS(Team(c1));
    CHECK_THROWS(Team(nullptr));

    CHECK_NOTHROW(t1.print());
    CHECK_THROWS(t1.add(c1));
    CHECK_NOTHROW(t1.add(c2));

    CHECK(t1.stillAlive() != 0);

    CHECK_NOTHROW(c1->move(c2));
    CHECK_THROWS(c1->move(c1));
    CHECK_THROWS(c1->slash(c1));
    CHECK_NOTHROW(c1->slash(c2));

    Team t2(new YoungNinja("Shai", Point(20,20)));
    CHECK_NOTHROW(t2.add(new TrainedNinja("Sdc", Point(100,100))));
    CHECK_NOTHROW(t2.attack(&t1));
    CHECK_THROWS(t1.attack(&t1));
}