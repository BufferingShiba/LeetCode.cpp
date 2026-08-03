#include "leetcode/problems/top-k-frequent-elements.h"

#include "gtest/gtest.h"

#include <algorithm>

namespace leetcode {
namespace problem_347 {

class TopKFrequentElementsTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  // Modeled on LeetCode's expectation: answer may be in any order,
  // so compare after sorting.
  void expectTopKFrequent(vector<int> nums, int k, vector<int> expected) {
    vector<int> result = solution.topKFrequent(nums, k);
    std::sort(result.begin(), result.end());
    std::sort(expected.begin(), expected.end());
    EXPECT_EQ(expected, result);
  }

  TopKFrequentElementsSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
TEST_P(TopKFrequentElementsTest, OfficialExample1) {
  expectTopKFrequent({1, 1, 1, 2, 2, 3}, 2, {1, 2});
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  nums = [1], k = 1
// Output: [1]
TEST_P(TopKFrequentElementsTest, OfficialExample2) {
  expectTopKFrequent({1}, 1, {1});
}

// ===== Official Example 3 (from LeetCode) =====
// Input:  nums = [1,2,1,2,1,2,3,1,3,2], k = 2
// Output: [1,2]
TEST_P(TopKFrequentElementsTest, OfficialExample3) {
  expectTopKFrequent({1, 2, 1, 2, 1, 2, 3, 1, 3, 2}, 2, {1, 2});
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, TopKFrequentElementsTest,
    ::testing::ValuesIn(TopKFrequentElementsSolution().getStrategyNames()));

}  // namespace problem_347
}  // namespace leetcode
