#ifndef LEETCODE_PROBLEM_MAXIMIZE_SUM_OF_DEVICE_RATINGS_H
#define LEETCODE_PROBLEM_MAXIMIZE_SUM_OF_DEVICE_RATINGS_H

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3961 {

using Func = std::function<long long(std::vector<std::vector<int>>&)>;

class MaximizeSumOfDeviceRatingsSolution : public SolutionBase<Func> {
 public:
  MaximizeSumOfDeviceRatingsSolution();

  long long maxRatings(std::vector<std::vector<int>>& units);
};

}  // namespace problem_3961
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_MAXIMIZE_SUM_OF_DEVICE_RATINGS_H
