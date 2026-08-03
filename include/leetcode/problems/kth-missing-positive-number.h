#ifndef LEETCODE_PROBLEM_1539_H
#define LEETCODE_PROBLEM_1539_H

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1539 {

using Func = std::function<int(std::vector<int>&, int)>;

class KthMissingPositiveNumberSolution : public SolutionBase<Func> {
 public:
  KthMissingPositiveNumberSolution();

  int findKthPositive(std::vector<int>& arr, int k);
};

}  // namespace problem_1539
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_1539_H
