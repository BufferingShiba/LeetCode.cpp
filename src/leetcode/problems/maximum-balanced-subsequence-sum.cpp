#include "leetcode/problems/maximum-balanced-subsequence-sum.h"

#include <algorithm>
#include <utility>
#include <vector>

namespace leetcode::problem_2926 {
namespace {

// Fenwick tree (BIT) for prefix maximum queries.
class FenwickMax {
 public:
  explicit FenwickMax(int n) : bit_(n + 1, 0) {}

  void update(int i, long long val) {
    const int n = static_cast<int>(bit_.size()) - 1;
    for (; i <= n; i += i & (-i)) {
      bit_[i] = std::max(bit_[i], val);
    }
  }

  // Returns max over values with rank <= i (1-based rank in [1, n]).
  long long query(int i) const {
    long long res = 0;
    if (bit_.empty()) {
      return res;
    }
    const int n = static_cast<int>(bit_.size()) - 1;
    if (i > n) i = n;
    for (; i > 0; i -= i & (-i)) {
      res = std::max(res, bit_[i]);
    }
    return res;
  }

 private:
  std::vector<long long> bit_;
};

long long maxBalancedSubsequenceSumImpl(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  // b[i] = nums[i] - i. Balanced subsequence  <=>  b values non-decreasing.
  std::vector<long long> b(n);
  for (int i = 0; i < n; ++i) {
    b[i] = static_cast<long long>(nums[i]) - i;
  }

  // Coordinate compression of b values.
  std::vector<long long> sorted = b;
  std::sort(sorted.begin(), sorted.end());
  sorted.erase(std::unique(sorted.begin(), sorted.end()), sorted.end());

  FenwickMax bit(static_cast<int>(sorted.size()));
  long long answer = std::numeric_limits<long long>::min();

  for (int i = 0; i < n; ++i) {
    int rank = static_cast<int>(
                   std::lower_bound(sorted.begin(), sorted.end(), b[i]) -
                   sorted.begin()) +
               1;
    long long cur = static_cast<long long>(nums[i]) + bit.query(rank);
    answer = std::max(answer, cur);
    bit.update(rank, cur);
  }

  return answer;
}

}  // namespace

MaximumBalancedSubsequenceSumSolution::MaximumBalancedSubsequenceSumSolution() {
  setMetaInfo({.id = 2926,
               .title = "Maximum Balanced Subsequence Sum",
               .url = "https://leetcode.com/problems/maximum-balanced-subsequence-sum/"});
  registerStrategy({.name = "Fenwick-DP",
                    .expected = "Accepted",
                    .time_complexity = "O(n log n)",
                    .space_complexity = "O(n)",
                    .tags = {"Array", "Dynamic Programming", "Binary Indexed Tree", "Binary Search"}},
                   &maxBalancedSubsequenceSumImpl);
}

long long MaximumBalancedSubsequenceSumSolution::maxBalancedSubsequenceSum(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_2926
