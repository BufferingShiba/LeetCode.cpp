#include "leetcode/problems/subsets.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_78 {

class SubsetsTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SubsetsSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
TEST_P(SubsetsTest, OfficialExample1) {
  std::vector<int> nums = {1, 2, 3};
  std::vector<std::vector<int>> expected = {
      {}, {1}, {2}, {1, 2}, {3}, {1, 3}, {2, 3}, {1, 2, 3}};
  auto actual = solution.subsets(nums);
  auto sorted_actual = actual;
  auto sorted_expected = expected;
  for (auto& s : sorted_actual) std::sort(s.begin(), s.end());
  for (auto& s : sorted_expected) std::sort(s.begin(), s.end());
  std::sort(sorted_actual.begin(), sorted_actual.end());
  std::sort(sorted_expected.begin(), sorted_expected.end());
  EXPECT_EQ(sorted_expected, sorted_actual);
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  nums = [0]
// Output: [[],[0]]
TEST_P(SubsetsTest, OfficialExample2) {
  std::vector<int> nums = {0};
  std::vector<std::vector<int>> expected = {{}, {0}};
  auto actual = solution.subsets(nums);
  auto sorted_actual = actual;
  auto sorted_expected = expected;
  for (auto& s : sorted_actual) std::sort(s.begin(), s.end());
  for (auto& s : sorted_expected) std::sort(s.begin(), s.end());
  std::sort(sorted_actual.begin(), sorted_actual.end());
  std::sort(sorted_expected.begin(), sorted_expected.end());
  EXPECT_EQ(sorted_expected, sorted_actual);
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, SubsetsTest,
    ::testing::ValuesIn(SubsetsSolution().getStrategyNames()));

}  // namespace problem_78
}  // namespace leetcode
