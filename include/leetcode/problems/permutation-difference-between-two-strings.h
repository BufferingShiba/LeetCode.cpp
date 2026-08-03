#ifndef LEETCODE_PROBLEMS_PERMUTATION_DIFFERENCE_BETWEEN_TWO_STRINGS_H__
#define LEETCODE_PROBLEMS_PERMUTATION_DIFFERENCE_BETWEEN_TWO_STRINGS_H__

#include "leetcode/core.h"
#include <functional>
#include <string>

namespace leetcode::problem_3146 {

using Func = std::function<int(std::string, std::string)>;

class PermutationDifferenceBetweenTwoStringsSolution
    : public SolutionBase<Func> {
 public:
  PermutationDifferenceBetweenTwoStringsSolution();

  int findPermutationDifference(std::string s, std::string t);
};

}  // namespace leetcode::problem_3146

#endif  // LEETCODE_PROBLEMS_PERMUTATION_DIFFERENCE_BETWEEN_TWO_STRINGS_H__
