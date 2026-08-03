#ifndef LEETCODE_PROBLEMS_FIND_THE_DISTINCT_DIFFERENCE_ARRAY_H_
#define LEETCODE_PROBLEMS_FIND_THE_DISTINCT_DIFFERENCE_ARRAY_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2670 {

using Func = std::function<std::vector<int>(std::vector<int>&)>;

class FindTheDistinctDifferenceArraySolution
    : public SolutionBase<Func> {
 public:
  std::vector<int> distinctDifferenceArray(std::vector<int>& nums);
  FindTheDistinctDifferenceArraySolution();
};

}  // namespace problem_2670
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_THE_DISTINCT_DIFFERENCE_ARRAY_H_
