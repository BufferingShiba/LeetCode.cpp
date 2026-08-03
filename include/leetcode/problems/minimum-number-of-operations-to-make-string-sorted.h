#ifndef LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_OPERATIONS_TO_MAKE_STRING_SORTED_H_
#define LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_OPERATIONS_TO_MAKE_STRING_SORTED_H_

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_1830 {

using Func = std::function<int(std::string)>;

class MinimumNumberOfOperationsToMakeStringSortedSolution
    : public SolutionBase<Func> {
 public:
  MinimumNumberOfOperationsToMakeStringSortedSolution();

  int makeStringSorted(std::string s);
};

}  // namespace leetcode::problem_1830

#endif  // LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_OPERATIONS_TO_MAKE_STRING_SORTED_H_
