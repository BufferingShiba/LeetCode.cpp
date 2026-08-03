#include <gtest/gtest.h>

#include "leetcode/problems/find-the-highest-altitude.h"

namespace leetcode::problem_1732 {

class FindTheHighestAltitudeTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FindTheHighestAltitudeSolution solution;
};

TEST_P(FindTheHighestAltitudeTest, OfficialExample1) {
  std::vector<int> gain = {-5, 1, 5, 0, -7};
  EXPECT_EQ(solution.largestAltitude(gain), 1);
}

TEST_P(FindTheHighestAltitudeTest, OfficialExample2) {
  std::vector<int> gain = {-4, -3, -2, -1, 4, 3, 2};
  EXPECT_EQ(solution.largestAltitude(gain), 0);
}

TEST_P(FindTheHighestAltitudeTest, SelfAuthoredAllNegative) {
  std::vector<int> gain = {-1, -2, -3};
  EXPECT_EQ(solution.largestAltitude(gain), 0);
}

TEST_P(FindTheHighestAltitudeTest, SelfAuthoredAllPositive) {
  std::vector<int> gain = {1, 2, 3};
  EXPECT_EQ(solution.largestAltitude(gain), 6);
}

TEST_P(FindTheHighestAltitudeTest, SelfAuthoredSingleElement) {
  std::vector<int> gain = {5};
  EXPECT_EQ(solution.largestAltitude(gain), 5);
}

INSTANTIATE_TEST_SUITE_P(Strategies, FindTheHighestAltitudeTest,
                         testing::ValuesIn(FindTheHighestAltitudeSolution()
                                               .getStrategyNames()));

}  // namespace leetcode::problem_1732
