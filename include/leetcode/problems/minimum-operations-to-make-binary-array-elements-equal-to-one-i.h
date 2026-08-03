#ifndef LEEETCODE_PROBLEMS_MINIMUM_OPERATIONS_TO_MAKE_BINARY_ARRAY_ELEMENTS_EQUAL_TO_ONE_I_H__
#define LEEETCODE_PROBLEMS_MINIMUM_OPERATIONS_TO_MAKE_BINARY_ARRAY_ELEMENTS_EQUAL_TO_ONE_I_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3191 {

using Func = std::function<int(std::vector<int>&)>;

class MinimumOperationsToMakeBinaryArrayElementsEqualToOneISolution
    : public SolutionBase<Func> {
 public:
  int minOperations(std::vector<int>& nums);

  MinimumOperationsToMakeBinaryArrayElementsEqualToOneISolution();
};

}  // namespace problem_3191
}  // namespace leetcode

#endif  // LEEETCODE_PROBLEMS_MINIMUM_OPERATIONS_TO_MAKE_BINARY_ARRAY_ELEMENTS_EQUAL_TO_ONE_I_H__
