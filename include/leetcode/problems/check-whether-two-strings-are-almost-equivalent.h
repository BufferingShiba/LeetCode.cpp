// Copyright (c) LeetCode.cpp Project.

#ifndef LEETCODE_PROBLEMS_CHECK_WHETHER_TWO_STRINGS_ARE_ALMOST_EQUIVALENT_H_
#define LEETCODE_PROBLEMS_CHECK_WHETHER_TWO_STRINGS_ARE_ALMOST_EQUIVALENT_H_

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2068 {

using Func = std::function<bool(std::string, std::string)>;

class CheckWhetherTwoStringsAreAlmostEquivalentSolution
    : public SolutionBase<Func> {
 public:
  CheckWhetherTwoStringsAreAlmostEquivalentSolution();

  bool checkAlmostEquivalent(std::string word1, std::string word2);
};

}  // namespace problem_2068
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CHECK_WHETHER_TWO_STRINGS_ARE_ALMOST_EQUIVALENT_H_
