#include <string>

#include "leetcode/problems/find-the-punishment-number-of-an-integer.h"

namespace leetcode {
namespace problem_2698 {
namespace {

// Returns true if the decimal string can be partitioned into contiguous
// substrings whose integer values sum to target.
bool canPartition(const std::string& s, int pos, int target) {
  if (pos == static_cast<int>(s.size())) {
    return target == 0;
  }
  int cur = 0;
  for (int i = pos; i < static_cast<int>(s.size()); ++i) {
    cur = cur * 10 + (s[i] - '0');
    if (cur > target) {
      break;
    }
    if (canPartition(s, i + 1, target - cur)) {
      return true;
    }
  }
  return false;
}

// Returns true if i is a valid candidate: the square's decimal string can be
// partitioned into substrings summing exactly to i.
bool isValid(int i) {
  const std::string s = std::to_string(i * i);
  return canPartition(s, 0, i);
}

int punishmentNumberImpl(int n) {
  int total = 0;
  for (int i = 1; i <= n; ++i) {
    if (isValid(i)) {
      total += i * i;
    }
  }
  return total;
}

}  // namespace

FindThePunishmentNumberOfAnIntegerSolution::FindThePunishmentNumberOfAnIntegerSolution() {
  setMetaInfo({.id = 2698,
               .title = "Find the Punishment Number of an Integer",
               .url = "https://leetcode.com/problems/find-the-punishment-number-of-an-integer/"});
  registerStrategy(
      {.name = "Backtracking",
       .expected = "Accepted",
       .time_complexity = "O(n * 2^len), len <= 7 digits of i*i",
       .space_complexity = "O(len)",
       .tags = {"Math", "Backtracking"}},
      punishmentNumberImpl);
}

int FindThePunishmentNumberOfAnIntegerSolution::punishmentNumber(int n) {
  return getSolution()(n);
}

}  // namespace problem_2698
}  // namespace leetcode
