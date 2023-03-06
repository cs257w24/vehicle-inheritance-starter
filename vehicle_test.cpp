#include <sstream>
#include <iostream>

#include "gtest/gtest.h"
#include "person.h"
#include "vehicle.h"

const int kJalopyMiles = 500000;

TEST(Vehicle, TravelOneHour) {
    Person p("Crash dummy");
    Vehicle v(kJalopyMiles, 7);
    v.Go(p, 1, 7);
    ASSERT_EQ(kJalopyMiles + 7, v.GetMilesTraveled());
}

TEST(Vehicle, TravelZeroHours) {
    Person p("Crash dummy");
    Vehicle v(kJalopyMiles, 7);
    v.Go(p, 0, 5);
    ASSERT_EQ(kJalopyMiles, v.GetMilesTraveled());
}

TEST(Vehicle, TravelNegativeHours) {
    Person p("Crash dummy");
    Vehicle v(kJalopyMiles, 7);
    v.Go(p, -2, 5);
    ASSERT_EQ(kJalopyMiles, v.GetMilesTraveled());
}

TEST(Vehicle, TopSpeed) {
    Person p("Crash dummy");
    Vehicle v(0, 10);
    v.Go(p, 1, 11);
    ASSERT_EQ(10, v.GetMilesTraveled());
}

TEST(Vehicle, LongDrive) {
    Person p("Crash dummy");
    Vehicle v(0, 55);
    v.Go(p, 1000, 55);
    ASSERT_EQ(55000, v.GetMilesTraveled());
}

TEST(Vehicle, String) {
    Person p("Crash dummy");
    Vehicle v(kJalopyMiles, 7);
    std::stringstream expected;
    expected << "mileage: " << kJalopyMiles;

    std::stringstream actual;
    actual << v;
    ASSERT_EQ(expected.str(), actual.str());
}
