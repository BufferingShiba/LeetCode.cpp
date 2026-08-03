#ifndef LEETCODE_PROBLEMS_TRANSFORM_ARRAY_BY_PARITY_H_
#define LEETCODE_PROBLEMS_TRANSFORM_ARRAY_BY_PARITY_H_

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode::problem_3467 {

using Func = std::function<std::vector<int>(std::vector<int>&)>;

class TransformArrayByParitySolution : public SolutionBase<Func> {
 public:
  TransformArrayByParitySolution();

  std::vector<int> transformArray(std::vector<int>& nums);
};

}  // namespace leetcode::problem_3467

#endif  // LEETCODE_PROBLEMS_TRANSFORM_ARRAY_BY_PARITY_H_
