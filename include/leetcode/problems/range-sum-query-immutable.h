#ifndef LEETCODE_PROBLEMS_RANGE_SUM_QUERY_IMMUTABLE_H
#define LEETCODE_PROBLEMS_RANGE_SUM_QUERY_IMMUTABLE_H

#include <vector>

namespace leetcode::problem_303 {

// LeetCode 303. Range Sum Query - Immutable
// Design class using prefix sum for O(1) range-sum queries.
class RangeSumQueryImmutable {
 public:
  explicit RangeSumQueryImmutable(const std::vector<int>& nums);

  int sumRange(int left, int right) const;

 private:
  // prefix_[i] = sum of nums[0..i-1]
  std::vector<int> prefix_;
};

}  // namespace leetcode::problem_303

#endif  // LEETCODE_PROBLEMS_RANGE_SUM_QUERY_IMMUTABLE_H
