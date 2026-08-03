#ifndef LEETCODE_PROBLEMS_K_RADIUS_SUBARRAY_AVERAGES_H__
#define LEETCODE_PROBLEMS_K_RADIUS_SUBARRAY_AVERAGES_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2090 {

using Func = std::function<std::vector<int>(std::vector<int>&, int)>;

class KRadiusSubarrayAveragesSolution
    : public SolutionBase<Func> {
 public:
  KRadiusSubarrayAveragesSolution();

  std::vector<int> getAverages(std::vector<int>& nums, int k) {
    return getSolution()(nums, k);
  }
};

}  // namespace problem_2090
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_K_RADIUS_SUBARRAY_AVERAGES_H__
