#include "leetcode/problems/bag-of-tokens.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_948 {

class BagOfTokensTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  BagOfTokensSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  tokens = [100], power = 50
// Output: 0
TEST_P(BagOfTokensTest, OfficialExample1) {
  vector<int> tokens = {100};
  int power = 50;
  int result = solution.bagOfTokensScore(tokens, power);
  EXPECT_EQ(0, result);
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  tokens = [200,100], power = 150
// Output: 1
TEST_P(BagOfTokensTest, OfficialExample2) {
  vector<int> tokens = {200, 100};
  int power = 150;
  int result = solution.bagOfTokensScore(tokens, power);
  EXPECT_EQ(1, result);
}

// ===== Official Example 3 (from LeetCode) =====
// Input:  tokens = [100,200,300,400], power = 200
// Output: 2
TEST_P(BagOfTokensTest, OfficialExample3) {
  vector<int> tokens = {100, 200, 300, 400};
  int power = 200;
  int result = solution.bagOfTokensScore(tokens, power);
  EXPECT_EQ(2, result);
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, BagOfTokensTest,
    ::testing::ValuesIn(BagOfTokensSolution().getStrategyNames()));

}  // namespace problem_948
}  // namespace leetcode
