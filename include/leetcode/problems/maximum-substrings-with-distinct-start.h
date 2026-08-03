#ifndef LEETCODE_PROBLEMS_MAXIMUM_SUBSTRINGS_WITH_DISTINCT_START_H__
#define LEETCODE_PROBLEMS_MAXIMUM_SUBSTRINGS_WITH_DISTINCT_START_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_3760 {

using Func = std::function<int(std::string)>;

class MaximumSubstringsWithDistinctStartSolution
    : public SolutionBase<Func> {
 public:
  MaximumSubstringsWithDistinctStartSolution();

  int maxDistinct(std::string s);
};

}  // namespace leetcode::problem_3760

#endif  // LEETCODE_PROBLEMS_MAXIMUM_SUBSTRINGS_WITH_DISTINCT_START_H__
