#ifndef LEETCODE_PROBLEMS_LONGEST_UNCOMMON_SUBSEQUENCE_I_H_
#define LEETCODE_PROBLEMS_LONGEST_UNCOMMON_SUBSEQUENCE_I_H_

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_521 {

using Func = std::function<int(std::string, std::string)>;

class LongestUncommonSubsequenceISolution : public SolutionBase<Func> {
 public:
  LongestUncommonSubsequenceISolution();

  [[nodiscard]] int findLUSlength(std::string a, std::string b);
};

}  // namespace leetcode::problem_521

#endif  // LEETCODE_PROBLEMS_LONGEST_UNCOMMON_SUBSEQUENCE_I_H_
