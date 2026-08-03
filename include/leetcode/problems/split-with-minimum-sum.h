#ifndef LEETCODE_PROBLEMS_SPLIT_WITH_MINIMUM_SUM_H__
#define LEETCODE_PROBLEMS_SPLIT_WITH_MINIMUM_SUM_H__

#include "leetcode/core.h"
#include <functional>

namespace leetcode {
namespace problem_2578 {

using Func = std::function<int(int)>;

class SplitWithMinimumSumSolution : public SolutionBase<Func> {
 public:
  SplitWithMinimumSumSolution();

  int splitNum(int num);
};

}  // namespace problem_2578
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SPLIT_WITH_MINIMUM_SUM_H__
