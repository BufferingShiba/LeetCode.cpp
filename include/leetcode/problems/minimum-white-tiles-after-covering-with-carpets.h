#ifndef LEETCODE_PROBLEMS_MINIMUM_WHITE_TILES_AFTER_COVERING_WITH_CARPETS_H_
#define LEETCODE_PROBLEMS_MINIMUM_WHITE_TILES_AFTER_COVERING_WITH_CARPETS_H_

#include "leetcode/core.h"

namespace leetcode::problem_2209 {

using Func = std::function<int(std::string, int, int)>;

class MinimumWhiteTilesAfterCoveringWithCarpetsSolution : public SolutionBase<Func> {
 public:
  MinimumWhiteTilesAfterCoveringWithCarpetsSolution();
  int minimumWhiteTiles(std::string floor, int numCarpets, int carpetLen);
};

}  // namespace leetcode::problem_2209

#endif  // LEETCODE_PROBLEMS_MINIMUM_WHITE_TILES_AFTER_COVERING_WITH_CARPETS_H_
