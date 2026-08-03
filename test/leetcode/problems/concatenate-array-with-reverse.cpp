#include <gtest/gtest.h>

#include "leetcode/problems/concatenate-array-with-reverse.h"

namespace leetcode::problem_3925 {

class ConcatenateArrayWithReverseTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  ConcatenateArrayWithReverseSolution solution_;
};

TEST_P(ConcatenateArrayWithReverseTest, Example1) {
  std::vector<int> nums = {1, 2, 3};
  std::vector<int> expected = {1, 2, 3, 3, 2, 1};
  EXPECT_EQ(solution_.concatWithReverse(nums), expected);
}

TEST_P(ConcatenateArrayWithReverseTest, Example2) {
  std::vector<int> nums = {1};
  std::vector<int> expected = {1, 1};
  EXPECT_EQ(solution_.concatWithReverse(nums), expected);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, ConcatenateArrayWithReverseTest,
    ::testing::ValuesIn(
        ConcatenateArrayWithReverseSolution().getStrategyNames()));

}  // namespace leetcode::problem_3925
