#ifndef LEETCODE_PROBLEMS_COUNT_BEAUTIFUL_SPLITS_IN_AN_ARRAY_H_
#define LEETCODE_PROBLEMS_COUNT_BEAUTIFUL_SPLITS_IN_AN_ARRAY_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_3388 {

using Func = std::function<int(std::vector<int>&)>;

class CountBeautifulSplitsInAnArraySolution
    : public SolutionBase<Func> {
 public:
  CountBeautifulSplitsInAnArraySolution();

  int beautifulSplits(std::vector<int>& nums);
};

}  // namespace leetcode::problem_3388

#endif  // LEETCODE_PROBLEMS_COUNT_BEAUTIFUL_SPLITS_IN_AN_ARRAY_H_
