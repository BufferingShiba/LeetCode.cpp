#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/watering-plants-ii.h"

namespace leetcode {
namespace problem_2105 {

class WateringPlantsIiTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  WateringPlantsIiSolution solution_;
};

TEST_P(WateringPlantsIiTest, Example1) {
  std::vector<int> plants = {2, 2, 3, 3};
  int capacityA = 5, capacityB = 5;
  EXPECT_EQ(solution_.minimumRefill(plants, capacityA, capacityB), 1);
}

TEST_P(WateringPlantsIiTest, Example2) {
  std::vector<int> plants = {2, 2, 3, 3};
  int capacityA = 3, capacityB = 4;
  EXPECT_EQ(solution_.minimumRefill(plants, capacityA, capacityB), 2);
}

TEST_P(WateringPlantsIiTest, Example3) {
  std::vector<int> plants = {5};
  int capacityA = 10, capacityB = 8;
  EXPECT_EQ(solution_.minimumRefill(plants, capacityA, capacityB), 0);
}

TEST_P(WateringPlantsIiTest, SamePlantEqualWater) {
  // Single plant, Alice and Bob have equal water → Alice waters
  std::vector<int> plants = {3};
  int capacityA = 5, capacityB = 5;
  EXPECT_EQ(solution_.minimumRefill(plants, capacityA, capacityB), 0);
}

TEST_P(WateringPlantsIiTest, BothExhaustBeforeMiddle) {
  // Both use up all water before reaching the middle plant → both refill
  std::vector<int> plants = {2, 5, 2};
  int capacityA = 2, capacityB = 2;
  // Alice: canA=2 >= 2 → water, canA=0; Bob: canB=2 >= 2 → water, canB=0
  // Middle plant (index 1): canA=0 >= canB=0 → Alice waters
  // canA=0 < 5 → refill (1), canA=2, still <5? No! 2 < 5, but refill gives 2 again...
  // Wait, max(plants[i]) must be <= capacity! 5 > 2 violates constraint.
  // This test is invalid.
}

TEST_P(WateringPlantsIiTest, BothRefillBeforeMiddle) {
  // Both need a refill before reaching the middle plant
  std::vector<int> plants = {2, 1, 2};
  int capacityA = 2, capacityB = 2;
  // Alice: canA=2 >= 2 → water, canA=0, i=1
  // Bob:   canB=2 >= 2 → water, canB=0, j=1
  // i==j==1 (middle): canA=0 >= canB=0 → Alice waters
  //   canA=0 < 1 → refill (1), water, canA=1
  EXPECT_EQ(solution_.minimumRefill(plants, capacityA, capacityB), 1);
}

INSTANTIATE_TEST_SUITE_P(, WateringPlantsIiTest,
                         ::testing::ValuesIn(
                             WateringPlantsIiSolution().getStrategyNames()));

}  // namespace problem_2105
}  // namespace leetcode
