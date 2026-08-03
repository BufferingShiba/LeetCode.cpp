#ifndef LEETCODE_PROBLEMS_FIND_INDICES_WITH_INDEX_AND_VALUE_DIFFERENCE_I_H__
#define LEETCODE_PROBLEMS_FIND_INDICES_WITH_INDEX_AND_VALUE_DIFFERENCE_I_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2903 {

using Func = std::function<std::vector<int>(std::vector<int>&, int, int)>;

class FindIndicesWithIndexAndValueDifferenceISolution
    : public SolutionBase<Func> {
 public:
  FindIndicesWithIndexAndValueDifferenceISolution();

  std::vector<int> findIndices(std::vector<int>& nums, int indexDifference,
                               int valueDifference);
};

}  // namespace problem_2903
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_INDICES_WITH_INDEX_AND_VALUE_DIFFERENCE_I_H__
