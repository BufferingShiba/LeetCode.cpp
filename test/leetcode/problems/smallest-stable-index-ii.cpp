#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/smallest-stable-index-ii.h"

namespace leetcode::problem_3904 {

class SmallestStableIndexIiTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  SmallestStableIndexIiSolution solution;
};

TEST_P(SmallestStableIndexIiTest, Example1) {
  std::vector<int> nums{5, 0, 1, 4};
  int k = 3;
  EXPECT_EQ(solution.firstStableIndex(nums, k), 3);
}

TEST_P(SmallestStableIndexIiTest, Example2) {
  std::vector<int> nums{3, 2, 1};
  int k = 1;
  EXPECT_EQ(solution.firstStableIndex(nums, k), -1);
}

TEST_P(SmallestStableIndexIiTest, Example3) {
  std::vector<int> nums{0};
  int k = 0;
  EXPECT_EQ(solution.firstStableIndex(nums, k), 0);
}

TEST_P(SmallestStableIndexIiTest, SelfAuthoredAllStableAtZero) {
  std::vector<int> nums{7, 7, 7};
  int k = 0;
  EXPECT_EQ(solution.firstStableIndex(nums, k), 0);
}

INSTANTIATE_TEST_SUITE_P(
    SmallestStableIndexIiTestSuite,
    SmallestStableIndexIiTest,
    ::testing::ValuesIn(SmallestStableIndexIiSolution().getStrategyNames()));

}  // namespace leetcode::problem_3904
