#ifndef LEETCODE_PROBLEMS_MINIMUM_MOVES_TO_EQUAL_ARRAY_ELEMENTS_III_H__
#define LEETCODE_PROBLEMS_MINIMUM_MOVES_TO_EQUAL_ARRAY_ELEMENTS_III_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3736 {

using Func = std::function<int(std::vector<int>&)>;

class MinimumMovesToEqualArrayElementsIiiSolution : public SolutionBase<Func> {
 public:
  MinimumMovesToEqualArrayElementsIiiSolution();

  int minMoves(std::vector<int>& nums);
};

}  // namespace problem_3736
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_MOVES_TO_EQUAL_ARRAY_ELEMENTS_III_H__
