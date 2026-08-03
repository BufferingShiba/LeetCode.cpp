#ifndef LEETCODE_PROBLEMS_LATEST_TIME_BY_REPLACING_HIDDEN_DIGITS_H__
#define LEETCODE_PROBLEMS_LATEST_TIME_BY_REPLACING_HIDDEN_DIGITS_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1736 {

using Func = std::function<std::string(std::string)>;

class LatestTimeByReplacingHiddenDigitsSolution : public SolutionBase<Func> {
 public:
  LatestTimeByReplacingHiddenDigitsSolution();

  std::string maximumTime(std::string time);
};

}  // namespace problem_1736
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_LATEST_TIME_BY_REPLACING_HIDDEN_DIGITS_H__
