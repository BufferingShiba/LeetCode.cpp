#include "leetcode/problems/number-of-integers-with-popcount-depth-equal-to-k-ii.h"

#include <vector>

namespace leetcode {
namespace problem_3624 {

namespace {

int depthOf(long long x) {
  int d = 0;
  while (x != 1) {
    x = __builtin_popcountll(static_cast<unsigned long long>(x));
    ++d;
  }
  return d;
}

struct Fenwick {
  int n;
  std::vector<int> tree;

  explicit Fenwick(int n_) : n(n_), tree(n_ + 1, 0) {}

  void add(int idx, int delta) {  // 0-based idx
    for (int i = idx + 1; i <= n; i += i & (-i)) tree[i] += delta;
  }

  int prefix(int idx) const {  // sum over [0, idx)
    int s = 0;
    for (int i = idx; i > 0; i -= i & (-i)) s += tree[i];
    return s;
  }

  int range(int l, int r) const {  // 0-based inclusive
    return prefix(r + 1) - prefix(l);
  }
};

}  // namespace

std::vector<int> popcountDepthImpl(
    std::vector<long long>& nums,
    std::vector<std::vector<long long>>& queries) {
  const int n = static_cast<int>(nums.size());
  constexpr int kNumDepths = 6;  // depth in [0, 5]
  std::vector<Fenwick> bits;
  bits.reserve(kNumDepths);
  for (int i = 0; i < kNumDepths; ++i) bits.emplace_back(n);

  for (int j = 0; j < n; ++j) {
    bits[depthOf(nums[j])].add(j, 1);
  }

  std::vector<int> answer;
  for (const auto& q : queries) {
    if (q[0] == 1) {
      int l = static_cast<int>(q[1]);
      int r = static_cast<int>(q[2]);
      int k = static_cast<int>(q[3]);
      answer.push_back(bits[k].range(l, r));
    } else {
      int idx = static_cast<int>(q[1]);
      long long val = q[2];
      int oldDepth = depthOf(nums[idx]);
      int newDepth = depthOf(val);
      if (oldDepth != newDepth) {
        bits[oldDepth].add(idx, -1);
        bits[newDepth].add(idx, 1);
      }
      nums[idx] = val;
    }
  }
  return answer;
}

NumberOfIntegersWithPopcountDepthEqualToKIiSolution::
    NumberOfIntegersWithPopcountDepthEqualToKIiSolution() {
  setMetaInfo({.id = 3624,
               .title = "Number of Integers With Popcount-Depth Equal to K II",
               .url = "https://leetcode.com/problems/number-of-integers-with-popcount-depth-equal-to-k-ii/"});
  registerStrategy(
      {.name = "Fenwick",
       .expected = "Accepted",
       .time_complexity = "O((n + Q) * depth * log n) ~ O(Q log n)",
       .space_complexity = "O(n)",
       .tags = {"Binary Indexed Tree", "Segment Tree", "Divide and Conquer"}},
      popcountDepthImpl);
}

std::vector<int>
NumberOfIntegersWithPopcountDepthEqualToKIiSolution::popcountDepth(
    std::vector<long long>& nums,
    std::vector<std::vector<long long>>& queries) {
  return getSolution()(nums, queries);
}

}  // namespace problem_3624
}  // namespace leetcode
