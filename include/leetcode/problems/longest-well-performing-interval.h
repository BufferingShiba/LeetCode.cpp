#ifndef LEETCODE_PROBLEMS_LONGEST_WELL_PERFORMING_INTERVAL_H__
#define LEETCODE_PROBLEMS_LONGEST_WELL_PERFORMING_INTERVAL_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode::problem_1124 {

using Func = std::function<int(std::vector<int>&)>;

class LongestWellPerformingIntervalSolution
    : public SolutionBase<Func> {
 public:
  LongestWellPerformingIntervalSolution();

  int longestWPI(std::vector<int>& hours);
};

}  // namespace leetcode::problem_1124

#endif  // LEETCODE_PROBLEMS_LONGEST_WELL_PERFORMING_INTERVAL_H__
