#include "leetcode/problems/form-array-by-concatenating-subarrays-of-another-array.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_1764 {

class FormArrayByConcatenatingSubarraysOfAnotherArrayTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FormArrayByConcatenatingSubarraysOfAnotherArraySolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  groups = [[1,-1,-1],[3,-2,0]], nums = [1,-1,0,1,-1,-1,3,-2,0]
// Output: true
TEST_P(FormArrayByConcatenatingSubarraysOfAnotherArrayTest, OfficialExample1) {
  std::vector<std::vector<int>> groups = {{1, -1, -1}, {3, -2, 0}};
  std::vector<int> nums = {1, -1, 0, 1, -1, -1, 3, -2, 0};
  EXPECT_EQ(true, solution.canChoose(groups, nums));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  groups = [[10,-2],[1,2,3,4]], nums = [7,7,1,2,3,4,10,-2]
// Output: false
TEST_P(FormArrayByConcatenatingSubarraysOfAnotherArrayTest, OfficialExample2) {
  std::vector<std::vector<int>> groups = {{10, -2}, {1, 2, 3, 4}};
  std::vector<int> nums = {1, 2, 3, 4, 10, -2};
  EXPECT_EQ(false, solution.canChoose(groups, nums));
}

// ===== Official Example 3 (from LeetCode) =====
// Input:  groups = [[1,2,3],[3,4]], nums = [7,7,1,2,3,4,7,7]
// Output: false
TEST_P(FormArrayByConcatenatingSubarraysOfAnotherArrayTest, OfficialExample3) {
  std::vector<std::vector<int>> groups = {{1, 2, 3}, {3, 4}};
  std::vector<int> nums = {7, 7, 1, 2, 3, 4, 7, 7};
  EXPECT_EQ(false, solution.canChoose(groups, nums));
}


INSTANTIATE_TEST_SUITE_P(
    LeetCode, FormArrayByConcatenatingSubarraysOfAnotherArrayTest,
    ::testing::ValuesIn(FormArrayByConcatenatingSubarraysOfAnotherArraySolution().getStrategyNames()));

}  // namespace problem_1764
}  // namespace leetcode
