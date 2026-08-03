#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/special-array-ii.h"

namespace leetcode::problem_3152 {

class SpecialArrayIiTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SpecialArrayIiSolution solution;
};

TEST_P(SpecialArrayIiTest, Example1) {
  std::vector<int> nums{3, 4, 1, 2, 6};
  std::vector<std::vector<int>> queries{{0, 4}};
  std::vector<bool> expected{false};
  EXPECT_EQ(solution.isArraySpecial(nums, queries), expected);
}

TEST_P(SpecialArrayIiTest, Example2) {
  std::vector<int> nums{4, 3, 1, 6};
  std::vector<std::vector<int>> queries{{0, 2}, {2, 3}};
  std::vector<bool> expected{false, true};
  EXPECT_EQ(solution.isArraySpecial(nums, queries), expected);
}

TEST_P(SpecialArrayIiTest, SelfAuthoredSingleElementAlwaysSpecial) {
  std::vector<int> nums{7};
  std::vector<std::vector<int>> queries{{0, 0}};
  std::vector<bool> expected{true};
  EXPECT_EQ(solution.isArraySpecial(nums, queries), expected);
}

TEST_P(SpecialArrayIiTest, SelfAuthoredAlternatingFullArray) {
  std::vector<int> nums{1, 2, 3, 4, 5};
  std::vector<std::vector<int>> queries{{0, 4}};
  std::vector<bool> expected{true};
  EXPECT_EQ(solution.isArraySpecial(nums, queries), expected);
}

INSTANTIATE_TEST_SUITE_P(
    SpecialArrayIiTestSuite, SpecialArrayIiTest,
    ::testing::ValuesIn(SpecialArrayIiSolution().getStrategyNames()));

}  // namespace leetcode::problem_3152
