#ifndef LEETCODE_PROBLEMS_TWO_OUT_OF_THREE_H__
#define LEETCODE_PROBLEMS_TWO_OUT_OF_THREE_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2032 {

using Func = std::function<std::vector<int>(std::vector<int>&, std::vector<int>&,
                                            std::vector<int>&)>;

class TwoOutOfThreeSolution : public SolutionBase<Func> {
 public:
  TwoOutOfThreeSolution();

  std::vector<int> twoOutOfThree(std::vector<int>& nums1, std::vector<int>& nums2,
                                 std::vector<int>& nums3);
};

}  // namespace problem_2032
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_TWO_OUT_OF_THREE_H__
