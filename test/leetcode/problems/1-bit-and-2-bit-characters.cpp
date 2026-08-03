#include "leetcode/problems/1-bit-and-2-bit-characters.h"

#include <string>
#include <vector>

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_717 {

class Problem1BitAnd2BitCharactersTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  Problem1BitAnd2BitCharactersSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  bits = [1,0,0]
// Output: true
TEST_P(Problem1BitAnd2BitCharactersTest, OfficialExample1) {
  std::vector<int> bits = {1, 0, 0};
  EXPECT_EQ(true, solution.isOneBitCharacter(bits));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  bits = [1,1,1,0]
// Output: false
TEST_P(Problem1BitAnd2BitCharactersTest, OfficialExample2) {
  std::vector<int> bits = {1, 1, 1, 0};
  EXPECT_EQ(false, solution.isOneBitCharacter(bits));
}

// ===== Edge: single 0-bit =====
// Input:  bits = [0]
// Output: true
TEST_P(Problem1BitAnd2BitCharactersTest, SingleZero) {
  std::vector<int> bits = {0};
  EXPECT_EQ(true, solution.isOneBitCharacter(bits));
}

// ===== Edge: [1,0] decodes as a single two-bit character =====
// Input:  bits = [1,0]
// Output: false
TEST_P(Problem1BitAnd2BitCharactersTest, OneThenZero) {
  std::vector<int> bits = {1, 0};
  EXPECT_EQ(false, solution.isOneBitCharacter(bits));
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, Problem1BitAnd2BitCharactersTest,
    ::testing::ValuesIn(Problem1BitAnd2BitCharactersSolution().getStrategyNames()));

}  // namespace problem_717
}  // namespace leetcode
