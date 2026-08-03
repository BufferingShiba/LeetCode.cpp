#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-peak-element.h"

namespace leetcode::problem_162 {

class FindPeakElementTest
    : public ::testing::TestWithParam<std::string> {
 public:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

 protected:
  FindPeakElementSolution solution_;
};

TEST_P(FindPeakElementTest, Example1) {
  std::vector<int> nums{1, 2, 3, 1};
  int result = solution_.findPeakElement(nums);
  EXPECT_EQ(result, 2);
}

TEST_P(FindPeakElementTest, Example2) {
  std::vector<int> nums{1, 2, 1, 3, 5, 6, 4};
  int result = solution_.findPeakElement(nums);
  EXPECT_TRUE(result == 1 || result == 5);
}

TEST_P(FindPeakElementTest, SelfAuthoredSingleElement) {
  std::vector<int> nums{5};
  int result = solution_.findPeakElement(nums);
  EXPECT_EQ(result, 0);
}

TEST_P(FindPeakElementTest, SelfAuthoredStrictlyIncreasing) {
  std::vector<int> nums{1, 2, 3, 4, 5};
  int result = solution_.findPeakElement(nums);
  EXPECT_EQ(result, 4);
}

TEST_P(FindPeakElementTest, SelfAuthoredStrictlyDecreasing) {
  std::vector<int> nums{5, 4, 3, 2, 1};
  int result = solution_.findPeakElement(nums);
  EXPECT_EQ(result, 0);
}

TEST_P(FindPeakElementTest, SelfAuthoredTwoElementsAscending) {
  std::vector<int> nums{1, 2};
  int result = solution_.findPeakElement(nums);
  EXPECT_EQ(result, 1);
}

INSTANTIATE_TEST_SUITE_P(
    FindPeakElementTestSuite, FindPeakElementTest,
    ::testing::ValuesIn(FindPeakElementSolution().getStrategyNames()));

}  // namespace leetcode::problem_162
