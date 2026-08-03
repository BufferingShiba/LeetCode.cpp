#ifndef LEETCODE_PROBLEMS_SMALLEST_VALUE_OF_THE_REARRANGED_NUMBER_H
#define LEETCODE_PROBLEMS_SMALLEST_VALUE_OF_THE_REARRANGED_NUMBER_H

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2165 {

using Func = std::function<long long(long long)>;

class SmallestValueOfTheRearrangedNumberSolution : public SolutionBase<Func> {
 public:
  SmallestValueOfTheRearrangedNumberSolution();

  long long smallestNumber(long long num);
};

}  // namespace problem_2165
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SMALLEST_VALUE_OF_THE_REARRANGED_NUMBER_H
