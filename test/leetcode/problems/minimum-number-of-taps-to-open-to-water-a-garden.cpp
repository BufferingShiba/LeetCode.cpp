#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/minimum-number-of-taps-to-open-to-water-a-garden.h"

namespace leetcode {
namespace problem_1326 {

class MinimumNumberOfTapsToOpenToWaterAGardenTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumNumberOfTapsToOpenToWaterAGardenSolution solution;
};

TEST_P(MinimumNumberOfTapsToOpenToWaterAGardenTest, Example1) {
  int n = 5;
  std::vector<int> ranges{3, 4, 1, 1, 0, 0};
  EXPECT_EQ(1, solution.minTaps(n, ranges));
}

TEST_P(MinimumNumberOfTapsToOpenToWaterAGardenTest, Example2) {
  int n = 3;
  std::vector<int> ranges{0, 0, 0, 0};
  EXPECT_EQ(-1, solution.minTaps(n, ranges));
}

TEST_P(MinimumNumberOfTapsToOpenToWaterAGardenTest, SelfAuthoredSingleTapCoversAll) {
  int n = 1;
  std::vector<int> ranges{1, 1};
  EXPECT_EQ(1, solution.minTaps(n, ranges));
}

TEST_P(MinimumNumberOfTapsToOpenToWaterAGardenTest, SelfAuthoredGapUnreachable) {
  int n = 5;
  std::vector<int> ranges{1, 1, 0, 0, 1, 1};
  EXPECT_EQ(-1, solution.minTaps(n, ranges));
}

INSTANTIATE_TEST_SUITE_P(
    MinimumNumberOfTapsToOpenToWaterAGardenStrategies,
    MinimumNumberOfTapsToOpenToWaterAGardenTest,
    ::testing::ValuesIn(
        MinimumNumberOfTapsToOpenToWaterAGardenSolution().getStrategyNames()));

}  // namespace problem_1326
}  // namespace leetcode
