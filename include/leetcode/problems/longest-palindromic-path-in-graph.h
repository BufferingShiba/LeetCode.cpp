#ifndef LEETCODE_PROBLEMS_LONGEST_PALINDROMIC_PATH_IN_GRAPH_H_
#define LEETCODE_PROBLEMS_LONGEST_PALINDROMIC_PATH_IN_GRAPH_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_3615 {

using Func = std::function<int(int n, std::vector<std::vector<int>>& edges,
                               std::string label)>;

class LongestPalindromicPathInGraphSolution
    : public SolutionBase<Func> {
 public:
  LongestPalindromicPathInGraphSolution();

  int maxLen(int n, std::vector<std::vector<int>>& edges,
             std::string label);
};

}  // namespace leetcode::problem_3615

#endif  // LEETCODE_PROBLEMS_LONGEST_PALINDROMIC_PATH_IN_GRAPH_H_
