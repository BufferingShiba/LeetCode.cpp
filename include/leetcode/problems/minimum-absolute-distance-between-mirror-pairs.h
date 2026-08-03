#ifndef LEETCODE_PROBLEMS_MINIMUM_ABSOLUTE_DISTANCE_BETWEEN_MIRROR_PAIRS_H_
#define LEETCODE_PROBLEMS_MINIMUM_ABSOLUTE_DISTANCE_BETWEEN_MIRROR_PAIRS_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3761 {

using Func = std::function<int(std::vector<int>&)>;

class MinimumAbsoluteDistanceBetweenMirrorPairsSolution
    : public SolutionBase<Func> {
 public:
  MinimumAbsoluteDistanceBetweenMirrorPairsSolution();

  // 题目要求的方法
  int minMirrorPairDistance(std::vector<int>& nums);
};

}  // namespace problem_3761
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_ABSOLUTE_DISTANCE_BETWEEN_MIRROR_PAIRS_H_
