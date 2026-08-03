#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/maximum-xor-with-an-element-from-array.h"

namespace leetcode {
namespace problem_1707 {

class MaximumXorWithAnElementFromArrayTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MaximumXorWithAnElementFromArraySolution solution_;
};

TEST_P(MaximumXorWithAnElementFromArrayTest, Example1) {
  std::vector<int> nums{0, 1, 2, 3, 4};
  std::vector<std::vector<int>> queries{{3, 1}, {1, 3}, {5, 6}};
  std::vector<int> expected{3, 3, 7};
  EXPECT_EQ(solution_.maximizeXor(nums, queries), expected);
}

TEST_P(MaximumXorWithAnElementFromArrayTest, Example2) {
  std::vector<int> nums{5, 2, 4, 6, 6, 3};
  std::vector<std::vector<int>> queries{{12, 4}, {8, 1}, {6, 3}};
  std::vector<int> expected{15, -1, 5};
  EXPECT_EQ(solution_.maximizeXor(nums, queries), expected);
}

TEST_P(MaximumXorWithAnElementFromArrayTest, SelfAuthoredSingleElement) {
  std::vector<int> nums{5};
  std::vector<std::vector<int>> queries{{3, 10}, {7, 2}, {8, 5}};
  // 5 <= 10: 3^5=6; 5<=2 false -> -1; 5<=5: 8^5=13
  std::vector<int> expected{6, -1, 13};
  EXPECT_EQ(solution_.maximizeXor(nums, queries), expected);
}

INSTANTIATE_TEST_SUITE_P(
    MaximumXorWithAnElementFromArrayTestSuite,
    MaximumXorWithAnElementFromArrayTest,
    ::testing::ValuesIn(
        MaximumXorWithAnElementFromArraySolution().getStrategyNames()));

}  // namespace problem_1707
}  // namespace leetcode
