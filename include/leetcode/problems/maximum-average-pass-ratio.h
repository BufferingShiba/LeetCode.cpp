#ifndef LEETCODE_PROBLEMS_MAXIMUM_AVERAGE_PASS_RATIO_H_
#define LEETCODE_PROBLEMS_MAXIMUM_AVERAGE_PASS_RATIO_H_

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode::problem_1792 {

using Func = std::function<double(std::vector<std::vector<int>>&, int)>;

class MaximumAveragePassRatioSolution : public SolutionBase<Func> {
 public:
  MaximumAveragePassRatioSolution();

  double maxAverageRatio(std::vector<std::vector<int>>& classes, int extraStudents);
};

}  // namespace leetcode::problem_1792

#endif  // LEETCODE_PROBLEMS_MAXIMUM_AVERAGE_PASS_RATIO_H_
