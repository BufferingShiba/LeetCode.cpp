#ifndef LEETCODE_PROBLEMS_FIND_N_UNIQUE_INTEGERS_SUM_UP_TO_ZERO_H__
#define LEETCODE_PROBLEMS_FIND_N_UNIQUE_INTEGERS_SUM_UP_TO_ZERO_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1304 {

using Func = std::function<std::vector<int>(int n)>;

class FindNUniqueIntegersSumUpToZeroSolution
    : public SolutionBase<Func> {
 public:
  FindNUniqueIntegersSumUpToZeroSolution();

  std::vector<int> sumZero(int n);
};

}  // namespace problem_1304
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_N_UNIQUE_INTEGERS_SUM_UP_TO_ZERO_H__
