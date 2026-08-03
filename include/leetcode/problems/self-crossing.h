#ifndef LEETCODE_PROBLEM_335_SELF_CROSSING_H_
#define LEETCODE_PROBLEM_335_SELF_CROSSING_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_335 {

using Func = std::function<bool(std::vector<int>&)>;

class SelfCrossingSolution : public SolutionBase<Func> {
 public:
  SelfCrossingSolution();

  bool isSelfCrossing(std::vector<int>& distance);
};

}  // namespace problem_335
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_335_SELF_CROSSING_H_
