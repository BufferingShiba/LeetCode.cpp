#include "leetcode/problems/minimum-possible-integer-after-at-most-k-adjacent-swaps-on-digits.h"

#include <queue>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_1505 {

// Fenwick Tree (Binary Indexed Tree) for prefix sums.
class FenwickTree {
  std::vector<int> tree_;
  int n_;

 public:
  explicit FenwickTree(int n) : n_(n), tree_(n + 1, 0) {}

  void add(int idx, int delta) {
    for (++idx; idx <= n_; idx += idx & -idx) tree_[idx] += delta;
  }

  // Returns sum of [0, idx).
  int sum(int idx) const {
    int s = 0;
    for (; idx > 0; idx -= idx & -idx) s += tree_[idx];
    return s;
  }
};

static std::string minIntegerImpl(std::string num, int k) {
  int n = static_cast<int>(num.size());

  // Store original positions for each digit 0-9.
  std::vector<std::queue<int>> pos(10);
  for (int i = 0; i < n; ++i) {
    pos[num[i] - '0'].push(i);
  }

  FenwickTree bit(n);
  for (int i = 0; i < n; ++i) {
    bit.add(i, 1);  // each position initially occupied
  }

  std::string result;
  result.reserve(n);

  for (int i = 0; i < n; ++i) {
    // Greedily pick the smallest digit that can be brought to the front.
    for (int d = 0; d <= 9; ++d) {
      if (pos[d].empty()) continue;
      int originalPos = pos[d].front();
      // Number of not-yet-moved elements standing before originalPos.
      int cost = bit.sum(originalPos);
      if (cost <= k) {
        k -= cost;
        result.push_back(static_cast<char>('0' + d));
        bit.add(originalPos, -1);  // mark as moved
        pos[d].pop();
        break;
      }
    }
  }

  return result;
}

MinimumPossibleIntegerAfterAtMostKAdjacentSwapsOnDigitsSolution::
    MinimumPossibleIntegerAfterAtMostKAdjacentSwapsOnDigitsSolution() {
  setMetaInfo(
      {.id = 1505,
       .title = "Minimum Possible Integer After at Most K Adjacent Swaps On Digits",
       .url =
           "https://leetcode.com/problems/minimum-possible-integer-after-at-most-k-adjacent-swaps-on-digits/"});

  registerStrategy(
      {.name = "Greedy with Fenwick Tree",
       .expected = "Accepted",
       .time_complexity = "O(n log n)",
       .space_complexity = "O(n)",
       .tags = {"String", "Greedy", "Binary Indexed Tree"}},
      minIntegerImpl);
}

std::string
MinimumPossibleIntegerAfterAtMostKAdjacentSwapsOnDigitsSolution::minInteger(
    std::string num, int k) {
  return getSolution()(num, k);
}

}  // namespace problem_1505
}  // namespace leetcode
