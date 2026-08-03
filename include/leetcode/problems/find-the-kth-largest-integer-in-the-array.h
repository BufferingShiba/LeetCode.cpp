#include "leetcode/core.h"

namespace leetcode {
namespace problem_1985 {

using Func = std::function<string(vector<string>&, int)>;

class FindTheKthLargestIntegerInTheArraySolution : public SolutionBase<Func> {
 public:
  //! 1985. Find the Kth Largest Integer in the Array
  //! https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/
  string kthLargestNumber(vector<string>& nums, int k);

  FindTheKthLargestIntegerInTheArraySolution();
};

}  // namespace problem_1985
}  // namespace leetcode
