#ifndef LEETCODE_PROBLEMS_DIVIDE_A_STRING_INTO_GROUPS_OF_SIZE_K_H__
#define LEETCODE_PROBLEMS_DIVIDE_A_STRING_INTO_GROUPS_OF_SIZE_K_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_2138 {

using Func = std::function<std::vector<std::string>(std::string, int, char)>;

class DivideAStringIntoGroupsOfSizeKSolution
    : public SolutionBase<Func> {
 public:
  std::vector<std::string> divideString(std::string s, int k, char fill);

  DivideAStringIntoGroupsOfSizeKSolution();
};

}  // namespace leetcode::problem_2138

#endif  // LEETCODE_PROBLEMS_DIVIDE_A_STRING_INTO_GROUPS_OF_SIZE_K_H__
