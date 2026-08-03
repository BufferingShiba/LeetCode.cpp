#ifndef LEETCODE_PROBLEMS_ARRAY_WITH_ELEMENTS_NOT_EQUAL_TO_AVERAGE_OF_NEIGHBORS_H_
#define LEETCODE_PROBLEMS_ARRAY_WITH_ELEMENTS_NOT_EQUAL_TO_AVERAGE_OF_NEIGHBORS_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1968 {

using Func = std::function<std::vector<int>(std::vector<int>&)>;

class ArrayWithElementsNotEqualToAverageOfNeighborsSolution : public SolutionBase<Func> {
 public:
  ArrayWithElementsNotEqualToAverageOfNeighborsSolution();

  std::vector<int> rearrangeArray(std::vector<int>& nums);
};

}  // namespace problem_1968
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_ARRAY_WITH_ELEMENTS_NOT_EQUAL_TO_AVERAGE_OF_NEIGHBORS_H_
