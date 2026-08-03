#include "leetcode/problems/count-substrings-that-satisfy-k-constraint-ii.h"

#include <algorithm>

namespace leetcode::problem_3261 {

namespace {

// For each left index i, find the maximal right endpoint R[i] such that the
// substring s[i..R[i]] satisfies the k-constraint (either zeros <= k or ones
// <= k). The array R is non-decreasing in i, which enables binary search per
// query over the split point between prefix-sum and arithmetic contributions.
std::vector<long long> countKConstraintSubstringsImpl(
    std::string s, int k, std::vector<std::vector<int>>& queries) {
  const int n = static_cast<int>(s.size());
  std::vector<int> right(n);
  std::vector<int> count(2, 0);

  int r = 0;
  for (int l = 0; l < n; ++l) {
    while (r < n) {
      // Need to know if adding s[r] keeps validity.
      const int bit = s[r] - '0';
      bool valid;
      if (count[bit] + 1 <= k) {
        valid = true;
      } else {
        // count[bit] + 1 > k, check the other side.
        valid = (count[1 - bit] <= k);
      }
      if (!valid) {
        break;
      }
      ++count[bit];
      ++r;
    }
    right[l] = r - 1;

    // Remove s[l] from window before advancing window's left pointer.
    --count[s[l] - '0'];
  }

  // cnt[i] = number of valid substrings starting at i (unbounded to the
  // right). prefix[i+1] = sum_{j=0}^{i} cnt[j].
  std::vector<long long> prefix(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    prefix[i + 1] = prefix[i] + (right[i] - i + 1);
  }

  std::vector<long long> answer;
  answer.reserve(queries.size());
  for (const auto& q : queries) {
    const int l = q[0];
    const int r = q[1];

    // Find smallest p in [l, r+1] such that right[p] >= r.
    int lo = l;
    int hi = r + 1;  // exclusive upper bound for the search range
    while (lo < hi) {
      const int mid = lo + (hi - lo) / 2;
      if (right[mid] >= r) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    }
    const int p = lo;  // first index with right[p] >= r, or r+1 if none

    long long ans = 0;
    // For i in [l, p-1]: right[i] < r, contribution = cnt[i].
    ans += prefix[p] - prefix[l];
    // For i in [p, r]: contribution = r - i + 1.
    if (p <= r) {
      const long long len = static_cast<long long>(r - p + 1);
      ans += len * (len + 1) / 2;
    }
    answer.push_back(ans);
  }
  return answer;
}

}  // namespace

CountSubstringsThatSatisfyKConstraintIiSolution::
    CountSubstringsThatSatisfyKConstraintIiSolution() {
  setMetaInfo({.id = 3261,
               .title = "Count Substrings That Satisfy K-Constraint II",
               .url = "https://leetcode.com/problems/count-substrings-that-satisfy-k-constraint-ii/"});
  registerStrategy(
      {.name = "SlideWindow+PrefixSum+BinarySearch",
       .expected = "Accepted",
       .time_complexity = "O(n + Q log n)",
       .space_complexity = "O(n)",
       .tags = {"Sliding Window", "Prefix Sum", "Binary Search"}},
      countKConstraintSubstringsImpl);
}

std::vector<long long> CountSubstringsThatSatisfyKConstraintIiSolution::
    countKConstraintSubstrings(std::string s, int k,
                               std::vector<std::vector<int>>& queries) {
  return getSolution()(std::move(s), k, queries);
}

}  // namespace leetcode::problem_3261
