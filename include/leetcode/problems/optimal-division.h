#ifndef LEETCODE_PROBLEMS_OPTIMAL_DIVISION_H_
#define LEETCODE_PROBLEMS_OPTIMAL_DIVISION_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_553 {

using Func = std::function<std::string(std::vector<int>&)>;

class OptimalDivisionSolution : public SolutionBase<Func> {
 public:
  OptimalDivisionSolution();

  std::string optimalDivision(std::vector<int>& nums);
};

}  // namespace problem_553
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_OPTIMAL_DIVISION_H_
