#ifndef LEETCODE_PROBLEM_3588_H
#define LEETCODE_PROBLEM_3588_H

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3588 {

using Func = std::function<long long(std::vector<std::vector<int>>&)>;

class FindMaximumAreaOfATriangleSolution : public SolutionBase<Func> {
 public:
  FindMaximumAreaOfATriangleSolution();

  long long maxArea(std::vector<std::vector<int>>& coords);
};

}  // namespace problem_3588
}  // namespace leetcode

#endif
