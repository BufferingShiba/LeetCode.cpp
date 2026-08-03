#ifndef LEETCODE_PROBLEMS_MAXIMUM_FRUITS_HARVESTED_AFTER_AT_MOST_K_STEPS_H_
#define LEETCODE_PROBLEMS_MAXIMUM_FRUITS_HARVESTED_AFTER_AT_MOST_K_STEPS_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2106 {

using Func = std::function<int(std::vector<std::vector<int>>&, int, int)>;

class MaximumFruitsHarvestedAfterAtMostKStepsSolution : public SolutionBase<Func> {
 public:
  MaximumFruitsHarvestedAfterAtMostKStepsSolution();

  int maxTotalFruits(std::vector<std::vector<int>>& fruits, int startPos, int k) {
    return getSolution()(fruits, startPos, k);
  }
};

}  // namespace problem_2106
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_FRUITS_HARVESTED_AFTER_AT_MOST_K_STEPS_H_
