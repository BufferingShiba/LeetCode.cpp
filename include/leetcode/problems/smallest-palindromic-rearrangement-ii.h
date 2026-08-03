#ifndef LEETCODE_PROBLEM_3518_H
#define LEETCODE_PROBLEM_3518_H

#include "leetcode/core.h"
#include <functional>
#include <string>

namespace leetcode {
namespace problem_3518 {

using Func = std::function<std::string(std::string, int)>;

class SmallestPalindromicRearrangementIiSolution : public SolutionBase<Func> {
 public:
  SmallestPalindromicRearrangementIiSolution();

  std::string smallestPalindrome(std::string s, int k);
};

}  // namespace problem_3518
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_3518_H
