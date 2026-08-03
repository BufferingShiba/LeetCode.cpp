#ifndef LEETCODE_PROBLEM_376_H_
#define LEETCODE_PROBLEM_376_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_376 {

using Func = std::function<int(std::vector<int>&)>;

class WiggleSubsequenceSolution : public SolutionBase<Func> {
 public:
  WiggleSubsequenceSolution();

  int wiggleMaxLength(std::vector<int>& nums);
};

}  // namespace problem_376
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_376_H_
