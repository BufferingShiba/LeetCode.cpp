#ifndef LEETCODE_PROBLEMS_MINIMUM_COST_TO_MAKE_TWO_BINARY_STRINGS_EQUAL_H__
#define LEETCODE_PROBLEMS_MINIMUM_COST_TO_MAKE_TWO_BINARY_STRINGS_EQUAL_H__

#include "leetcode/core.h"

#include <functional>
#include <string>

namespace leetcode {
namespace problem_3800 {

using Func = std::function<long long(std::string, std::string, int, int, int)>;

class MinimumCostToMakeTwoBinaryStringsEqualSolution
    : public SolutionBase<Func> {
 public:
  MinimumCostToMakeTwoBinaryStringsEqualSolution();

  long long minimumCost(std::string s, std::string t, int flipCost,
                        int swapCost, int crossCost);
};

}  // namespace problem_3800
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_COST_TO_MAKE_TWO_BINARY_STRINGS_EQUAL_H__
