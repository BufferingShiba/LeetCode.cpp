// Find The Least Frequent Digit
#ifndef LEETCODE_PROBLEMS_FIND_THE_LEAST_FREQUENT_DIGIT_H__
#define LEETCODE_PROBLEMS_FIND_THE_LEAST_FREQUENT_DIGIT_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3663 {

class FindTheLeastFrequentDigitSolution
    : public SolutionBase<std::function<int(int)>> {
 public:
  FindTheLeastFrequentDigitSolution();
  int getLeastFrequentDigit(int n);
};

}  // namespace problem_3663
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_THE_LEAST_FREQUENT_DIGIT_H__
