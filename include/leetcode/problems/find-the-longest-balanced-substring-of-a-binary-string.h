#ifndef LEETCODE_PROBLEMS_FIND_THE_LONGEST_BALANCED_SUBSTRING_OF_A_BINARY_STRING_H__
#define LEETCODE_PROBLEMS_FIND_THE_LONGEST_BALANCED_SUBSTRING_OF_A_BINARY_STRING_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_2609 {

using Func = std::function<int(std::string)>;

class FindTheLongestBalancedSubstringOfABinaryStringSolution
    : public SolutionBase<Func> {
 public:
  FindTheLongestBalancedSubstringOfABinaryStringSolution();

  int findTheLongestBalancedSubstring(std::string s);
};

}  // namespace leetcode::problem_2609

#endif  // LEETCODE_PROBLEMS_FIND_THE_LONGEST_BALANCED_SUBSTRING_OF_A_BINARY_STRING_H__
