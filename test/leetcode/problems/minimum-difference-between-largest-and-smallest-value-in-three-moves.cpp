#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves.h"

namespace leetcode::problem_1509 {

template <typename T>
using TestWithParam = ::testing::TestWithParam<T>;

class MinimumDifferenceBetweenLargestAndSmallestValueInThreeMovesTest
    : public TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  MinimumDifferenceBetweenLargestAndSmallestValueInThreeMovesSolution solution_;
};

TEST_P(MinimumDifferenceBetweenLargestAndSmallestValueInThreeMovesTest, Example1) {
  std::vector<int> nums = {5, 3, 2, 4};
  EXPECT_EQ(0, solution_.minDifference(nums));
}

TEST_P(MinimumDifferenceBetweenLargestAndSmallestValueInThreeMovesTest, Example2) {
  std::vector<int> nums = {1, 5, 0, 10, 14};
  EXPECT_EQ(1, solution_.minDifference(nums));
}

TEST_P(MinimumDifferenceBetweenLargestAndSmallestValueInThreeMovesTest, Example3) {
  std::vector<int> nums = {3, 100, 20};
  EXPECT_EQ(0, solution_.minDifference(nums));
}

TEST_P(MinimumDifferenceBetweenLargestAndSmallestValueInThreeMovesTest, SingleElement) {
  std::vector<int> nums = {5};
  EXPECT_EQ(0, solution_.minDifference(nums));
}

TEST_P(MinimumDifferenceBetweenLargestAndSmallestValueInThreeMovesTest, FewElements) {
  std::vector<int> nums = {9, 48, 92, 4, 20, 19};
  EXPECT_EQ(11, solution_.minDifference(nums));
}

INSTANTIATE_TEST_SUITE_P(
    MinimumDifferenceBetweenLargestAndSmallestValueInThreeMovesTestSuite,
    MinimumDifferenceBetweenLargestAndSmallestValueInThreeMovesTest,
    ::testing::ValuesIn(
        MinimumDifferenceBetweenLargestAndSmallestValueInThreeMovesSolution()
            .getStrategyNames()));

}  // namespace leetcode::problem_1509
