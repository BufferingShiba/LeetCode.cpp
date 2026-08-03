#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/design-underground-system.h"

namespace problem_1396 {
namespace {

using SolutionClass = UndergroundSystem;

class DesignUndergroundSystemTest : public ::testing::TestWithParam<int> {
 protected:
  void SetUp() override { (void)GetParam(); }
};

TEST_P(DesignUndergroundSystemTest, Example1) {
  UndergroundSystem sys;
  sys.checkIn(45, "Leyton", 3);
  sys.checkIn(32, "Paradise", 8);
  sys.checkIn(27, "Leyton", 10);
  sys.checkOut(45, "Waterloo", 15);
  sys.checkOut(27, "Waterloo", 20);
  sys.checkOut(32, "Cambridge", 22);
  EXPECT_DOUBLE_EQ(14.0, sys.getAverageTime("Paradise", "Cambridge"));
  EXPECT_DOUBLE_EQ(11.0, sys.getAverageTime("Leyton", "Waterloo"));
  sys.checkIn(10, "Leyton", 24);
  EXPECT_DOUBLE_EQ(11.0, sys.getAverageTime("Leyton", "Waterloo"));
  sys.checkOut(10, "Waterloo", 38);
  EXPECT_DOUBLE_EQ(12.0, sys.getAverageTime("Leyton", "Waterloo"));
}

TEST_P(DesignUndergroundSystemTest, SelfAuthoredExample2) {
  UndergroundSystem sys;
  sys.checkIn(10, "Leyton", 3);
  sys.checkOut(10, "Paradise", 8);
  EXPECT_DOUBLE_EQ(5.0, sys.getAverageTime("Leyton", "Paradise"));
  sys.checkIn(5, "Leyton", 10);
  sys.checkOut(5, "Paradise", 16);
  EXPECT_DOUBLE_EQ(5.5, sys.getAverageTime("Leyton", "Paradise"));
  sys.checkIn(2, "Leyton", 21);
  sys.checkOut(2, "Paradise", 30);
  EXPECT_DOUBLE_EQ(6.666666666666667,
                  sys.getAverageTime("Leyton", "Paradise"));
}

TEST_P(DesignUndergroundSystemTest, SelfAuthoredSameStationRouteIsIndependent) {
  UndergroundSystem sys;
  // Leyton -> Water
  sys.checkIn(1, "Leyton", 10);
  sys.checkOut(1, "Water", 20);
  // Water -> Leyton (reverse direction, independent)
  sys.checkIn(2, "Water", 30);
  sys.checkOut(2, "Leyton", 50);
  EXPECT_DOUBLE_EQ(10.0, sys.getAverageTime("Leyton", "Water"));
  EXPECT_DOUBLE_EQ(20.0, sys.getAverageTime("Water", "Leyton"));
}

INSTANTIATE_TEST_SUITE_P(
    DesignUndergroundSystemTestSuite, DesignUndergroundSystemTest,
    ::testing::Values(0));

}  // namespace
}  // namespace problem_1396
