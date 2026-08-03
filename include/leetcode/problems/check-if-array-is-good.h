#ifndef LEETCODE_PROBLEMS_CHECK_IF_ARRAY_IS_GOOD_H_
#define LEETCODE_PROBLEMS_CHECK_IF_ARRAY_IS_GOOD_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2784 {

using Func = std::function<bool(std::vector<int>&)>;

class CheckIfArrayIsGoodSolution : public SolutionBase<Func> {
 public:
  CheckIfArrayIsGoodSolution();

  bool isGood(std::vector<int>& nums);
};

}  // namespace problem_2784
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CHECK_IF_ARRAY_IS_GOOD_H_
