#include "leetcode/problems/word-search.h"

#include <functional>
#include <unordered_map>

namespace leetcode {
namespace problem_79 {

namespace {
int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool dfs(vector<vector<char>>& board, int r, int c, int idx, const string& word) {
  if (idx == static_cast<int>(word.size())) return true;
  if (r < 0 || r >= static_cast<int>(board.size()) || c < 0 ||
      c >= static_cast<int>(board[0].size()) || board[r][c] != word[idx]) {
    return false;
  }
  char tmp = board[r][c];
  board[r][c] = '\0';  // mark visited
  for (auto& d : dirs) {
    if (dfs(board, r + d[0], c + d[1], idx + 1, word)) return true;
  }
  board[r][c] = tmp;
  return false;
}
}  // namespace

// DFS/backtracking: try each cell as a starting point, explore all 4 directions,
// marking visited cells by temporarily zeroing them out. Time O(m*n*4^L),
// space O(L) for recursion, where L = word length.
static bool solution1(vector<vector<char>>& board, string word) {
  int m = static_cast<int>(board.size());
  int n = static_cast<int>(board[0].size());

  // Early pruning: word longer than board cells -> impossible.
  if (static_cast<int>(word.size()) > m * n) return false;

  // Frequency-based pruning: if board lacks enough letters, impossible.
  unordered_map<char, int> charCount;
  for (auto& row : board)
    for (char ch : row) ++charCount[ch];
  for (char ch : word) {
    if (--charCount[ch] < 0) return false;
  }

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (board[i][j] == word[0] && dfs(board, i, j, 0, word)) return true;
    }
  }
  return false;
}

WordSearchSolution::WordSearchSolution() {
  setMetaInfo({
      .id = 79,
      .title = "Word Search",
      .url = "https://leetcode.com/problems/word-search"
  });
  registerStrategy(
      {
          .name = "Backtracking",
          .expected = "Accepted",
          .time_complexity = "O(m*n*4^L)",
          .space_complexity = "O(L)",
          .tags = {"Backtracking", "DFS", "Array"},
          .notes =
              "DFS from each starting cell, marking visited by zeroing cells.",
      },
      solution1);
}

bool WordSearchSolution::exist(vector<vector<char>>& board, string word) {
  return getSolution()(board, word);
}

}  // namespace problem_79
}  // namespace leetcode
