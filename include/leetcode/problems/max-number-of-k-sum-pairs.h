#ifndef LEETCODE_PROBLEMS_MAX_NUMBER_OF_K_SUM_PAIRS_H__
#define LEETCODE_PROBLEMS_MAX_NUMBER_OF_K_SUM_PAIRS_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_1679 {

using Func = std::function<int(std::vector<int>&, int)>;

class MaxNumberOfKSumPairsSolution
    : public SolutionBase<Func> {
 public:
  MaxNumberOfKSumPairsSolution();
  int maxOperations(std::vector<int>& nums, int k);
};

}  // namespace problem_1679
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAX_NUMBER_OF_K_SUM_PAIRS_H__
