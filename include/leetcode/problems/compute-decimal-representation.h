#ifndef LEETCODE_PROBLEMS_COMPUTE_DECIMAL_REPRESENTATION_H__
#define LEETCODE_PROBLEMS_COMPUTE_DECIMAL_REPRESENTATION_H__

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode::problem_3697 {

using Func = std::function<std::vector<int>(int)>;

class ComputeDecimalRepresentationSolution
    : public SolutionBase<Func> {
 public:
  ComputeDecimalRepresentationSolution();

  std::vector<int> decimalRepresentation(int n);
};

}  // namespace leetcode::problem_3697

#endif  // LEETCODE_PROBLEMS_COMPUTE_DECIMAL_REPRESENTATION_H__
