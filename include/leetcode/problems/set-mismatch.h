#ifndef LEETCODE_PROBLEMS_SET_MISMATCH_H_
#define LEETCODE_PROBLEMS_SET_MISMATCH_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_645 {

using Func = std::function<std::vector<int>(std::vector<int>&)>;

class SetMismatchSolution : public SolutionBase<Func> {
 public:
  SetMismatchSolution();

  std::vector<int> findErrorNums(std::vector<int>& nums);
};

}  // namespace problem_645
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SET_MISMATCH_H_
