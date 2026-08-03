#ifndef LEETCODE_PROBLEMS_MAXIMUM_SCORE_AFTER_SPLITTING_A_STRING_H__
#define LEETCODE_PROBLEMS_MAXIMUM_SCORE_AFTER_SPLITTING_A_STRING_H__

#include "leetcode/core.h"

#include <functional>
#include <string>

namespace leetcode {
namespace problem_1422 {

using Func = std::function<int(std::string)>;

class MaximumScoreAfterSplittingAString : public SolutionBase<Func> {
 public:
  MaximumScoreAfterSplittingAString();
  int maxScore(std::string s);
};

// 框架要求的测试用 Solution 类。
class MaximumScoreAfterSplittingAStringSolution
    : public MaximumScoreAfterSplittingAString {
 public:
  using MaximumScoreAfterSplittingAString::MaximumScoreAfterSplittingAString;
};

}  // namespace problem_1422
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_SCORE_AFTER_SPLITTING_A_STRING_H__
