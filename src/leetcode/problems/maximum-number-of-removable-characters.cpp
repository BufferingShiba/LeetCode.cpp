#include "leetcode/problems/maximum-number-of-removable-characters.h"

#include <algorithm>

namespace leetcode {
namespace problem_1898 {

namespace {

bool maximumRemovalsImpl(const std::string& s, const std::string& p,
                         const std::vector<int>& removable, int k) {
  // Mark the first k removable indices as removed.
  std::vector<bool> removed(s.size(), false);
  for (int i = 0; i < k; ++i) {
    removed[removable[i]] = true;
  }

  // Greedy two-pointer matching of p as a subsequence of s.
  int pIdx = 0;
  for (int sIdx = 0; sIdx < static_cast<int>(s.size()) && pIdx < static_cast<int>(p.size());
       ++sIdx) {
    if (!removed[sIdx] && s[sIdx] == p[pIdx]) {
      ++pIdx;
    }
  }
  return pIdx == static_cast<int>(p.size());
}

int maximumRemovalsSolve(std::string s, std::string p,
                         std::vector<int>& removable) {
  // Binary search on k in [0, removable.size()].
  int lo = 0;
  int hi = static_cast<int>(removable.size());
  while (lo < hi) {
    int mid = lo + (hi - lo + 1) / 2;
    if (maximumRemovalsImpl(s, p, removable, mid)) {
      lo = mid;
    } else {
      hi = mid - 1;
    }
  }
  return lo;
}

}  // namespace

MaximumNumberOfRemovableCharactersSolution::MaximumNumberOfRemovableCharactersSolution() {
  // NOLINTBEGIN
  registerStrategy({
      .name = "binary-search-two-pointers",
      .expected = "Accepted",
      .time_complexity = "O(n log m) where n = s.size(), m = removable.size()",
      .space_complexity = "O(n)",
      .tags = {"Array", "Two Pointers", "String", "Binary Search"},
      .notes = "Binary search k; for each check greedily match p as a subsequence of s skipping removed indices.",
  }, maximumRemovalsSolve);
  // NOLINTEND
}

int MaximumNumberOfRemovableCharactersSolution::maximumRemovals(
    std::string s, std::string p, std::vector<int>& removable) {
  return getSolution()(std::move(s), std::move(p), removable);
}

}  // namespace problem_1898
}  // namespace leetcode
