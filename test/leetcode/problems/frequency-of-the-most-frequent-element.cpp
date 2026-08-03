#include "leetcode/problems/frequency-of-the-most-frequent-element.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_1838 {

class FrequencyOfTheMostFrequentElementTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FrequencyOfTheMostFrequentElementSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  nums = [1,2,4], k = 5
// Output: 3
TEST_P(FrequencyOfTheMostFrequentElementTest, OfficialExample1) {
  vector<int> nums = {1, 2, 4};
  EXPECT_EQ(3, solution.maxFrequency(nums, 5));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  nums = [1,4,8,13], k = 5
// Output: 2
TEST_P(FrequencyOfTheMostFrequentElementTest, OfficialExample2) {
  vector<int> nums = {1, 4, 8, 13};
  EXPECT_EQ(2, solution.maxFrequency(nums, 5));
}

// ===== Official Example 3 (from LeetCode) =====
// Input:  nums = [3,9,6], k = 2
// Output: 1
TEST_P(FrequencyOfTheMostFrequentElementTest, OfficialExample3) {
  vector<int> nums = {3, 9, 6};
  EXPECT_EQ(1, solution.maxFrequency(nums, 2));
}

// ===== Edge Case: single element =====
TEST_P(FrequencyOfTheMostFrequentElementTest, EdgeCaseSingleElement) {
  vector<int> nums = {1};
  EXPECT_EQ(1, solution.maxFrequency(nums, 100));
}

// ===== Edge Case: all elements already equal, no cost needed =====
TEST_P(FrequencyOfTheMostFrequentElementTest, EdgeCaseAllEqual) {
  vector<int> nums = {5, 5, 5, 5};
  EXPECT_EQ(4, solution.maxFrequency(nums, 1));
}


INSTANTIATE_TEST_SUITE_P(
    LeetCode, FrequencyOfTheMostFrequentElementTest,
    ::testing::ValuesIn(FrequencyOfTheMostFrequentElementSolution().getStrategyNames()));

}  // namespace problem_1838
}  // namespace leetcode
