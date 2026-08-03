#ifndef LEETCODE_PROBLEM_2120_H
#define LEETCODE_PROBLEM_2120_H

#include "leetcode/core.h"

namespace leetcode::problem_2120 {

using Func = std::function<std::vector<int>(int, std::vector<int>&, std::string)>;

class ExecutionOfAllSuffixInstructionsStayingInAGridSolution : public SolutionBase<Func> {
 public:
  ExecutionOfAllSuffixInstructionsStayingInAGridSolution();
  std::vector<int> executeInstructions(int n, std::vector<int>& startPos, std::string s);
};

}  // namespace leetcode::problem_2120

#endif  // LEETCODE_PROBLEM_2120_H
