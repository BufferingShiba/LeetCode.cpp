#ifndef LEETCODE_PROBLEMS_BINARY_SEARCH_H__
#define LEETCODE_PROBLEMS_BINARY_SEARCH_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_704 {

using Func = std::function<int(std::vector<int>&, int)>;

class BinarySearchSolution : public SolutionBase<Func> {
 public:
  BinarySearchSolution();

  int search(std::vector<int>& nums, int target);
};

}  // namespace leetcode::problem_704

#endif  // LEETCODE_PROBLEMS_BINARY_SEARCH_H__
