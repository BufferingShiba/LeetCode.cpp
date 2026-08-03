#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/smallest-stable-index-i.h"

namespace leetcode {
namespace problem_3903 {

class SmallestStableIndexITest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  SmallestStableIndexISolution solution_;
};

TEST_P(SmallestStableIndexITest, Example1) {
  std::vector<int> nums = {5, 0, 1, 4};
  int k = 3;
  EXPECT_EQ(solution_.firstStableIndex(nums, k), 3);
}

TEST_P(SmallestStableIndexITest, Example2) {
  std::vector<int> nums = {3, 2, 1};
  int k = 1;
  EXPECT_EQ(solution_.firstStableIndex(nums, k), -1);
}

TEST_P(SmallestStableIndexITest, Example3) {
  std::vector<int> nums = {0};
  int k = 0;
  EXPECT_EQ(solution_.firstStableIndex(nums, k), 0);
}

TEST_P(SmallestStableIndexITest, SelfAuthoredSingleElementLargeK) {
  std::vector<int> nums = {7};
  int k = 10;
  EXPECT_EQ(solution_.firstStableIndex(nums, k), 0);
}

TEST_P(SmallestStableIndexITest, SelfAuthoredAllEqual) {
  std::vector<int> nums = {2, 2, 2, 2};
  int k = 0;
  EXPECT_EQ(solution_.firstStableIndex(nums, k), 0);
}

TEST_P(SmallestStableIndexITest, SelfAuthoredStableAtLastOnly) {
  std::vector<int> nums = {10, 1, 1, 9};
  int k = 1;
  EXPECT_EQ(solution_.firstStableIndex(nums, k), 3);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    SmallestStableIndexITest,
    testing::ValuesIn(SmallestStableIndexISolution().getStrategyNames()));

}  // namespace problem_3903
}  // namespace leetcode
