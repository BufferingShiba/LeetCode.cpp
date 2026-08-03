#include "leetcode/problems/valid-binary-strings-with-cost-limit.h"

namespace leetcode {
namespace problem_3955 {

namespace {

void backtrack(int pos, int n, int k, long long cost,
               std::string& cur, std::vector<std::string>& result) {
  if (pos == n) {
    result.push_back(cur);
    return;
  }

  // Place '1' at pos: costs pos, and previous must not be '1'.
  if (pos == 0 || cur[pos - 1] != '1') {
    if (cost + pos <= k) {
      cur.push_back('1');
      backtrack(pos + 1, n, k, cost + pos, cur, result);
      cur.pop_back();
    }
  }

  // Place '0' at pos.
  cur.push_back('0');
  backtrack(pos + 1, n, k, cost, cur, result);
  cur.pop_back();
}

std::vector<std::string> generateValidStringsImpl(int n, int k) {
  std::vector<std::string> result;
  std::string cur;
  cur.reserve(n);
  backtrack(0, n, k, 0, cur, result);
  return result;
}

}  // namespace

ValidBinaryStringsWithCostLimit::ValidBinaryStringsWithCostLimit() {
  setMetaInfo({.id = 3955,
               .title = "Valid Binary Strings With Cost Limit",
               .url = "https://leetcode.com/problems/valid-binary-strings-with-cost-limit/"});

  registerStrategy(
      {.name = "backtracking-pruned",
       .expected = "Accepted",
       .time_complexity = "O(2^n)",
       .space_complexity = "O(n)",
       .tags = {"Backtracking", "String"}},
      generateValidStringsImpl);
}

std::vector<std::string> ValidBinaryStringsWithCostLimit::generateValidStrings(
    int n, int k) {
  return getSolution()(n, k);
}

}  // namespace problem_3955
}  // namespace leetcode
