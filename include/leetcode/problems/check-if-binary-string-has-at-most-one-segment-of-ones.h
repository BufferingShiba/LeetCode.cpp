#ifndef LEETCODE_PROBLEM_1784_H_
#define LEETCODE_PROBLEM_1784_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1784 {

using Func = std::function<bool(std::string)>;

class CheckIfBinaryStringHasAtMostOneSegmentOfOnesSolution : public SolutionBase<Func> {
 public:
  CheckIfBinaryStringHasAtMostOneSegmentOfOnesSolution();
  bool checkOnesSegment(std::string s);
};

}  // namespace problem_1784
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_1784_H_
