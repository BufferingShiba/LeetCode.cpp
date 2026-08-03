#ifndef LEETCODE_PROBLEM_1437_H
#define LEETCODE_PROBLEM_1437_H

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1437 {

using Func = std::function<bool(std::vector<int>&, int)>;

class CheckIfAll1sAreAtLeastLengthKPlacesAwaySolution : public SolutionBase<Func> {
 public:
  CheckIfAll1sAreAtLeastLengthKPlacesAwaySolution();

  bool kLengthApart(std::vector<int>& nums, int k);
};

}  // namespace problem_1437
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_1437_H
