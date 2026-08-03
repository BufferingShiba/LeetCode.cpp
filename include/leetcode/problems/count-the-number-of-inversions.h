#ifndef LEETCODE_PROBLEMS_COUNT_THE_NUMBER_OF_INVERSIONS_H__
#define LEETCODE_PROBLEMS_COUNT_THE_NUMBER_OF_INVERSIONS_H__

#include <vector>
#include <functional>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3193 {

using Func = std::function<int(int, std::vector<std::vector<int>>&)>;

class CountTheNumberOfInversionsSolution : public SolutionBase<Func> {
 public:
  CountTheNumberOfInversionsSolution();
  int numberOfPermutations(int n, std::vector<std::vector<int>>& requirements);
};

}  // namespace problem_3193
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COUNT_THE_NUMBER_OF_INVERSIONS_H__
