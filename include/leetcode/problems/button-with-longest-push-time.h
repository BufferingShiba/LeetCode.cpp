#ifndef LEETCODE_PROBLEMS_BUTTON_WITH_LONGEST_PUSH_TIME_H__
#define LEETCODE_PROBLEMS_BUTTON_WITH_LONGEST_PUSH_TIME_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_3386 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class ButtonWithLongestPushTimeSolution : public SolutionBase<Func> {
 public:
  ButtonWithLongestPushTimeSolution();

  int buttonWithLongestTime(std::vector<std::vector<int>>& events);
};

}  // namespace problem_3386
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_BUTTON_WITH_LONGEST_PUSH_TIME_H__
