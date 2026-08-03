#ifndef LEETCODE_PROBLEMS_LONGEST_BALANCED_SUBSTRING_II_H__
#define LEETCODE_PROBLEMS_LONGEST_BALANCED_SUBSTRING_II_H__

#include "leetcode/core.h"
#include <functional>
#include <string>

namespace leetcode {
namespace problem_3714 {

using Func = std::function<int(std::string)>;

class LongestBalancedSubstringIiSolution : public SolutionBase<Func> {
public:
  LongestBalancedSubstringIiSolution();

  int longestBalanced(std::string s) { return getSolution()(std::move(s)); }
};

}  // namespace problem_3714
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_LONGEST_BALANCED_SUBSTRING_II_H__
