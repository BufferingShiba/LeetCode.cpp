#ifndef LEETCODE_PROBLEMS_MAXIMUM_WHITE_TILES_COVERED_BY_A_CARPET_H_
#define LEETCODE_PROBLEMS_MAXIMUM_WHITE_TILES_COVERED_BY_A_CARPET_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2271 {

using Func = std::function<int(std::vector<std::vector<int>>&, int)>;

class MaximumWhiteTilesCoveredByACarpetSolution : public SolutionBase<Func> {
 public:
  MaximumWhiteTilesCoveredByACarpetSolution();

  int maximumWhiteTiles(std::vector<std::vector<int>>& tiles, int carpetLen);
};

}  // namespace problem_2271
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_WHITE_TILES_COVERED_BY_A_CARPET_H_
