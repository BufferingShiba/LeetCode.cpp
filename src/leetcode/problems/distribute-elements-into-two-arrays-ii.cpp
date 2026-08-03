#include "leetcode/problems/distribute-elements-into-two-arrays-ii.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_3072 {

namespace {

class Fenwick {
 public:
  explicit Fenwick(int n) : tree(n + 1, 0), n_(n) {}

  void update(int idx, int delta) {
    for (; idx <= n_; idx += idx & -idx) tree[idx] += delta;
  }

  // sum of [1..idx]
  int query(int idx) const {
    int sum = 0;
    for (; idx > 0; idx -= idx & -idx) sum += tree[idx];
    return sum;
  }

 private:
  std::vector<int> tree;
  int n_;
};

std::vector<int> resultArrayImpl(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());

  // Coordinate compression.
  std::vector<int> sorted = nums;
  std::sort(sorted.begin(), sorted.end());
  sorted.erase(std::unique(sorted.begin(), sorted.end()), sorted.end());
  int m = static_cast<int>(sorted.size());

  auto rank = [&](int val) {
    return static_cast<int>(
        std::lower_bound(sorted.begin(), sorted.end(), val) - sorted.begin()) +
        1;  // 1-indexed
  };

  Fenwick bit1(m), bit2(m);
  std::vector<int> arr1, arr2;

  // First two operations.
  arr1.push_back(nums[0]);
  bit1.update(rank(nums[0]), 1);
  arr2.push_back(nums[1]);
  bit2.update(rank(nums[1]), 1);

  for (int i = 2; i < n; ++i) {
    int r = rank(nums[i]);
    // greaterCount = total - count of <= val  (query(r) counts <= val)
    int g1 = static_cast<int>(arr1.size()) - bit1.query(r);
    int g2 = static_cast<int>(arr2.size()) - bit2.query(r);
    if (g1 > g2) {
      arr1.push_back(nums[i]);
      bit1.update(r, 1);
    } else if (g1 < g2) {
      arr2.push_back(nums[i]);
      bit2.update(r, 1);
    } else {
      if (arr1.size() <= arr2.size()) {
        arr1.push_back(nums[i]);
        bit1.update(r, 1);
      } else {
        arr2.push_back(nums[i]);
        bit2.update(r, 1);
      }
    }
  }

  arr1.insert(arr1.end(), arr2.begin(), arr2.end());
  return arr1;
}

}  // namespace

DistributeElementsIntoTwoArraysIiSolution::DistributeElementsIntoTwoArraysIiSolution() {
  setMetaInfo(
      {.id = 3072,
       .title = "Distribute Elements Into Two Arrays II",
       .url =
           "https://leetcode.com/problems/distribute-elements-into-two-arrays-ii/"});
  registerStrategy(
      {.name = "FenwickTree",
       .expected = "Accepted",
       .time_complexity = "O(n log n)",
       .space_complexity = "O(n)",
       .tags = {"Binary Indexed Tree", "Coordinate Compression"}},
      resultArrayImpl);
}

std::vector<int> DistributeElementsIntoTwoArraysIiSolution::resultArray(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3072
}  // namespace leetcode
