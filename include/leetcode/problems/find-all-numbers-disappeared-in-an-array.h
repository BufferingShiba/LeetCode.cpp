#ifndef LEETCODE_PROBLEMS_FIND_ALL_NUMBERS_DISAPPEARED_IN_AN_ARRAY_H__
#define LEETCODE_PROBLEMS_FIND_ALL_NUMBERS_DISAPPEARED_IN_AN_ARRAY_H__

#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_448 {

using Func = std::function<std::vector<int>(std::vector<int>&)>;

class FindAllNumbersDisappearedInAnArraySolution
    : public SolutionBase<Func> {
 public:
  FindAllNumbersDisappearedInAnArraySolution();

  std::vector<int> findDisappearedNumbers(std::vector<int>& nums);
};

}  // namespace problem_448
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_ALL_NUMBERS_DISAPPEARED_IN_AN_ARRAY_H__
