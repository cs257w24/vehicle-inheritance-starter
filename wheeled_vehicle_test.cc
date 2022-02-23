#include "wheeled_vehicle.h"

#include "gtest/gtest.h"

TEST(WheeledVehicle, NewTires) {
  WheeledVehicle wv(500, 25, 4);
  ASSERT_FALSE(wv.GetHasFlat());
}

TEST(WheeledVehicle, GoodTires) {
  Person p("crash dummy"); 
  WheeledVehicle wv(500, 25, 4);
  wv.Go(p, 4, 65);
  ASSERT_EQ(600, wv.GetMilesTraveled());
}

TEST(WheeledVehicle, ProblemTire) {
  Person p("crash dummy"); 
  WheeledVehicle wv(500, 25, 4);
  wv.PopTire();
  wv.Go(p, 4, 65);
  ASSERT_EQ(500, wv.GetMilesTraveled());
}

TEST(WheeledVehicle, FixFlat) {
  Person p("crash dummy"); 
  WheeledVehicle wv(500, 65, 4);
  wv.PopTire();
  wv.FixFlat();
  wv.Go(p, 4, 65);
  ASSERT_EQ(760, wv.GetMilesTraveled());
}
