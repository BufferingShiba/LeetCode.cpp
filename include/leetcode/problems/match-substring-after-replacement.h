#ifndef LEETCODE_PROBLEM_2301_H
#define LEETCODE_PROBLEM_2301_H

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2301 {

using Func = std::function<bool(std::string, std::string, std::vector<std::vector<char>>&)>;

class MatchSubstringAfterReplacementSolution : public SolutionBase<Func> {
 public:
  bool matchReplacement(std::string s, std::string sub, std::vector<std::vector<char>>& mappings);
  MatchSubstringAfterReplacementSolution();
};

}  // namespace problem_2301
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_2301_H
