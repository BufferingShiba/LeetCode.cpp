#ifndef LEETCODE_PROBLEMS_FIND_INDICES_OF_STABLE_MOUNTAINS_H__
#define LEETCODE_PROBLEMS_FIND_INDICES_OF_STABLE_MOUNTAINS_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3285 {

using Func = std::function<std::vector<int>(std::vector<int>&, int)>;

class FindIndicesOfStableMountainsSolution
    : public SolutionBase<Func> {
 public:
  FindIndicesOfStableMountainsSolution();

  std::vector<int> stableMountains(std::vector<int>& height, int threshold);
};

}  // namespace problem_3285
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_INDICES_OF_STABLE_MOUNTAINS_H__
