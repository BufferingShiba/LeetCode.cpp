#ifndef LEETCODE_PROBLEMS_FIND_THE_PEAKS_H__
#define LEETCODE_PROBLEMS_FIND_THE_PEAKS_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_2951 {

using Func = std::function<std::vector<int>(std::vector<int>&)>;

class FindThePeaksSolution : public SolutionBase<Func> {
 public:
  FindThePeaksSolution();

  std::vector<int> findPeaks(std::vector<int>& mountain);
};

}  // namespace leetcode::problem_2951

#endif  // LEETCODE_PROBLEMS_FIND_THE_PEAKS_H__
