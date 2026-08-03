#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/smallest-range-i.h"

namespace leetcode {
namespace problem_908 {
namespace {

class SmallestRangeITest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SmallestRangeISolution solution;
};

TEST_P(SmallestRangeITest, Example1) {
  std::vector<int> nums = {1};
  int k = 0;
  EXPECT_EQ(solution.smallestRangeI(nums, k), 0);
}

TEST_P(SmallestRangeITest, Example2) {
  std::vector<int> nums = {0, 10};
  int k = 2;
  EXPECT_EQ(solution.smallestRangeI(nums, k), 6);
}

TEST_P(SmallestRangeITest, Example3) {
  std::vector<int> nums = {1, 3, 6};
  int k = 3;
  EXPECT_EQ(solution.smallestRangeI(nums, k), 0);
}

TEST_P(SmallestRangeITest, SelfAuthoredAllSame) {
  std::vector<int> nums = {5, 5, 5};
  int k = 1;
  EXPECT_EQ(solution.smallestRangeI(nums, k), 0);
}

TEST_P(SmallestRangeITest, SelfAuthoredLargeK) {
  std::vector<int> nums = {0, 100};
  int k = 10000;
  EXPECT_EQ(solution.smallestRangeI(nums, k), 0);
}

INSTANTIATE_TEST_SUITE_P(
    SmallestRangeIStrategyTests, SmallestRangeITest,
    ::testing::ValuesIn(SmallestRangeISolution().getStrategyNames()));

}  // namespace
}  // namespace problem_908
}  // namespace leetcode
