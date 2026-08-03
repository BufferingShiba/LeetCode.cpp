#ifndef LEETCODE_PROBLEMS_LIMIT_OCCURRENCES_IN_SORTED_ARRAY_H_
#define LEETCODE_PROBLEMS_LIMIT_OCCURRENCES_IN_SORTED_ARRAY_H_

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode::problem_3940 {

using Func = std::function<std::vector<int>(std::vector<int>&, int)>;

class LimitOccurrencesInSortedArraySolution
    : public SolutionBase<Func> {
 public:
  LimitOccurrencesInSortedArraySolution();

  std::vector<int> limitOccurrences(std::vector<int>& nums, int k);
};

}  // namespace leetcode::problem_3940

#endif  // LEETCODE_PROBLEMS_LIMIT_OCCURRENCES_IN_SORTED_ARRAY_H_
