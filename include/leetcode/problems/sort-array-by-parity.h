#ifndef LEETCODE_PROBLEMS_SORT_ARRAY_BY_PARITY_H__
#define LEETCODE_PROBLEMS_SORT_ARRAY_BY_PARITY_H__

#include "leetcode/core.h"
#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_905 {

using Func = std::function<std::vector<int>(std::vector<int>&)>;

class SortArrayByParitySolution : public SolutionBase<Func> {
 public:
  SortArrayByParitySolution();

  std::vector<int> sortArrayByParity(std::vector<int>& nums);
};

}  // namespace problem_905
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SORT_ARRAY_BY_PARITY_H__
