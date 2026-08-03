#include "leetcode/problems/find-the-k-sum-of-an-array.h"

#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

namespace leetcode {
namespace problem_2386 {

long long FindTheKSumOfAnArraySolution::solveKSum(std::vector<int>& nums, int k) {
  long long base = 0;
  std::vector<long long> a;
  a.reserve(nums.size());
  for (int x : nums) {
    if (x > 0) {
      base += x;
      a.push_back(x);
    } else {
      a.push_back(-static_cast<long long>(x));
    }
  }
  std::sort(a.begin(), a.end());

  const int n = static_cast<int>(a.size());

  // Min-heap of (subsetSum, lastTakenIndex).
  // 0 (empty subset) is the 1st smallest subset sum.
  using Node = std::pair<long long, int>;
  auto cmp = [](const Node& x, const Node& y) { return x.first > y.first; };
  std::priority_queue<Node, std::vector<Node>, decltype(cmp)> pq(cmp);

  if (n > 0) {
    pq.push({a[0], 0});
  }

  // We need the k-th smallest subset sum. The empty subset (0) is the 1st.
  long long kthSubsetSum = 0;
  int remaining = k - 1;  // already consumed the empty subset
  while (remaining-- > 0 && n > 0) {
    auto [s, idx] = pq.top();
    pq.pop();
    kthSubsetSum = s;
    if (idx + 1 < n) {
      pq.push({s + a[idx + 1], idx + 1});
      pq.push({s - a[idx] + a[idx + 1], idx + 1});
    }
  }

  return base - kthSubsetSum;
}

}  // namespace problem_2386
}  // namespace leetcode
