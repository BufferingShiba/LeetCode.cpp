#ifndef LEETCODE_PROBLEMS_COUNT_ELEMENTS_WITH_MAXIMUM_FREQUENCY_H__
#define LEETCODE_PROBLEMS_COUNT_ELEMENTS_WITH_MAXIMUM_FREQUENCY_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_3005 {

class CountElementsWithMaximumFrequencySolution
    : public SolutionBase<
          std::function<int(std::vector<int>&)>> {
 public:
  CountElementsWithMaximumFrequencySolution();

  int maxFrequencyElements(std::vector<int>& nums);
};

}  // namespace leetcode::problem_3005

#endif  // LEETCODE_PROBLEMS_COUNT_ELEMENTS_WITH_MAXIMUM_FREQUENCY_H__
