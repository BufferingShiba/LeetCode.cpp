#ifndef LEETCODE_PROBLEMS_LARGEST_PALINDROMIC_NUMBER_H__
#define LEETCODE_PROBLEMS_LARGEST_PALINDROMIC_NUMBER_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2384 {

using Func = std::function<std::string(std::string)>;

class LargestPalindromicNumberSolution
    : public SolutionBase<Func> {
 public:
  LargestPalindromicNumberSolution();

  // 题目原始方法
  std::string largestPalindromic(std::string num);
};

}  // namespace problem_2384
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_LARGEST_PALINDROMIC_NUMBER_H__
