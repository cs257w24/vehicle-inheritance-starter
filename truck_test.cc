#include "truck.h"

#include "gtest/gtest.h"
#include "person.h"

TEST(Truck, FourWheels) {
  Truck t(0, 20);
  ASSERT_EQ(4, t.GetNumWheels());
}

TEST(Truck, CapHours1) {
  Person p("crash dummy");
  Truck t(0, 55);
  t.Go(p, Truck::kMaxDrivingHours, 55);
  int miles = t.GetMilesTraveled();
  t.Go(p, 1, 25);
  ASSERT_EQ(miles, t.GetMilesTraveled());
}

TEST(Truck, CapHours2) {
  Person p("crash dummy");
  Truck t(0, 55);
  t.Go(p, Truck::kMaxDrivingHours + 1, 55);
  int miles = t.GetMilesTraveled();
  t.Go(p, 1, 55);
  ASSERT_EQ(miles, Truck::kMaxDrivingHours * 55);
}

TEST(Truck, UnderCap) {
  Person p("crash dummy");
  Truck t(0, 55);
  t.Go(p, 1, 55);
  int miles = t.GetMilesTraveled();
  t.Go(p, 1, 55);
  ASSERT_EQ(miles, 55);
}
