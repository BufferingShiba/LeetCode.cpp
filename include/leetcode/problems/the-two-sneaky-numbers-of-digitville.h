#ifndef LEETCODE_PROBLEMS_THE_TWO_SNEAKY_NUMBERS_OF_DIGITVILLE_H__
#define LEETCODE_PROBLEMS_THE_TWO_SNEAKY_NUMBERS_OF_DIGITVILLE_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_3289 {

using Func = std::function<std::vector<int>(std::vector<int>&)>;

class TheTwoSneakyNumbersOfDigitvilleSolution : public SolutionBase<Func> {
 public:
  TheTwoSneakyNumbersOfDigitvilleSolution();

  std::vector<int> getSneakyNumbers(std::vector<int>& nums) {
    return getSolution()(nums);
  }
};

}  // namespace problem_3289
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_THE_TWO_SNEAKY_NUMBERS_OF_DIGITVILLE_H__
