#include "leetcode/problems/count-the-hidden-sequences.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_2145 {

class CountTheHiddenSequencesTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CountTheHiddenSequencesSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  differences = [1,-3,4], lower = 1, upper = 6
// Output: 2
TEST_P(CountTheHiddenSequencesTest, OfficialExample1) {
  std::vector<int> differences = {1, -3, 4};
  int result = solution.numberOfArrays(differences, 1, 6);
  EXPECT_EQ(2, result);
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  differences = [3,-4,5,1,-2], lower = -4, upper = 5
// Output: 4
TEST_P(CountTheHiddenSequencesTest, OfficialExample2) {
  std::vector<int> differences = {3, -4, 5, 1, -2};
  int result = solution.numberOfArrays(differences, -4, 5);
  EXPECT_EQ(4, result);
}

// ===== Official Example 3 (from LeetCode) =====
// Input:  differences = [4,-7,2], lower = 3, upper = 6
// Output: 0
TEST_P(CountTheHiddenSequencesTest, OfficialExample3) {
  std::vector<int> differences = {4, -7, 2};
  int result = solution.numberOfArrays(differences, 3, 6);
  EXPECT_EQ(0, result);
}


INSTANTIATE_TEST_SUITE_P(
    LeetCode, CountTheHiddenSequencesTest,
    ::testing::ValuesIn(CountTheHiddenSequencesSolution().getStrategyNames()));

}  // namespace problem_2145
}  // namespace leetcode
