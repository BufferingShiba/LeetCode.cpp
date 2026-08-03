#ifndef LEETCODE_PROBLEMS_CONSTRUCT_UNIFORM_PARITY_ARRAY_II_H__
#define LEETCODE_PROBLEMS_CONSTRUCT_UNIFORM_PARITY_ARRAY_II_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3876 {

using Func = std::function<bool(std::vector<int>&)>;

class ConstructUniformParityArrayIiSolution : public SolutionBase<Func> {
 public:
  ConstructUniformParityArrayIiSolution();
  bool uniformArray(std::vector<int>& nums1);
};

}  // namespace problem_3876
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CONSTRUCT_UNIFORM_PARITY_ARRAY_II_H__
