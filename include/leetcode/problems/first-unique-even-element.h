#ifndef LEETCODE_PROBLEM_3866_H_
#define LEETCODE_PROBLEM_3866_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3866 {

using Func = std::function<int(std::vector<int>&)>;

class FirstUniqueEvenElementSolution : public SolutionBase<Func> {
 public:
  FirstUniqueEvenElementSolution();

  int firstUniqueEven(std::vector<int>& nums);
};

}  // namespace problem_3866
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_3866_H_
