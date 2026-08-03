#ifndef LEETCODE_PROBLEMS_ADD_TO_ARRAY_FORM_OF_INTEGER_H__
#define LEETCODE_PROBLEMS_ADD_TO_ARRAY_FORM_OF_INTEGER_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_989 {

using Func = std::function<std::vector<int>(std::vector<int>&, int)>;

class AddToArrayFormOfIntegerSolution
    : public SolutionBase<Func> {
 public:
  AddToArrayFormOfIntegerSolution();

  std::vector<int> addToArrayForm(std::vector<int>& num, int k);
};

}  // namespace problem_989
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_ADD_TO_ARRAY_FORM_OF_INTEGER_H__
