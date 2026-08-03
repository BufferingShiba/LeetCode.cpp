#include <gtest/gtest.h>
#include "leetcode/problems/next-greater-element-iv.h"

namespace leetcode {
namespace problem_2454 {

class NextGreaterElementIvTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  NextGreaterElementIvSolution solution_;
};

TEST_P(NextGreaterElementIvTest, Example1) {
  std::vector<int> nums = {2, 4, 0, 9, 6};
  std::vector<int> expected = {9, 6, 6, -1, -1};
  EXPECT_EQ(solution_.secondGreaterElement(nums), expected);
}

TEST_P(NextGreaterElementIvTest, Example2) {
  std::vector<int> nums = {3, 3};
  std::vector<int> expected = {-1, -1};
  EXPECT_EQ(solution_.secondGreaterElement(nums), expected);
}

TEST_P(NextGreaterElementIvTest, SelfAuthoredDecreasing) {
  std::vector<int> nums = {5, 4, 3, 2, 1};
  std::vector<int> expected = {-1, -1, -1, -1, -1};
  EXPECT_EQ(solution_.secondGreaterElement(nums), expected);
}

TEST_P(NextGreaterElementIvTest, SelfAuthoredIncreasing) {
  std::vector<int> nums = {1, 2, 3, 4, 5};
  // 1: first=2, second=3; 2: first=3, second=4; 3: first=4, second=5; 4: first=5, second=-1; 5: -1
  std::vector<int> expected = {3, 4, 5, -1, -1};
  EXPECT_EQ(solution_.secondGreaterElement(nums), expected);
}

TEST_P(NextGreaterElementIvTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {7};
  std::vector<int> expected = {-1};
  EXPECT_EQ(solution_.secondGreaterElement(nums), expected);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, NextGreaterElementIvTest,
    ::testing::ValuesIn(NextGreaterElementIvSolution().getStrategyNames()));

}  // namespace problem_2454
}  // namespace leetcode
