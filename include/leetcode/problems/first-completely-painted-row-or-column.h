#ifndef LEETCODE_PROBLEMS_FIRST_COMPLETELY_PAINTED_ROW_OR_COLUMN_H__
#define LEETCODE_PROBLEMS_FIRST_COMPLETELY_PAINTED_ROW_OR_COLUMN_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_2661 {

using Func =
    std::function<int(std::vector<int>&, std::vector<std::vector<int>>&)>;

class FirstCompletelyPaintedRowOrColumnSolution
    : public SolutionBase<Func> {
 public:
  FirstCompletelyPaintedRowOrColumnSolution();

  int firstCompleteIndex(std::vector<int>& arr,
                         std::vector<std::vector<int>>& mat);
};

}  // namespace problem_2661
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIRST_COMPLETELY_PAINTED_ROW_OR_COLUMN_H__
