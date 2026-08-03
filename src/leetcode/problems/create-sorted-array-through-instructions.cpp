#include "leetcode/problems/create-sorted-array-through-instructions.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_1649 {

namespace {

constexpr int kMod = 1'000'000'007;

class FenwickTree {
 public:
  explicit FenwickTree(int n) : tree_(n + 1, 0), n_(n) {}

  void add(int idx, int delta) {
    while (idx <= n_) {
      tree_[idx] += delta;
      idx += idx & -idx;
    }
  }

  int sum(int idx) const {
    int s = 0;
    while (idx > 0) {
      s += tree_[idx];
      idx -= idx & -idx;
    }
    return s;
  }

 private:
  std::vector<int> tree_;
  int n_;
};

int createSortedArrayImpl(std::vector<int>& instructions) {
  // Value range: [1, 100000]
  constexpr int kMaxVal = 100000;
  FenwickTree bit(kMaxVal);

  long long total_cost = 0;
  int total = 0;

  for (int x : instructions) {
    int less = bit.sum(x - 1);
    int greater = total - bit.sum(x);
    total_cost = (total_cost + std::min(less, greater)) % kMod;
    bit.add(x, 1);
    ++total;
  }

  return static_cast<int>(total_cost);
}

}  // namespace

CreateSortedArrayThroughInstructionsSolution::CreateSortedArrayThroughInstructionsSolution() {
  setMetaInfo({.id = 1649,
               .title = "Create Sorted Array through Instructions",
               .url = "https://leetcode.com/problems/create-sorted-array-through-instructions/"});

  registerStrategy(
      {.name = "Fenwick Tree",
       .expected = "Accepted",
       .time_complexity = "O(N log M)",
       .space_complexity = "O(M)",
       .tags = {"Array", "Binary Indexed Tree", "Divide and Conquer", "Merge Sort",
                "Ordered Set"}},
      createSortedArrayImpl);
}

int CreateSortedArrayThroughInstructionsSolution::createSortedArray(
    std::vector<int>& instructions) {
  return getSolution()(instructions);
}

}  // namespace problem_1649
}  // namespace leetcode
