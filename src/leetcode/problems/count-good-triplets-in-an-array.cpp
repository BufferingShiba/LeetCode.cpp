#include "leetcode/problems/count-good-triplets-in-an-array.h"

#include <vector>

namespace leetcode::problem_2179 {
namespace {

class BIT {
 public:
  explicit BIT(int n) : tree_(n + 1, 0) {}

  void update(int idx, int delta) {
    for (int i = idx; i < static_cast<int>(tree_.size()); i += i & (-i)) {
      tree_[i] += delta;
    }
  }

  int query(int idx) const {
    int res = 0;
    for (int i = idx; i > 0; i -= i & (-i)) {
      res += tree_[i];
    }
    return res;
  }

 private:
  std::vector<int> tree_;
};

long long countGoodTripletsIml(std::vector<int>& nums1,
                               std::vector<int>& nums2) {
  const int n = static_cast<int>(nums1.size());
  std::vector<int> pos(n);
  for (int i = 0; i < n; ++i) {
    pos[nums1[i]] = i;
  }
  std::vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    arr[i] = pos[nums2[i]] + 1;
  }

  std::vector<long long> leftLess(n, 0);
  BIT bit(n);
  for (int j = 0; j < n; ++j) {
    leftLess[j] = bit.query(arr[j] - 1);
    bit.update(arr[j], 1);
  }

  std::vector<long long> rightGreater(n, 0);
  BIT bit2(n);
  for (int j = n - 1; j >= 0; --j) {
    rightGreater[j] = (n - 1 - j) - bit2.query(arr[j]);
    bit2.update(arr[j], 1);
  }

  long long answer = 0;
  for (int j = 0; j < n; ++j) {
    answer += leftLess[j] * rightGreater[j];
  }
  return answer;
}

}  // namespace

CountGoodTripletsInAnArraySolution::CountGoodTripletsInAnArraySolution() {
  this->setMetaInfo({.id = 2179,
                     .title = "Count Good Triplets in an Array",
                     .url = "https://leetcode.com/problems/count-good-triplets-in-an-array/"});
  this->registerStrategy(
      {.name = "BinaryIndexedTree",
       .expected = "Accepted",
       .time_complexity = "O(n log n)",
       .space_complexity = "O(n)",
       .tags = {"Binary Indexed Tree", "Array"}},
      countGoodTripletsIml);
}

long long CountGoodTripletsInAnArraySolution::goodTriplets(
    std::vector<int>& nums1, std::vector<int>& nums2) {
  return getSolution()(nums1, nums2);
}

}  // namespace leetcode::problem_2179
