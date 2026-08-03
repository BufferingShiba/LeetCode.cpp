#include "leetcode/problems/shuffle-an-array.h"

#include <cstdlib>

namespace leetcode {
namespace problem_384 {

Solution::Solution(vector<int>& nums) : nums_(nums) {
  original_ = nums;
}

vector<int> Solution::reset() {
  return original_;
}

vector<int> Solution::shuffle() {
  // Fisher-Yates shuffle: at step i pick a random index j in [0, i]
  // and swap nums_[i] with nums_[j]. Each permutation is equally likely.
  int n = static_cast<int>(nums_.size());
  for (int i = n - 1; i > 0; --i) {
    int j = std::rand() % (i + 1);
    std::swap(nums_[i], nums_[j]);
  }
  return nums_;
}

}  // namespace problem_384
}  // namespace leetcode
