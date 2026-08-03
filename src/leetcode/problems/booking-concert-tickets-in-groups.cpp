#include "leetcode/problems/booking-concert-tickets-in-groups.h"

#include <algorithm>

namespace leetcode {
namespace problem_2286 {

BookMyShow::BookMyShow(int n, int m)
    : n_(n), m_(m), used_(n, 0), bit_(n, 0), seg_(4 * n, 0), ptr_(0) {
  // initialize segment tree leaves with m free seats each
  auto build = [&](auto&& self, int node, int l, int r) -> void {
    if (l == r) {
      seg_[node] = m;
      return;
    }
    int mid = (l + r) / 2;
    self(self, node * 2, l, mid);
    self(self, node * 2 + 1, mid + 1, r);
    seg_[node] = std::max(seg_[node * 2], seg_[node * 2 + 1]);
  };
  build(build, 1, 0, n_ - 1);
}

void BookMyShow::update_bit(int i, long long delta) {
  for (; i < n_; i |= (i + 1)) {
    bit_[i] += delta;
  }
}

long long BookMyShow::sum_bit(int i) const {
  long long s = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) {
    s += bit_[i];
  }
  return s;
}

long long BookMyShow::sum_used(int a, int b) const {
  long long res = sum_bit(b);
  if (a > 0) res -= sum_bit(a - 1);
  return res;
}

void BookMyShow::update_seg(int node, int l, int r, int i, long long val) {
  if (l == r) {
    seg_[node] = val;
    return;
  }
  int mid = (l + r) / 2;
  if (i <= mid) {
    update_seg(node * 2, l, mid, i, val);
  } else {
    update_seg(node * 2 + 1, mid + 1, r, i, val);
  }
  seg_[node] = std::max(seg_[node * 2], seg_[node * 2 + 1]);
}

long long BookMyShow::query_max(int node, int l, int r, int ql, int qr) const {
  if (ql <= l && r <= qr) return seg_[node];
  int mid = (l + r) / 2;
  long long res = 0;
  if (ql <= mid) res = std::max(res, query_max(node * 2, l, mid, ql, qr));
  if (qr > mid) res = std::max(res, query_max(node * 2 + 1, mid + 1, r, ql, qr));
  return res;
}

int BookMyShow::find_first(int node, int l, int r, int ql, int qr, int k) const {
  if (r < ql || l > qr || seg_[node] < static_cast<long long>(k)) return -1;
  if (l == r) return l;
  int mid = (l + r) / 2;
  int lres = find_first(node * 2, l, mid, ql, qr, k);
  if (lres != -1) return lres;
  return find_first(node * 2 + 1, mid + 1, r, ql, qr, k);
}

void BookMyShow::update_row(int i, long long delta) {
  used_[i] += delta;
  update_bit(i, delta);
  update_seg(1, 0, n_ - 1, i, m_ - used_[i]);
}

std::vector<int> BookMyShow::gather(int k, int maxRow) {
  if (query_max(1, 0, n_ - 1, 0, maxRow) < static_cast<long long>(k)) {
    return {};
  }
  int r = find_first(1, 0, n_ - 1, 0, maxRow, k);
  int c = static_cast<int>(used_[r]);
  update_row(r, static_cast<long long>(k));
  return {r, c};
}

bool BookMyShow::scatter(int k, int maxRow) {
  long long total_free =
      m_ * (static_cast<long long>(maxRow) + 1) - sum_used(0, maxRow);
  if (total_free < static_cast<long long>(k)) return false;
  int remaining = k;
  while (remaining > 0) {
    int row = ptr_;
    long long free_now = m_ - used_[row];
    long long take = std::min(static_cast<long long>(remaining), free_now);
    update_row(row, take);
    remaining -= static_cast<int>(take);
    if (used_[row] == m_) ++ptr_;
  }
  return true;
}

}  // namespace problem_2286
}  // namespace leetcode
