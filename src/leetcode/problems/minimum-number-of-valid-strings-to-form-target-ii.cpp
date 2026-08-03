#include "leetcode/problems/minimum-number-of-valid-strings-to-form-target-ii.h"

#include <algorithm>

namespace leetcode {
namespace problem_3292 {

namespace {

std::vector<int> zFunction(const std::string& s) {
  int n = static_cast<int>(s.size());
  std::vector<int> z(n, 0);
  int l = 0, r = 0;
  for (int i = 1; i < n; ++i) {
    if (i <= r) {
      z[i] = std::min(r - i + 1, z[i - l]);
    }
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      ++z[i];
    }
    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }
  return z;
}

int minValidStringsImpl(std::vector<std::string>& words, std::string target) {
  int n = static_cast<int>(target.size());
  // L[i] = max prefix-match length between any word and target[i:].
  std::vector<int> L(n, 0);
  const char sep = '{';  // one past 'z', not in lowercase alphabet

  for (const std::string& w : words) {
    std::string s = w + sep + target;
    std::vector<int> z = zFunction(s);
    int base = static_cast<int>(w.size()) + 1;
    for (int k = 0; k < n; ++k) {
      if (z[base + k] > L[k]) {
        L[k] = z[base + k];
      }
    }
  }

  // Greedy min-jumps (jump game II). From position i we can reach [i+1, i+L[i]].
  int jumps = 0;
  int curEnd = 0;
  int farthest = 0;
  for (int i = 0; i < n; ++i) {
    farthest = std::max(farthest, i + L[i]);
    if (i == curEnd) {
      if (farthest <= i) {
        return -1;  // cannot make progress from this reachable zone
      }
      ++jumps;
      curEnd = farthest;
      if (curEnd >= n) {
        return jumps;
      }
    }
  }
  return -1;
}

}  // namespace

MinimumNumberOfValidStringsToFormTargetIiSolution::
    MinimumNumberOfValidStringsToFormTargetIiSolution() {
  setMetaInfo({3292,
               "Minimum Number of Valid Strings to Form Target II",
               "https://leetcode.com/problems/minimum-number-of-valid-strings-to-form-target-ii/"});
  registerStrategy(
      {.name = "Z-Algorithm + Greedy",
       .expected = "Accepted",
       .time_complexity = "O(sum|word| + |words| * |target|)",
       .space_complexity = "O(|target| + max|word|)",
       .tags = {"String", "Greedy", "Dynamic Programming"},
       .notes = "For each word, compute LCP with every target suffix via Z-algorithm; then greedy min-jumps on reachable intervals."},
      &minValidStringsImpl);
}

int MinimumNumberOfValidStringsToFormTargetIiSolution::minValidStrings(
    std::vector<std::string>& words, std::string target) {
  return getSolution()(words, std::move(target));
}

}  // namespace problem_3292
}  // namespace leetcode
