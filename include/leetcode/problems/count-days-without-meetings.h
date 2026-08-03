#ifndef LEETCODE_PROBLEMS_COUNT_DAYS_WITHOUT_MEETINGS_H_
#define LEETCODE_PROBLEMS_COUNT_DAYS_WITHOUT_MEETINGS_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3169 {

using Func = std::function<int(int, std::vector<std::vector<int>>&)>;

class CountDaysWithoutMeetingsSolution : public SolutionBase<Func> {
 public:
  CountDaysWithoutMeetingsSolution();

  int countDays(int days, std::vector<std::vector<int>>& meetings);
};

}  // namespace problem_3169
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COUNT_DAYS_WITHOUT_MEETINGS_H_
