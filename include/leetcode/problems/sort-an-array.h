#ifndef LEETCODE_PROBLEMS_SORT_AN_ARRAY_H__
#define LEETCODE_PROBLEMS_SORT_AN_ARRAY_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_912 {

using Func = std::function<std::vector<int>(std::vector<int>&)>;

class SortAnArraySolution : public SolutionBase<Func> {
 public:
  SortAnArraySolution();

  std::vector<int> sortArray(std::vector<int>& nums);
};

}  // namespace problem_912
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SORT_AN_ARRAY_H__
