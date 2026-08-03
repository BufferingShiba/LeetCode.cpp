#ifndef LEETCODE_PROBLEMS_MINIMUM_TIME_DIFFERENCE_H__
#define LEETCODE_PROBLEMS_MINIMUM_TIME_DIFFERENCE_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_539 {

using Func = std::function<int(std::vector<std::string>&)>;

class MinimumTimeDifferenceSolution : public SolutionBase<Func> {
 public:
  MinimumTimeDifferenceSolution();

  int findMinDifference(std::vector<std::string>& timePoints);
};

}  // namespace problem_539
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_TIME_DIFFERENCE_H__
