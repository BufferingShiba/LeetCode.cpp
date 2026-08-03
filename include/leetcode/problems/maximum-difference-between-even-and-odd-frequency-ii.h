#ifndef LEETCODE_PROBLEMS_MAXIMUM_DIFFERENCE_BETWEEN_EVEN_AND_ODD_FREQUENCY_II_H
#define LEETCODE_PROBLEMS_MAXIMUM_DIFFERENCE_BETWEEN_EVEN_AND_ODD_FREQUENCY_II_H

#include "leetcode/core.h"

#include <functional>
#include <string>

namespace leetcode::problem_3445 {

using Func = std::function<int(std::string, int)>;

class MaximumDifferenceBetweenEvenAndOddFrequencyIiSolution
    : public SolutionBase<Func> {
 public:
  MaximumDifferenceBetweenEvenAndOddFrequencyIiSolution();

  int maxDifference(std::string s, int k);
};

}  // namespace leetcode::problem_3445

#endif  // LEETCODE_PROBLEMS_MAXIMUM_DIFFERENCE_BETWEEN_EVEN_AND_ODD_FREQUENCY_II_H
