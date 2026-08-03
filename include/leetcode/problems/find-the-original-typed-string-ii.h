#ifndef LEETCODE_PROBLEMS_FIND_THE_ORIGINAL_TYPED_STRING_II_H__
#define LEETCODE_PROBLEMS_FIND_THE_ORIGINAL_TYPED_STRING_II_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3333 {

using Func = std::function<int(std::string, int)>;

class FindTheOriginalTypedStringIiSolution : public SolutionBase<Func> {
 public:
  // Alias for public usage (framework requires this name).
  using Base = SolutionBase<Func>;

  FindTheOriginalTypedStringIiSolution();

  int possibleStringCount(std::string word, int k);
};

}  // namespace problem_3333
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_THE_ORIGINAL_TYPED_STRING_II_H__
