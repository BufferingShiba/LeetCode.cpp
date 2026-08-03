#include "leetcode/problems/range-sum-query-immutable.h"

namespace leetcode::problem_303 {

RangeSumQueryImmutable::RangeSumQueryImmutable(const std::vector<int>& nums) {
  prefix_.resize(nums.size() + 1, 0);
  for (std::size_t i = 0; i < nums.size(); ++i) {
    prefix_[i + 1] = prefix_[i] + nums[i];
  }
}

int RangeSumQueryImmutable::sumRange(int left, int right) const {
  return prefix_[right + 1] - prefix_[left];
}

}  // namespace leetcode::problem_303
