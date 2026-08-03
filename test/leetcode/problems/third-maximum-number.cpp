#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/third-maximum-number.h"

namespace leetcode::problem_414 {

class ThirdMaximumNumberTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  ThirdMaximumNumberSolution solution_;
};

TEST_P(ThirdMaximumNumberTest, Example1) {
  std::vector<int> nums{3, 2, 1};
  EXPECT_EQ(solution_.thirdMax(nums), 1);
}

TEST_P(ThirdMaximumNumberTest, Example2) {
  std::vector<int> nums{1, 2};
  EXPECT_EQ(solution_.thirdMax(nums), 2);
}

TEST_P(ThirdMaximumNumberTest, Example3) {
  std::vector<int> nums{2, 2, 3, 1};
  EXPECT_EQ(solution_.thirdMax(nums), 1);
}

TEST_P(ThirdMaximumNumberTest, SelfAuthoredContainsIntMin) {
  std::vector<int> nums{1, 2, -2147483648};
  EXPECT_EQ(solution_.thirdMax(nums), -2147483648);
}

TEST_P(ThirdMaximumNumberTest, SelfAuthoredSingleElement) {
  std::vector<int> nums{5};
  EXPECT_EQ(solution_.thirdMax(nums), 5);
}

TEST_P(ThirdMaximumNumberTest, SelfAuthoredAllDuplicates) {
  std::vector<int> nums{1, 1, 1};
  EXPECT_EQ(solution_.thirdMax(nums), 1);
}

INSTANTIATE_TEST_SUITE_P(
    ThirdMaximumNumberTestSuite, ThirdMaximumNumberTest,
    ::testing::ValuesIn(ThirdMaximumNumberSolution().getStrategyNames()));

}  // namespace leetcode::problem_414
