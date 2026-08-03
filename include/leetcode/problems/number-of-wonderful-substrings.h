#ifndef LEETCODE_PROBLEMS_NUMBER_OF_WONDERFUL_SUBSTRINGS_H__
#define LEETCODE_PROBLEMS_NUMBER_OF_WONDERFUL_SUBSTRINGS_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_1915 {

using Func = std::function<long long(std::string)>;

class NumberOfWonderfulSubstringsSolution : public SolutionBase<Func> {
 public:
  NumberOfWonderfulSubstringsSolution();

  long long wonderfulSubstrings(std::string word);
};

}  // namespace leetcode::problem_1915

#endif  // LEETCODE_PROBLEMS_NUMBER_OF_WONDERFUL_SUBSTRINGS_H__
