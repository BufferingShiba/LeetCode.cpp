#ifndef LEETCODE_PROBLEMS_NUMBER_OF_PAIRS_OF_STRINGS_WITH_CONCATENATION_EQUAL_TO_TARGET_H__
#define LEETCODE_PROBLEMS_NUMBER_OF_PAIRS_OF_STRINGS_WITH_CONCATENATION_EQUAL_TO_TARGET_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_2023 {

using Func = std::function<int(std::vector<std::string>&, std::string)>;

class NumberOfPairsOfStringsWithConcatenationEqualToTargetSolution
    : public SolutionBase<Func> {
 public:
  NumberOfPairsOfStringsWithConcatenationEqualToTargetSolution();

  int numOfPairs(std::vector<std::string>& nums, std::string target);
};

}  // namespace problem_2023
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_NUMBER_OF_PAIRS_OF_STRINGS_WITH_CONCATENATION_EQUAL_TO_TARGET_H__
