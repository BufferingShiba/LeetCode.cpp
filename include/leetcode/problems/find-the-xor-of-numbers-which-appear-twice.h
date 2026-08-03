#ifndef LEETCODE_PROBLEM_3158_H
#define LEETCODE_PROBLEM_3158_H

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3158 {

using Func = std::function<int(std::vector<int>&)>;

class FindTheXorOfNumbersWhichAppearTwiceSolution : public SolutionBase<Func> {
 public:
  FindTheXorOfNumbersWhichAppearTwiceSolution();

  int duplicateNumbersXOR(std::vector<int>& nums);
};

}  // namespace problem_3158
}  // namespace leetcode

#endif
