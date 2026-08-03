#ifndef LEETCODE_PROBLEM_3276_H
#define LEETCODE_PROBLEM_3276_H

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3276 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class SelectCellsInGridWithMaximumScoreSolution : public SolutionBase<Func> {
 public:
  SelectCellsInGridWithMaximumScoreSolution();

  int maxScore(std::vector<std::vector<int>>& grid);
};

}  // namespace problem_3276
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_3276_H
