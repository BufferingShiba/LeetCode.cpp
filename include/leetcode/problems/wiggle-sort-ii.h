#ifndef LEETCODE_PROBLEMS_WIGGLE_SORT_II_H__
#define LEETCODE_PROBLEMS_WIGGLE_SORT_II_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode::problem_324 {

using Func = std::function<void(std::vector<int>&)>;

class WiggleSortIiSolution : public SolutionBase<Func> {
 public:
  WiggleSortIiSolution();

  void wiggleSort(std::vector<int>& nums);
};

}  // namespace leetcode::problem_324

#endif  // LEETCODE_PROBLEMS_WIGGLE_SORT_II_H__
