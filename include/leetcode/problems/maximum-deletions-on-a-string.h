#ifndef LEETCODE_PROBLEMS_MAXIMUM_DELETIONS_ON_A_STRING_H__
#define LEETCODE_PROBLEMS_MAXIMUM_DELETIONS_ON_A_STRING_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_2430 {

using Func = std::function<int(const std::string&)>;

class MaximumDeletionsOnAStringSolution
    : public SolutionBase<Func> {
 public:
  MaximumDeletionsOnAStringSolution();
  int deleteString(const std::string& s);
};

}  // namespace leetcode::problem_2430

#endif  // LEETCODE_PROBLEMS_MAXIMUM_DELETIONS_ON_A_STRING_H__
