#ifndef LEETCODE_PROBLEMS_DISTRIBUTE_REPEATING_INTEGERS_H__
#define LEETCODE_PROBLEMS_DISTRIBUTE_REPEATING_INTEGERS_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1655 {

using Func = std::function<bool(std::vector<int>&, std::vector<int>&)>;

class DistributeRepeatingIntegersSolution : public SolutionBase<Func> {
 public:
  DistributeRepeatingIntegersSolution();

  bool canDistribute(std::vector<int>& nums, std::vector<int>& quantity);
};

}  // namespace problem_1655
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_DISTRIBUTE_REPEATING_INTEGERS_H__
