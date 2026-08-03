#ifndef LEETCODE_PROBLEMS_MINIMUM_RECOLORS_TO_GET_K_CONSECUTIVE_BLACK_BLOCKS_H__
#define LEETCODE_PROBLEMS_MINIMUM_RECOLORS_TO_GET_K_CONSECUTIVE_BLACK_BLOCKS_H__

#include "leetcode/core.h"

#include <functional>
#include <string>

namespace leetcode::problem_2379 {

using Func = std::function<int(std::string, int)>;

class MinimumRecolorsToGetKConsecutiveBlackBlocksSolution : public SolutionBase<Func> {
 public:
  MinimumRecolorsToGetKConsecutiveBlackBlocksSolution();

  int minimumRecolors(std::string blocks, int k);
};

}  // namespace leetcode::problem_2379

#endif  // LEETCODE_PROBLEMS_MINIMUM_RECOLORS_TO_GET_K_CONSECUTIVE_BLACK_BLOCKS_H__
