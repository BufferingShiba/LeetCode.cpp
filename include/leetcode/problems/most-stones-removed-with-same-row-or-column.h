#ifndef LEETCODE_PROBLEMS_MOST_STONES_REMOVED_WITH_SAME_ROW_OR_COLUMN_H__
#define LEETCODE_PROBLEMS_MOST_STONES_REMOVED_WITH_SAME_ROW_OR_COLUMN_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_947 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class MostStonesRemovedWithSameRowOrColumnSolution
    : public SolutionBase<Func> {
 public:
  MostStonesRemovedWithSameRowOrColumnSolution();

  int removeStones(std::vector<std::vector<int>>& stones);
};

}  // namespace leetcode::problem_947

#endif  // LEETCODE_PROBLEMS_MOST_STONES_REMOVED_WITH_SAME_ROW_OR_COLUMN_H__
