#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-x-value-of-array-i.h"

namespace leetcode::problem_3524 {

class FindXValueOfArrayITest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  FindXValueOfArrayISolution solution_;
};

TEST_P(FindXValueOfArrayITest, Example1) {
  std::vector<int> nums{1, 2, 3, 4, 5};
  const std::vector<long long> expected{9, 2, 4};
  EXPECT_EQ(solution_.resultArray(nums, 3), expected);
}

TEST_P(FindXValueOfArrayITest, Example2) {
  std::vector<int> nums{1, 2, 4, 8, 16, 32};
  const std::vector<long long> expected{18, 1, 2, 0};
  EXPECT_EQ(solution_.resultArray(nums, 4), expected);
}

TEST_P(FindXValueOfArrayITest, Example3) {
  std::vector<int> nums{1, 1, 2, 1, 1};
  const std::vector<long long> expected{9, 6};
  EXPECT_EQ(solution_.resultArray(nums, 2), expected);
}

TEST_P(FindXValueOfArrayITest, SelfAuthoredSingleElement) {
  std::vector<int> nums{7};
  // Only one subarray [7]; 7 % 5 == 2, so result[2]=1, rest 0.
  const std::vector<long long> expected{0, 0, 1, 0, 0};
  EXPECT_EQ(solution_.resultArray(nums, 5), expected);
}

TEST_P(FindXValueOfArrayITest, SelfAuthoredAllDivisibleByK) {
  std::vector<int> nums{3, 6, 9};
  // Every subarray product is a multiple of 3 => all residues are 0.
  const std::vector<long long> expected{6, 0, 0};
  EXPECT_EQ(solution_.resultArray(nums, 3), expected);
}

INSTANTIATE_TEST_SUITE_P(
    FindXValueOfArrayISolutionTests, FindXValueOfArrayITest,
    ::testing::ValuesIn(FindXValueOfArrayISolution().getStrategyNames()));

}  // namespace leetcode::problem_3524
