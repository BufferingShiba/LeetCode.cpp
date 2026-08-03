#include "leetcode/core.h"

namespace leetcode {
namespace problem_384 {

//! 384. Shuffle an Array
//! https://leetcode.com/problems/shuffle-an-array/
class Solution {
 public:
  Solution(vector<int>& nums);
  vector<int> reset();
  vector<int> shuffle();

 private:
  vector<int> original_;
  vector<int> nums_;
};

}  // namespace problem_384
}  // namespace leetcode
