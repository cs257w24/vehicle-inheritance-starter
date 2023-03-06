#include "bike.h"
#include "person.h"

#include "gtest/gtest.h"

TEST(Bike, TwoWheels) {
  Person p("crash dummy");
  Bike b(0, 20);
  ASSERT_EQ(2, b.GetNumWheels());
}

TEST(Bike, BikeGoes) {
  Person p("crash dummy");
  Bike b(0, 20);
  b.Go(p, 1, 20);
  ASSERT_EQ(20, b.GetMilesTraveled());
}

TEST(Bike, BikeGoesLimit) {
  Person p("crash dummy");
  Bike b(0, 20);
  b.Go(p, 1, 21);
  ASSERT_EQ(20, b.GetMilesTraveled());
}
