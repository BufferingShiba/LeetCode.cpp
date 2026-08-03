#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/rings-and-rods.h"

namespace leetcode {
namespace problem_2103 {
namespace test {

class RingsAndRodsTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  RingsAndRodsSolution solution_;
};

TEST_P(RingsAndRodsTest, Example1) {
  EXPECT_EQ(solution_.countPoints("B0B6G0R6R0R6G9"), 1);
}

TEST_P(RingsAndRodsTest, Example2) {
  EXPECT_EQ(solution_.countPoints("B0R0G0R9R0B0G0"), 1);
}

TEST_P(RingsAndRodsTest, Example3) {
  EXPECT_EQ(solution_.countPoints("G4"), 0);
}

TEST_P(RingsAndRodsTest, SelfAuthoredAllColorsOnSameRod) {
  EXPECT_EQ(solution_.countPoints("R0G0B0"), 1);
}

TEST_P(RingsAndRodsTest, SelfAuthoredMissingColorOnAllRods) {
  EXPECT_EQ(solution_.countPoints("R1G2R3G4R5G6"), 0);
}

TEST_P(RingsAndRodsTest, SelfAuthoredAllTenRodsComplete) {
  std::string rings =
      "R0G0B0R1G1B1R2G2B2R3G3B3R4G4B4R5G5B5R6G6B6R7G7B7R8G8B8R9G9B9";
  EXPECT_EQ(solution_.countPoints(rings), 10);
}

INSTANTIATE_TEST_SUITE_P(
    RingsAndRodsStrategies, RingsAndRodsTest,
    ::testing::ValuesIn(RingsAndRodsSolution().getStrategyNames()));

}  // namespace test
}  // namespace problem_2103
}  // namespace leetcode
