#include "leetcode/problems/online-majority-element-in-subarray.h"

#include <algorithm>

namespace leetcode {
namespace problem_1157 {

MajorityChecker::MajorityChecker(const std::vector<int>& arr)
    : n_(static_cast<int>(arr.size())), arr_(arr) {
  for (int i = 0; i < n_; ++i) {
    pos_[arr_[i]].push_back(i);
  }
  tree_.resize(4 * (n_ + 1), {0, 0});
  if (n_ > 0) {
    build(1, 0, n_ - 1);
  }
}

std::pair<int, int> MajorityChecker::merge_(
    const std::pair<int, int>& a, const std::pair<int, int>& b) {
  if (a.first == b.first) {
    return {a.first, a.second + b.second};
  }
  if (a.second >= b.second) {
    return {a.first, a.second - b.second};
  }
  return {b.first, b.second - a.second};
}

void MajorityChecker::build(int node, int l, int r) {
  if (l == r) {
    tree_[node] = {arr_[l], 1};
    return;
  }
  int mid = (l + r) / 2;
  build(node * 2, l, mid);
  build(node * 2 + 1, mid + 1, r);
  tree_[node] = merge_(tree_[node * 2], tree_[node * 2 + 1]);
}

std::pair<int, int> MajorityChecker::rangeQuery(int node, int l, int r, int ql,
                                                int qr) {
  if (ql <= l && r <= qr) {
    return tree_[node];
  }
  int mid = (l + r) / 2;
  if (qr <= mid) {
    return rangeQuery(node * 2, l, mid, ql, qr);
  }
  if (ql > mid) {
    return rangeQuery(node * 2 + 1, mid + 1, r, ql, qr);
  }
  return merge_(rangeQuery(node * 2, l, mid, ql, qr),
                rangeQuery(node * 2 + 1, mid + 1, r, ql, qr));
}

int MajorityChecker::countInRange(int value, int l, int r) const {
  auto it = pos_.find(value);
  if (it == pos_.end()) {
    return 0;
  }
  const std::vector<int>& v = it->second;
  return static_cast<int>(std::upper_bound(v.begin(), v.end(), r) -
                          std::lower_bound(v.begin(), v.end(), l));
}

int MajorityChecker::query(int left, int right, int threshold) {
  std::pair<int, int> cand =
      rangeQuery(1, 0, n_ - 1, left, right);
  if (cand.first == 0) {
    return -1;
  }
  if (countInRange(cand.first, left, right) >= threshold) {
    return cand.first;
  }
  return -1;
}

OnlineMajorityElementInSubarraySolution::OnlineMajorityElementInSubarraySolution(
    const std::vector<int>& arr)
    : checker_(arr) {}

int OnlineMajorityElementInSubarraySolution::query(int left, int right,
                                                   int threshold) {
  return checker_.query(left, right, threshold);
}

}  // namespace problem_1157
}  // namespace leetcode
