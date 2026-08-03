#ifndef LEETCODE_PROBLEMS_ONLINE_MAJORITY_ELEMENT_IN_SUBARRAY_H__
#define LEETCODE_PROBLEMS_ONLINE_MAJORITY_ELEMENT_IN_SUBARRAY_H__

#include "leetcode/core.h"

#include <unordered_map>
#include <utility>
#include <vector>

namespace leetcode {
namespace problem_1157 {

class MajorityChecker {
 public:
  MajorityChecker(const std::vector<int>& arr);
  int query(int left, int right, int threshold);

 private:
  static std::pair<int, int> merge_(
      const std::pair<int, int>& a, const std::pair<int, int>& b);
  void build(int node, int l, int r);
  std::pair<int, int> rangeQuery(int node, int l, int r, int ql, int qr);
  int countInRange(int value, int l, int r) const;

  int n_;
  std::vector<int> arr_;
  std::vector<std::pair<int, int>> tree_;  // (Boyer-Moore cand, votes)
  std::unordered_map<int, std::vector<int>> pos_;
};

// Framework-facing wrapper that exposes the design class to local tests.
class OnlineMajorityElementInSubarraySolution {
 public:
  explicit OnlineMajorityElementInSubarraySolution(const std::vector<int>& arr);
  int query(int left, int right, int threshold);

 private:
  MajorityChecker checker_;
};

}  // namespace problem_1157
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_ONLINE_MAJORITY_ELEMENT_IN_SUBARRAY_H__
