#include "leetcode/problems/word-search.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_79 {

class WordSearchTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  WordSearchSolution solution;
};

INSTANTIATE_TEST_SUITE_P(
    LeetCode, WordSearchTest,
    ::testing::ValuesIn(WordSearchSolution().getStrategyNames()));

// ===== Official Example 1 (from LeetCode) =====
// Input:  board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// Output: true
TEST_P(WordSearchTest, OfficialExample1) {
  vector<vector<char>> board = {{'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}};
  string word = "ABCCED";
  EXPECT_EQ(true, solution.exist(board, word));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
// Output: true
TEST_P(WordSearchTest, OfficialExample2) {
  vector<vector<char>> board = {{'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}};
  string word = "SEE";
  EXPECT_EQ(true, solution.exist(board, word));
}

// ===== Official Example 3 (from LeetCode) =====
// Input:  board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
// Output: false
TEST_P(WordSearchTest, OfficialExample3) {
  vector<vector<char>> board = {{'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}};
  string word = "ABCB";
  EXPECT_EQ(false, solution.exist(board, word));
}

}  // namespace problem_79
}  // namespace leetcode
