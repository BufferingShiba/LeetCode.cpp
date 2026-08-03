#ifndef LEETCODE_PROBLEMS_MINIMUM_SUM_OF_MOUNTAIN_TRIPLETS_I_H__
#define LEETCODE_PROBLEMS_MINIMUM_SUM_OF_MOUNTAIN_TRIPLETS_I_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_2908 {

using Func = std::function<int(std::vector<int>&)>;

class MinimumSumOfMountainTripletsISolution : public SolutionBase<Func> {
 public:
  MinimumSumOfMountainTripletsISolution();

  int minimumSum(std::vector<int>& nums);
};

}  // namespace problem_2908
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_SUM_OF_MOUNTAIN_TRIPLETS_I_H__
