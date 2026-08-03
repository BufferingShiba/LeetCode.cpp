#include "leetcode/problems/peaks-in-array.h"

namespace leetcode {
namespace problem_3187 {

namespace {

// Binary Indexed Tree for point update / range sum over 1-based indices.
class Fenwick {
 public:
  explicit Fenwick(int n) : n_(n), tree_(n + 1, 0) {}

  void add(int i, int delta) {
    for (; i <= n_; i += i & (-i)) tree_[i] += delta;
  }

  int rangeSum(int l, int r) const {  // inclusive on 1-based indices [l, r]
    if (l > r) return 0;
    int s0 = 0;
    for (int j = r; j > 0; j -= j & (-j)) s0 += tree_[j];
    int s1 = 0;
    for (int j = l - 1; j > 0; j -= j & (-j)) s1 += tree_[j];
    return s0 - s1;
  }

 private:
  int n_;
  std::vector<int> tree_;
};

bool isPeakAt(const vector<int>& nums, int i) {
  return i > 0 && i + 1 < (int)nums.size() &&
         nums[i] > nums[i - 1] && nums[i] > nums[i + 1];
}

vector<int> countOfPeaksImpl(vector<int>& nums, vector<vector<int>>& queries) {
  const int n = (int)nums.size();
  Fenwick bit(n);

  // Initialize BIT: position i (0-based, internal) is a global peak.
  for (int i = 1; i + 1 < n; ++i) {
    if (isPeakAt(nums, i)) bit.add(i + 1, 1);
  }

  std::vector<int> ans;
  for (const auto& q : queries) {
    if (q[0] == 1) {
      int l = q[1], r = q[2];
      // peaks strictly inside [l, r] => indices in [l+1, r-1] (0-based).
      // 1-based: [l+2, r].
      ans.push_back(bit.rangeSum(l + 2, r));
    } else {
      const int idx = q[1];
      const int val = q[2];

      // Positions whose global-peak status may be affected by changing nums[idx].
      std::vector<int> affected;
      for (int p = idx - 1; p <= idx + 1; ++p) {
        if (p >= 1 && p + 1 < n) affected.push_back(p);
      }

      // Remove old contributions.
      for (int p : affected) {
        if (isPeakAt(nums, p)) bit.add(p + 1, -1);
      }

      nums[idx] = val;

      // Add new contributions.
      for (int p : affected) {
        if (isPeakAt(nums, p)) bit.add(p + 1, 1);
      }
    }
  }
  return ans;
}

}  // namespace

PeaksInArraySolution::PeaksInArraySolution() {
  setMetaInfo({.id = 3187,
               .title = "Peaks in Array",
               .url = "https://leetcode.com/problems/peaks-in-array/"});

  registerStrategy(
      {"BinaryIndexedTree",
       "Accepted",
       "O((n + q) log n)",
       "O(n)",
       {"Array", "Binary Indexed Tree", "Segment Tree"},
       ""},
      countOfPeaksImpl);
}

vector<int> PeaksInArraySolution::countOfPeaks(vector<int>& nums,
                                               vector<vector<int>>& queries) {
  return getSolution()(nums, queries);
}

}  // namespace problem_3187
}  // namespace leetcode
