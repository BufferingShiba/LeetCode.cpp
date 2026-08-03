#include "leetcode/problems/maximum-elegance-of-a-k-length-subsequence.h"

#include <algorithm>
#include <functional>
#include <queue>
#include <unordered_set>
#include <vector>

namespace leetcode {
namespace problem_2813 {

namespace {

long long findMaximumEleganceImpl(std::vector<std::vector<int>>& items, int k) {
  int n = static_cast<int>(items.size());
  // Sort by profit descending so that the top-k are the most profitable items.
  std::sort(items.begin(), items.end(),
            [](const std::vector<int>& a, const std::vector<int>& b) {
              return a[0] > b[0];
            });

  // Pick the top-k items as the base selection.
  std::unordered_set<int> seen;
  long long total = 0;
  // Min-heap of profits of selected items whose category already appeared in the
  // selection (duplicate-category items that could be swapped out).
  std::priority_queue<int, std::vector<int>, std::greater<int>> dupHeap;
  for (int i = 0; i < k; ++i) {
    int profit = items[i][0];
    int cat = items[i][1];
    total += profit;
    if (!seen.insert(cat).second) {
      dupHeap.push(profit);
    }
  }

  // For categories not yet represented, keep their maximum-profit item (the
  // first occurrence in the tail of the sorted array) as a candidate to
  // introduce a brand new distinct category.
  std::vector<int> remainingHeads;
  std::unordered_set<int> seenTail;
  for (int i = k; i < n; ++i) {
    int cat = items[i][1];
    if (!seen.count(cat) && !seenTail.count(cat)) {
      remainingHeads.push_back(items[i][0]);
      seenTail.insert(cat);
    }
  }
  std::sort(remainingHeads.begin(), remainingHeads.end(), std::greater<int>());

  int distinct = static_cast<int>(seen.size());
  long long ans = total + 1LL * distinct * distinct;

  // Greedily swap the smallest duplicate-category item with the largest
  // unrepresented category head to grow the number of distinct categories.
  size_t r = 0;
  while (r < remainingHeads.size() && !dupHeap.empty()) {
    long long P = remainingHeads[r++];
    long long Q = dupHeap.top();
    dupHeap.pop();
    total = total - Q + P;
    ++distinct;
    long long cur = total + 1LL * distinct * distinct;
    if (cur > ans) ans = cur;
  }
  return ans;
}

}  // namespace

MaximumEleganceOfAKLengthSubsequenceSolution::
    MaximumEleganceOfAKLengthSubsequenceSolution() {
  setMetaInfo({
      2813,
      "Maximum Elegance of a K-Length Subsequence",
      "https://leetcode.com/problems/maximum-elegance-of-a-k-length-subsequence/",
  });
  registerStrategy(
      {
          "greedy-sort-heap",
          "Accepted",
          "O(n log n)",
          "O(n)",
          {"Array", "Hash Table", "Stack", "Greedy", "Sorting",
           "Heap (Priority Queue)"},
          "Pick top-k by profit, then swap duplicate-category items with the "
          "largest unrepresented category heads to grow distinct count.",
      },
      findMaximumEleganceImpl);
}

long long MaximumEleganceOfAKLengthSubsequenceSolution::findMaximumElegance(
    std::vector<std::vector<int>>& items, int k) {
  return getSolution()(items, k);
}

}  // namespace problem_2813
}  // namespace leetcode
