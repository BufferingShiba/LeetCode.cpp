#ifndef LEETCODE_PROBLEMS_FIND_THE_ORIGINAL_TYPED_STRING_I_H__
#define LEETCODE_PROBLEMS_FIND_THE_ORIGINAL_TYPED_STRING_I_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3330 {

using Func = std::function<int(std::string)>;

class FindTheOriginalTypedStringISolution : public SolutionBase<Func> {
 public:
  FindTheOriginalTypedStringISolution();

  int possibleStringCount(std::string word);
};

}  // namespace problem_3330
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_THE_ORIGINAL_TYPED_STRING_I_H__
