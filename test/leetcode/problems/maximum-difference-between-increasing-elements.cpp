#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/maximum-difference-between-increasing-elements.h"

namespace leetcode {
namespace problem_2016 {

class MaximumDifferenceBetweenIncreasingElementsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  MaximumDifferenceBetweenIncreasingElementsSolution solution;
};

TEST_P(MaximumDifferenceBetweenIncreasingElementsTest, Example1) {
  std::vector<int> nums = {7, 1, 5, 4};
  EXPECT_EQ(4, solution.maximumDifference(nums));
}

TEST_P(MaximumDifferenceBetweenIncreasingElementsTest, Example2) {
  std::vector<int> nums = {9, 4, 3, 2};
  EXPECT_EQ(-1, solution.maximumDifference(nums));
}

TEST_P(MaximumDifferenceBetweenIncreasingElementsTest, Example3) {
  std::vector<int> nums = {1, 5, 2, 10};
  EXPECT_EQ(9, solution.maximumDifference(nums));
}

INSTANTIATE_TEST_SUITE_P(
    MaximumDifferenceBetweenIncreasingElementsTestSuite,
    MaximumDifferenceBetweenIncreasingElementsTest,
    ::testing::ValuesIn(
        MaximumDifferenceBetweenIncreasingElementsSolution()
            .getStrategyNames()));

}  // namespace problem_2016
}  // namespace leetcode
