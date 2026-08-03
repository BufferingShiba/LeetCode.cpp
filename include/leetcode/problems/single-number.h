#ifndef LEETCODE_PROBLEMS_SINGLE_NUMBER_H__
#define LEETCODE_PROBLEMS_SINGLE_NUMBER_H__

#include "leetcode/core.h"

namespace leetcode {
namespace problem_136 {

using Func = std::function<int(std::vector<int>&)>;

class SingleNumberSolution : public SolutionBase<Func> {
 public:
  SingleNumberSolution();

  int singleNumber(std::vector<int>& nums);
};

}  // namespace problem_136
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SINGLE_NUMBER_H__
