#ifndef LEETCODE_PROBLEMS_COUNT_LARGEST_GROUP_H__
#define LEETCODE_PROBLEMS_COUNT_LARGEST_GROUP_H__

#include "leetcode/core.h"

namespace leetcode::problem_1399 {

using Func = std::function<int(int)>;

class CountLargestGroupSolution : public SolutionBase<Func> {
 public:
  CountLargestGroupSolution();

  int countLargestGroup(int n);
};

}  // namespace leetcode::problem_1399

#endif  // LEETCODE_PROBLEMS_COUNT_LARGEST_GROUP_H__
