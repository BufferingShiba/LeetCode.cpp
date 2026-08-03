#ifndef LEETCODE_PROBLEMS_THE_K_STRONGEST_VALUES_IN_AN_ARRAY_H
#define LEETCODE_PROBLEMS_THE_K_STRONGEST_VALUES_IN_AN_ARRAY_H

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_1471 {

using Func = std::function<std::vector<int>(std::vector<int>&, int)>;

class TheKStrongestValuesInAnArraySolution
    : public SolutionBase<Func> {
 public:
  TheKStrongestValuesInAnArraySolution();

  std::vector<int> getStrongest(std::vector<int>& arr, int k);
};

}  // namespace problem_1471
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_THE_K_STRONGEST_VALUES_IN_AN_ARRAY_H
