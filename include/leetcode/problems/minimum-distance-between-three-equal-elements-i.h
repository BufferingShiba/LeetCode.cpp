#ifndef LEETCODE_PROBLEMS_MINIMUM_DISTANCE_BETWEEN_THREE_EQUAL_ELEMENTS_I_H__
#define LEETCODE_PROBLEMS_MINIMUM_DISTANCE_BETWEEN_THREE_EQUAL_ELEMENTS_I_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3740 {

using Func = std::function<int(std::vector<int>&)>;

class MinimumDistanceBetweenThreeEqualElementsISolution
    : public SolutionBase<Func> {
 public:
  int minimumDistance(std::vector<int>& nums);

  MinimumDistanceBetweenThreeEqualElementsISolution();
};

}  // namespace problem_3740
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_DISTANCE_BETWEEN_THREE_EQUAL_ELEMENTS_I_H__
