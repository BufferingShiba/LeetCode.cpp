#include "leetcode/problems/incremental-memory-leak.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_1860 {

class IncrementalMemoryLeakTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  IncrementalMemoryLeakSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  memory1 = 2, memory2 = 2
// Output: [3,1,0]
TEST_P(IncrementalMemoryLeakTest, OfficialExample1) {
  vector<int> expected = {3, 1, 0};
  vector<int> actual = solution.memLeak(2, 2);
  EXPECT_EQ(expected, actual);
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  memory1 = 8, memory2 = 11
// Output: [6,0,4]
TEST_P(IncrementalMemoryLeakTest, OfficialExample2) {
  vector<int> expected = {6, 0, 4};
  vector<int> actual = solution.memLeak(8, 11);
  EXPECT_EQ(expected, actual);
}

// ===== SelfAuthored Edge Case: both zeros =====
// First second requires 1 bit, crash immediately.
TEST_P(IncrementalMemoryLeakTest, EdgeCaseZeroMemory) {
  vector<int> expected = {1, 0, 0};
  vector<int> actual = solution.memLeak(0, 0);
  EXPECT_EQ(expected, actual);
}

// ===== SelfAuthored: crash at first second with only 1 bit available =====
TEST_P(IncrementalMemoryLeakTest, EdgeCaseOneBitAllocated) {
  vector<int> expected = {2, 0, 0};
  vector<int> actual = solution.memLeak(1, 0);
  EXPECT_EQ(expected, actual);
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, IncrementalMemoryLeakTest,
    ::testing::ValuesIn(IncrementalMemoryLeakSolution().getStrategyNames()));

}  // namespace problem_1860
}  // namespace leetcode
