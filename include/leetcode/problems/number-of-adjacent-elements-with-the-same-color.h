#ifndef LEETCODE_PROBLEMS_NUMBER_OF_ADJACENT_ELEMENTS_WITH_THE_SAME_COLOR_H_
#define LEETCODE_PROBLEMS_NUMBER_OF_ADJACENT_ELEMENTS_WITH_THE_SAME_COLOR_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2672 {

using Func = std::function<std::vector<int>(int, std::vector<std::vector<int>>&)>;

class NumberOfAdjacentElementsWithTheSameColorSolution : public SolutionBase<Func> {
 public:
  NumberOfAdjacentElementsWithTheSameColorSolution();

  std::vector<int> colorTheArray(int n, std::vector<std::vector<int>>& queries);
};

}  // namespace problem_2672
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_NUMBER_OF_ADJACENT_ELEMENTS_WITH_THE_SAME_COLOR_H_
