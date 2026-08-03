#include "leetcode/problems/verbal-arithmetic-puzzle.h"

#include <algorithm>
#include <cstring>
#include <unordered_set>
#include <vector>

namespace leetcode {
namespace problem_1307 {

// ----------------------------------------------------------------
// Column-wise DFS solver
// ----------------------------------------------------------------
static bool dfs(int col, int row, int sum,
                const std::vector<std::string>& words,
                const std::string& result,
                int char_to_digit[26],
                bool used[10],
                const bool is_leading[26]) {
  // All columns done: no carry allowed
  int max_cols = (int)result.size();
  if (col == max_cols) {
    return sum == 0;
  }

  int word_count = (int)words.size();

  if (row < word_count) {
    // Process a word row in the current column
    const std::string& word = words[row];
    int wlen = (int)word.size();
    // col is 0-indexed from rightmost (units)
    if (col >= wlen) {
      // This word has no digit in this column; contribute 0
      return dfs(col, row + 1, sum, words, result,
                 char_to_digit, used, is_leading);
    }

    char ch = word[wlen - 1 - col];
    int idx = ch - 'A';

    if (char_to_digit[idx] != -1) {
      // Already assigned
      return dfs(col, row + 1, sum + char_to_digit[idx],
                 words, result, char_to_digit, used, is_leading);
    }

    // Not assigned yet: try all possibilities
    int start = (is_leading[idx] ? 1 : 0);
    for (int d = start; d <= 9; ++d) {
      if (used[d]) continue;
      used[d] = true;
      char_to_digit[idx] = d;
      if (dfs(col, row + 1, sum + d, words, result,
              char_to_digit, used, is_leading)) {
        return true;
      }
      char_to_digit[idx] = -1;
      used[d] = false;
    }
    return false;

  } else {
    // Process the result row in the current column
    char ch = result[result.size() - 1 - col];
    int idx = ch - 'A';
    int digit = sum % 10;

    if (char_to_digit[idx] != -1) {
      // Already assigned – must match
      if (char_to_digit[idx] != digit) return false;
      return dfs(col + 1, 0, sum / 10, words, result,
                 char_to_digit, used, is_leading);
    }

    // Not assigned: must use 'digit' if available
    if (used[digit]) return false;
    // Leading-zero check for result's most-significant digit
    if (is_leading[idx] && digit == 0) return false;

    used[digit] = true;
    char_to_digit[idx] = digit;
    if (dfs(col + 1, 0, sum / 10, words, result,
            char_to_digit, used, is_leading)) {
      return true;
    }
    char_to_digit[idx] = -1;
    used[digit] = false;
    return false;
  }
}

static bool isSolvableImpl(std::vector<std::string>& words,
                           std::string result) {
  // Collect unique characters
  bool seen[26] = {false};
  bool is_leading[26] = {false};

  for (const auto& w : words) {
    if (!w.empty()) {
      int idx = w[0] - 'A';
      is_leading[idx] = true;
    }
    for (char ch : w) {
      seen[ch - 'A'] = true;
    }
  }
  if (!result.empty()) {
    int idx = result[0] - 'A';
    is_leading[idx] = true;
  }
  for (char ch : result) {
    seen[ch - 'A'] = true;
  }

  int distinct = 0;
  for (int i = 0; i < 26; ++i) {
    if (seen[i]) ++distinct;
  }
  if (distinct > 10) return false;  // impossible

  int char_to_digit[26];
  std::fill(std::begin(char_to_digit), std::end(char_to_digit), -1);
  bool used[10] = {false};

  return dfs(0, 0, 0, words, result, char_to_digit, used, is_leading);
}

// ----------------------------------------------------------------
// Solution class
// ----------------------------------------------------------------
VerbalArithmeticPuzzleSolution::VerbalArithmeticPuzzleSolution() {
  setMetaInfo({.id = 1307,
               .title = "Verbal Arithmetic Puzzle",
               .url = "https://leetcode.com/problems/verbal-arithmetic-puzzle/"});

  registerStrategy(
      {.name = "Column-wise DFS",
       .expected = "Accepted",
       .time_complexity = "O(10^K)",
       .space_complexity = "O(K)",
       .tags = {"Array", "Math", "String", "Backtracking"}},
      isSolvableImpl);
}

bool VerbalArithmeticPuzzleSolution::isSolvable(
    std::vector<std::string>& words, std::string result) {
  return getSolution()(words, result);
}

}  // namespace problem_1307
}  // namespace leetcode
