#ifndef LEETCODE_PROBLEMS_REDUCE_ARRAY_SIZE_TO_THE_HALF_H__
#define LEETCODE_PROBLEMS_REDUCE_ARRAY_SIZE_TO_THE_HALF_H__

#include "leetcode/core.h"
#include <functional>
#include <vector>
#include <string>

namespace leetcode {
namespace problem_1338 {

using Func = std::function<int(std::vector<int>&)>;

class ReduceArraySizeToTheHalfSolution : public SolutionBase<Func> {
 public:
  ReduceArraySizeToTheHalfSolution();

  int minSetSize(std::vector<int>& arr);
};

}  // namespace problem_1338
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_REDUCE_ARRAY_SIZE_TO_THE_HALF_H__
