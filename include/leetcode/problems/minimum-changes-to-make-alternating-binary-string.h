#ifndef LEETCODE_PROBLEMS_MINIMUM_CHANGES_TO_MAKE_ALTERNATING_BINARY_STRING_H_
#define LEETCODE_PROBLEMS_MINIMUM_CHANGES_TO_MAKE_ALTERNATING_BINARY_STRING_H_

#include <functional>
#include <string>
#include "leetcode/core.h"

namespace leetcode {
namespace problem_1758 {

using Func = std::function<int(std::string)>;

class MinimumChangesToMakeAlternatingBinaryStringSolution : public SolutionBase<Func> {
 public:
  int minOperations(std::string s);

  MinimumChangesToMakeAlternatingBinaryStringSolution();
};

}  // namespace problem_1758
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_CHANGES_TO_MAKE_ALTERNATING_BINARY_STRING_H_
