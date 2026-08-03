#ifndef LEETCODE_PROBLEMS_SUM_OF_DIGIT_DIFFERENCES_OF_ALL_PAIRS_H_
#define LEETCODE_PROBLEMS_SUM_OF_DIGIT_DIFFERENCES_OF_ALL_PAIRS_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3153 {

using Func = std::function<long long(std::vector<int>&)>;

class SumOfDigitDifferencesOfAllPairsSolution : public SolutionBase<Func> {
 public:
  SumOfDigitDifferencesOfAllPairsSolution();

  long long sumDigitDifferences(std::vector<int>& nums);
};

}  // namespace problem_3153
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SUM_OF_DIGIT_DIFFERENCES_OF_ALL_PAIRS_H_
