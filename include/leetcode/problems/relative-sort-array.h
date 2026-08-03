#ifndef LEETCODE_PROBLEMS_RELATIVE_SORT_ARRAY_H__
#define LEETCODE_PROBLEMS_RELATIVE_SORT_ARRAY_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1122 {

using Func =
    std::function<std::vector<int>(std::vector<int>&, std::vector<int>&)>;

class RelativeSortArraySolution : public SolutionBase<Func> {
 public:
  RelativeSortArraySolution();

  std::vector<int> relativeSortArray(std::vector<int>& arr1,
                                     std::vector<int>& arr2);
};

}  // namespace problem_1122
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_RELATIVE_SORT_ARRAY_H__
