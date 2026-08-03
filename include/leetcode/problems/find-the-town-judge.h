#ifndef LEETCODE_PROBLEMS_FIND_THE_TOWN_JUDGE_H__
#define LEETCODE_PROBLEMS_FIND_THE_TOWN_JUDGE_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_997 {

using Func = std::function<int(int, std::vector<std::vector<int>>&)>;

class FindTheTownJudgeSolution : public SolutionBase<Func> {
 public:
  FindTheTownJudgeSolution();
  int findJudge(int n, std::vector<std::vector<int>>& trust);
};

}  // namespace leetcode::problem_997

#endif  // LEETCODE_PROBLEMS_FIND_THE_TOWN_JUDGE_H__
