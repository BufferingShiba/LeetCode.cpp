#ifndef LEETCODE_PROBLEMS_BOOKING_CONCERT_TICKETS_IN_GROUPS_H_
#define LEETCODE_PROBLEMS_BOOKING_CONCERT_TICKETS_IN_GROUPS_H_

#include <vector>

namespace leetcode {
namespace problem_2286 {

class BookMyShow {
 public:
  BookMyShow(int n, int m);
  std::vector<int> gather(int k, int maxRow);
  bool scatter(int k, int maxRow);

 private:
  int n_;
  long long m_;
  std::vector<long long> used_;       // used[i] = seats used in row i
  std::vector<long long> bit_;        // Fenwick tree: prefix sum of used_
  std::vector<long long> seg_;        // segment tree: max free seats per row
  int ptr_;                           // scatter cursor: first row not fully filled

  void update_bit(int i, long long delta);
  long long sum_bit(int i) const;
  long long sum_used(int a, int b) const;
  void update_seg(int node, int l, int r, int i, long long val);
  long long query_max(int node, int l, int r, int ql, int qr) const;
  int find_first(int node, int l, int r, int ql, int qr, int k) const;
  void update_row(int i, long long delta);
};

}  // namespace problem_2286
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_BOOKING_CONCERT_TICKETS_IN_GROUPS_H_
