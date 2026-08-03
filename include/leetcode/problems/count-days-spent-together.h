#ifndef LEETCODE_PROBLEMS_COUNT_DAYS_SPENT_TOGETHER_H__
#define LEETCODE_PROBLEMS_COUNT_DAYS_SPENT_TOGETHER_H__

#include "leetcode/core.h"

#include <functional>
#include <string>

namespace leetcode {
namespace problem_2409 {

using Func = std::function<int(std::string, std::string, std::string, std::string)>;

class CountDaysSpentTogetherSolution : public SolutionBase<Func> {
 public:
  CountDaysSpentTogetherSolution();

  int countDaysTogether(std::string arriveAlice, std::string leaveAlice,
                        std::string arriveBob, std::string leaveBob);
};

}  // namespace problem_2409
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COUNT_DAYS_SPENT_TOGETHER_H__
