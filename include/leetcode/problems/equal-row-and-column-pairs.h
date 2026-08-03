#ifndef LEETCODE_PROBLEMS_EQUAL_ROW_AND_COLUMN_PAIRS_H__
#define LEETCODE_PROBLEMS_EQUAL_ROW_AND_COLUMN_PAIRS_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_2352 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class EqualRowAndColumnPairsSolution : public SolutionBase<Func> {
 public:
  EqualRowAndColumnPairsSolution();
  int equalPairs(std::vector<std::vector<int>>& grid);
};

}  // namespace leetcode::problem_2352

#endif  // LEETCODE_PROBLEMS_EQUAL_ROW_AND_COLUMN_PAIRS_H__
