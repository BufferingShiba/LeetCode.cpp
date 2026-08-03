#ifndef LEETCODE_PROBLEMS_NEXT_GREATER_ELEMENT_III_H__
#define LEETCODE_PROBLEMS_NEXT_GREATER_ELEMENT_III_H__

#include "leetcode/core.h"
#include <functional>
#include <string>

namespace leetcode {
namespace problem_556 {

using Func = std::function<int(int)>;

class NextGreaterElementIiiSolution : public SolutionBase<Func> {
 public:
  NextGreaterElementIiiSolution();

  int nextGreaterElement(int n);
};

}  // namespace problem_556
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_NEXT_GREATER_ELEMENT_III_H__
