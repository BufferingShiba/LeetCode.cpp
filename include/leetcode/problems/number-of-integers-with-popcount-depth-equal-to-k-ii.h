#ifndef LEETCODE_PROBLEMS_NUMBER_OF_INTEGERS_WITH_POPCOUNT_DEPTH_EQUAL_TO_K_II_H_
#define LEETCODE_PROBLEMS_NUMBER_OF_INTEGERS_WITH_POPCOUNT_DEPTH_EQUAL_TO_K_II_H_

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_3624 {

using Func = std::function<std::vector<int>(std::vector<long long>&,
                                            std::vector<std::vector<long long>>&)>;

class NumberOfIntegersWithPopcountDepthEqualToKIiSolution
    : public SolutionBase<Func> {
 public:
  NumberOfIntegersWithPopcountDepthEqualToKIiSolution();

  std::vector<int> popcountDepth(std::vector<long long>& nums,
                                 std::vector<std::vector<long long>>& queries);
};

}  // namespace problem_3624
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_NUMBER_OF_INTEGERS_WITH_POPCOUNT_DEPTH_EQUAL_TO_K_II_H_
