#include <gtest/gtest.h>

#include "leetcode/problems/minimum-difference-in-sums-after-removal-of-elements.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_2163 {

using leetcode::problem_2163::MinimumDifferenceInSumsAfterRemovalOfElementsSolution;

class MinimumDifferenceInSumsAfterRemovalOfElementsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }
  MinimumDifferenceInSumsAfterRemovalOfElementsSolution solution_;
};

TEST_P(MinimumDifferenceInSumsAfterRemovalOfElementsTest, Example1) {
  std::vector<int> nums{3, 1, 2};
  EXPECT_EQ(-1, solution_.minimumDifference(nums));
}

TEST_P(MinimumDifferenceInSumsAfterRemovalOfElementsTest, Example2) {
  std::vector<int> nums{7, 9, 5, 8, 1, 3};
  EXPECT_EQ(1, solution_.minimumDifference(nums));
}

TEST_P(MinimumDifferenceInSumsAfterRemovalOfElementsTest, SelfAuthoredSmall) {
  // nums = {1,2,3}, n = 1.
  // Remove 1 -> [2,3], first=[2], second=[3], diff = -1.
  // Remove 2 -> [1,3], first=[1], second=[3], diff = -2.
  // Remove 3 -> [1,2], first=[1], second=[2], diff = -1.
  // Minimum = -2.
  std::vector<int> nums{1, 2, 3};
  EXPECT_EQ(-2, solution_.minimumDifference(nums));
}

TEST_P(MinimumDifferenceInSumsAfterRemovalOfElementsTest, SelfAuthoredAscendingSix) {
  // nums = {1,2,3,4,5,6}, n = 2.
  // To minimise first - second, take smallest 2 as first and largest 2 as second.
  // Remove 2 middling elements; best: first={1,2}, second={5,6}, diff = 3 - 11 = -8.
  std::vector<int> nums{1, 2, 3, 4, 5, 6};
  EXPECT_EQ(-8, solution_.minimumDifference(nums));
}

INSTANTIATE_TEST_SUITE_P(
    MinimumDifferenceInSumsAfterRemovalOfElementsTests,
    MinimumDifferenceInSumsAfterRemovalOfElementsTest,
    ::testing::ValuesIn(
        MinimumDifferenceInSumsAfterRemovalOfElementsSolution().getStrategyNames()));

}  // namespace problem_2163
}  // namespace leetcode
