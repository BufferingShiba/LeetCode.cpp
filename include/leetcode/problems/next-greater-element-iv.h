#ifndef LEETCODE_PROBLEMS_NEXT_GREATER_ELEMENT_IV_H__
#define LEETCODE_PROBLEMS_NEXT_GREATER_ELEMENT_IV_H__

#include <functional>
#include <vector>
#include "leetcode/core.h"

namespace leetcode {
namespace problem_2454 {

using Func = std::function<std::vector<int>(std::vector<int>&)>;

class NextGreaterElementIvSolution : public SolutionBase<Func> {
 public:
  NextGreaterElementIvSolution();

  std::vector<int> secondGreaterElement(std::vector<int>& nums);
};

}  // namespace problem_2454
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_NEXT_GREATER_ELEMENT_IV_H__
