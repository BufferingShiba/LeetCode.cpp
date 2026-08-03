#ifndef LEETCODE_PROBLEMS_ROTATE_NON_NEGATIVE_ELEMENTS_H__
#define LEETCODE_PROBLEMS_ROTATE_NON_NEGATIVE_ELEMENTS_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3819 {

using Func = std::function<std::vector<int>(std::vector<int>&, int)>;

class RotateNonNegativeElementsSolution : public SolutionBase<Func> {
 public:
  RotateNonNegativeElementsSolution();

  std::vector<int> rotateElements(std::vector<int>& nums, int k);
};

}  // namespace problem_3819
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_ROTATE_NON_NEGATIVE_ELEMENTS_H__
