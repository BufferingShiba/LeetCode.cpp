#ifndef LEETCODE_PROBLEMS_FIND_PEAK_ELEMENT_H__
#define LEETCODE_PROBLEMS_FIND_PEAK_ELEMENT_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_162 {

using Func = std::function<int(std::vector<int>&)>;

class FindPeakElementSolution : public SolutionBase<Func> {
 public:
  FindPeakElementSolution();

  int findPeakElement(std::vector<int>& nums);
};

}  // namespace leetcode::problem_162

#endif  // LEETCODE_PROBLEMS_FIND_PEAK_ELEMENT_H__
