#ifndef LEETCODE_PROBLEM_567_PERMUTATION_IN_STRING_H_
#define LEETCODE_PROBLEM_567_PERMUTATION_IN_STRING_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_567 {

using Func = std::function<bool(std::string, std::string)>;

class PermutationInStringSolution : public SolutionBase<Func> {
 public:
  PermutationInStringSolution();

  bool checkInclusion(std::string s1, std::string s2);
};

}  // namespace problem_567
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_567_PERMUTATION_IN_STRING_H_
