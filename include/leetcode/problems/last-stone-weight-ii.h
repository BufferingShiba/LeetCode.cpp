#ifndef LEETCODE_SOLUTIONS_PROBLEMS_LAST_STONE_WEIGHT_II_H__
#define LEETCODE_SOLUTIONS_PROBLEMS_LAST_STONE_WEIGHT_II_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_1049 {

using Func = std::function<int(std::vector<int>&)>;

class LastStoneWeightIiSolution : public SolutionBase<Func> {
 public:
  LastStoneWeightIiSolution();

  int lastStoneWeightII(std::vector<int>& stones);
};

}  // namespace problem_1049
}  // namespace leetcode

#endif  // LEETCODE_SOLUTIONS_PROBLEMS_LAST_STONE_WEIGHT_II_H__
