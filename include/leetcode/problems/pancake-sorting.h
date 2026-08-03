#ifndef LEETCODE_PROBLEMS_PANCAKE_SORTING_H__
#define LEETCODE_PROBLEMS_PANCAKE_SORTING_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_969 {

using Func = std::function<std::vector<int>(std::vector<int>&)>;

class PancakeSortingSolution : public SolutionBase<Func> {
 public:
  PancakeSortingSolution();
  std::vector<int> pancakeSort(std::vector<int>& arr);
};

}  // namespace leetcode::problem_969

#endif  // LEETCODE_PROBLEMS_PANCAKE_SORTING_H__
