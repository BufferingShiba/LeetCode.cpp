#ifndef LEETCODE_PROBLEMS_FIND_MAXIMUM_VALUE_IN_A_CONSTRAINED_SEQUENCE_H_
#define LEETCODE_PROBLEMS_FIND_MAXIMUM_VALUE_IN_A_CONSTRAINED_SEQUENCE_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3796 {

using Func = std::function<int(int, std::vector<std::vector<int>>&, std::vector<int>&)>;

class FindMaximumValueInAConstrainedSequenceSolution : public SolutionBase<Func> {
 public:
  FindMaximumValueInAConstrainedSequenceSolution();

  int findMaxVal(int n, std::vector<std::vector<int>>& restrictions,
                 std::vector<int>& diff);
};

}  // namespace problem_3796
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_MAXIMUM_VALUE_IN_A_CONSTRAINED_SEQUENCE_H_
