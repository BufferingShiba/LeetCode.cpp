#ifndef LEETCODE_PROBLEMS_MAXIMUM_OR_H__
#define LEETCODE_PROBLEMS_MAXIMUM_OR_H__

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2680 {

using Func = std::function<long long(std::vector<int>&, int)>;

class MaximumOrSolution : public SolutionBase<Func> {
 public:
  MaximumOrSolution();
};

}  // namespace problem_2680
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_OR_H__
