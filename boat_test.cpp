#include "boat.h"
#include "person.h"

#include "gtest/gtest.h"

TEST(Boat, BrandNewMileage) {
  Boat b("Boaty McBoatface", 10, 5);
  ASSERT_EQ(10, b.GetMilesTraveled());
}

TEST(Boat, Name) {
    Boat b("Boaty McBoatface", 0, 10);
    ASSERT_EQ("Boaty McBoatface", b.GetName());
}

TEST(Boat, Rename) {
    Boat b("Boaty McBoatface", 0, 10);
    b.SetName("The SS Rum Runner");
    ASSERT_EQ("The SS Rum Runner", b.GetName());
}

TEST(Boat, BoatGoFast) {
    Boat b("Boaty McBoatface", 0, 30);
    Person p("Crash dummy");
    b.Go(p, 2, 30);
    ASSERT_EQ(60, b.GetMilesTraveled());
    b.Go(p, 2, 30);
    ASSERT_EQ(120, b.GetMilesTraveled());
}
