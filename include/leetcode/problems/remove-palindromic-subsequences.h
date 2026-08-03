#ifndef LEETCODE_PROBLEMS_REMOVE_PALINDROMIC_SUBSEQUENCES_H__
#define LEETCODE_PROBLEMS_REMOVE_PALINDROMIC_SUBSEQUENCES_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_1332 {

using Func = std::function<int(std::string)>;

class RemovePalindromicSubsequencesSolution
    : public SolutionBase<Func> {
 public:
  RemovePalindromicSubsequencesSolution();
  int removePalindromeSub(std::string s);
};

}  // namespace leetcode::problem_1332

#endif  // LEETCODE_PROBLEMS_REMOVE_PALINDROMIC_SUBSEQUENCES_H__
