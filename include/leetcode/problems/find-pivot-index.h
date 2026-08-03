#ifndef LEETCODE_PROBLEMS_FIND_PIVOT_INDEX_H__
#define LEETCODE_PROBLEMS_FIND_PIVOT_INDEX_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_724 {

using Func = std::function<int(std::vector<int>&)>;

class FindPivotIndexSolution : public SolutionBase<Func> {
 public:
  FindPivotIndexSolution();

  int pivotIndex(std::vector<int>& nums);
};

}  // namespace problem_724
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_PIVOT_INDEX_H__
