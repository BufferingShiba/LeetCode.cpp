#ifndef LEETCODE_PROBLEMS_PALINDROMIC_PATH_QUERIES_IN_A_TREE_H__
#define LEETCODE_PROBLEMS_PALINDROMIC_PATH_QUERIES_IN_A_TREE_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_3841 {

using Func = std::function<std::vector<bool>(
    int, std::vector<std::vector<int>>&, std::string&,
    std::vector<std::string>&)>;

class PalindromicPathQueriesInATreeSolution : public SolutionBase<Func> {
 public:
  PalindromicPathQueriesInATreeSolution();

  std::vector<bool> palindromePath(int n, std::vector<std::vector<int>>& edges,
                                   std::string& s,
                                   std::vector<std::string>& queries);
};

}  // namespace leetcode::problem_3841

#endif  // LEETCODE_PROBLEMS_PALINDROMIC_PATH_QUERIES_IN_A_TREE_H__
