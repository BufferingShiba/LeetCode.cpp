#ifndef LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_SECONDS_TO_MAKE_MOUNTAIN_HEIGHT_ZERO_H__
#define LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_SECONDS_TO_MAKE_MOUNTAIN_HEIGHT_ZERO_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3296 {

using Func = std::function<long long(int, std::vector<int>&)>;

class MinimumNumberOfSecondsToMakeMountainHeightZeroSolution
    : public SolutionBase<Func> {
 public:
  MinimumNumberOfSecondsToMakeMountainHeightZeroSolution();

  long long minNumberOfSeconds(int mountainHeight, std::vector<int>& workerTimes);
};

}  // namespace problem_3296
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_SECONDS_TO_MAKE_MOUNTAIN_HEIGHT_ZERO_H__
