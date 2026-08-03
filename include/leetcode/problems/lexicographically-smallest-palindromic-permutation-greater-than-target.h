#ifndef LEETCODE_PROBLEM_3734_H
#define LEETCODE_PROBLEM_3734_H

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3734 {

using Func = std::function<std::string(std::string, std::string)>;

class LexicographicallySmallestPalindromicPermutationGreaterThanTargetSolution
    : public SolutionBase<Func> {
 public:
  LexicographicallySmallestPalindromicPermutationGreaterThanTargetSolution();

  std::string lexPalindromicPermutation(std::string s, std::string target);
};

}  // namespace problem_3734
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_3734_H
