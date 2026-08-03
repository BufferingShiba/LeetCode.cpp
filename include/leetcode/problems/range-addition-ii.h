#ifndef LEETCODE_PROBLEMS_RANGE_ADDITION_II_H__
#define LEETCODE_PROBLEMS_RANGE_ADDITION_II_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_598 {

using Func = std::function<int(int, int, std::vector<std::vector<int>>&)>;

class RangeAdditionIiSolution : public SolutionBase<Func> {
 public:
  RangeAdditionIiSolution();

  int maxCount(int m, int n, std::vector<std::vector<int>>& ops);
};

}  // namespace problem_598
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_RANGE_ADDITION_II_H__
