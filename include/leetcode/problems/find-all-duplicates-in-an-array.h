#ifndef LEETCODE_PROBLEMS_FIND_ALL_DUPLICATES_IN_AN_ARRAY_H_
#define LEETCODE_PROBLEMS_FIND_ALL_DUPLICATES_IN_AN_ARRAY_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_442 {

using Func = std::function<std::vector<int>(std::vector<int>&)>;

class FindAllDuplicatesInAnArraySolution : public SolutionBase<Func> {
 public:
  FindAllDuplicatesInAnArraySolution();

  std::vector<int> findDuplicates(std::vector<int>& nums);
};

}  // namespace leetcode::problem_442

#endif  // LEETCODE_PROBLEMS_FIND_ALL_DUPLICATES_IN_AN_ARRAY_H_
