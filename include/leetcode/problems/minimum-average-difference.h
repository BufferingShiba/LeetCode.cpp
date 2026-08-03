#ifndef LEETCODE_PROBLEMS_2256_MINIMUM_AVERAGE_DIFFERENCE_H_
#define LEETCODE_PROBLEMS_2256_MINIMUM_AVERAGE_DIFFERENCE_H_

#include "leetcode/core.h"

#include <cstdlib>
#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_2256 {

using Func = std::function<int(std::vector<int>&)>;

class MinimumAverageDifferenceSolution : public SolutionBase<Func> {
 public:
  MinimumAverageDifferenceSolution();

  int minimumAverageDifference(std::vector<int>& nums) {
    return getSolution()(nums);
  }
};

}  // namespace problem_2256
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_2256_MINIMUM_AVERAGE_DIFFERENCE_H_
