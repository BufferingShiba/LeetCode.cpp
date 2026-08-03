#ifndef LEETCODE_PROBLEMS_CHECK_IF_ALL_AS_APPEARS_BEFORE_ALL_BS_H__
#define LEETCODE_PROBLEMS_CHECK_IF_ALL_AS_APPEARS_BEFORE_ALL_BS_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2124 {

using Func = std::function<bool(std::string)>;

class CheckIfAllAsAppearsBeforeAllBsSolution
    : public SolutionBase<Func> {
 public:
  CheckIfAllAsAppearsBeforeAllBsSolution();

  bool checkString(std::string s);
};

}  // namespace problem_2124
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CHECK_IF_ALL_AS_APPEARS_BEFORE_ALL_BS_H__
