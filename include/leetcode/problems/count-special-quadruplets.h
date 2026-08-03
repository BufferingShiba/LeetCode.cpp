#ifndef LEETCODE_PROBLEMS_COUNT_SPECIAL_QUADRUPLETS_H__
#define LEETCODE_PROBLEMS_COUNT_SPECIAL_QUADRUPLETS_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1995 {

using Func = std::function<int(std::vector<int>&)>;

class CountSpecialQuadrupletsSolution : public SolutionBase<Func> {
 public:
  CountSpecialQuadrupletsSolution();

  int countQuadruplets(std::vector<int>& nums);
};

}  // namespace problem_1995
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COUNT_SPECIAL_QUADRUPLETS_H__
