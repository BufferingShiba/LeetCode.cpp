#ifndef LEETCODE_PROBLEMS_SPLITTING_A_STRING_INTO_DESCENDING_CONSECUTIVE_VALUES_H_
#define LEETCODE_PROBLEMS_SPLITTING_A_STRING_INTO_DESCENDING_CONSECUTIVE_VALUES_H_

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1849 {

using Func = std::function<bool(std::string)>;

class SplittingAStringIntoDescendingConsecutiveValuesSolution
    : public SolutionBase<Func> {
 public:
  SplittingAStringIntoDescendingConsecutiveValuesSolution();

  bool splitString(std::string s);
};

}  // namespace problem_1849
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SPLITTING_A_STRING_INTO_DESCENDING_CONSECUTIVE_VALUES_H_
