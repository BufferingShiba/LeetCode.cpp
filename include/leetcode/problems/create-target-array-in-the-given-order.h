#ifndef LEETCODE_PROBLEMS_CREATE_TARGET_ARRAY_IN_THE_GIVEN_ORDER_H__
#define LEETCODE_PROBLEMS_CREATE_TARGET_ARRAY_IN_THE_GIVEN_ORDER_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1389 {

using Func =
    std::function<std::vector<int>(std::vector<int>&, std::vector<int>&)>;

class CreateTargetArrayInTheGivenOrderSolution
    : public SolutionBase<Func> {
 public:
  CreateTargetArrayInTheGivenOrderSolution();

  std::vector<int> createTargetArray(std::vector<int>& nums,
                                     std::vector<int>& index);
};

}  // namespace problem_1389
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CREATE_TARGET_ARRAY_IN_THE_GIVEN_ORDER_H__
