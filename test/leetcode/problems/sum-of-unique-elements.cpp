#include "leetcode/problems/sum-of-unique-elements.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_1748 {

class SumOfUniqueElementsTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SumOfUniqueElementsSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  nums = [1,2,3,2]
// Output: 4
TEST_P(SumOfUniqueElementsTest, OfficialExample1) {
  std::vector<int> nums = {1, 2, 3, 2};
  int r = solution.sumOfUnique(nums);
  EXPECT_EQ(4, r);
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  nums = [1,1,1,1,1]
// Output: 0
TEST_P(SumOfUniqueElementsTest, OfficialExample2) {
  std::vector<int> nums = {1, 1, 1, 1, 1};
  int r = solution.sumOfUnique(nums);
  EXPECT_EQ(0, r);
}

// ===== Official Example 3 (from LeetCode) =====
// Input:  nums = [1,2,3,4,5]
// Output: 15
TEST_P(SumOfUniqueElementsTest, OfficialExample3) {
  std::vector<int> nums = {1, 2, 3, 4, 5};
  int r = solution.sumOfUnique(nums);
  EXPECT_EQ(15, r);
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, SumOfUniqueElementsTest,
    ::testing::ValuesIn(SumOfUniqueElementsSolution().getStrategyNames()));

}  // namespace problem_1748
}  // namespace leetcode
