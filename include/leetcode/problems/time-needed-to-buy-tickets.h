#ifndef LEETCODE_PROBLEMS_TIME_NEEDED_TO_BUY_TICKETS_H_
#define LEETCODE_PROBLEMS_TIME_NEEDED_TO_BUY_TICKETS_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2073 {

using Func = std::function<int(std::vector<int>&, int)>;

class TimeNeededToBuyTicketsSolution : public SolutionBase<Func> {
 public:
  TimeNeededToBuyTicketsSolution();
  int timeRequiredToBuy(std::vector<int>& tickets, int k);
};

}  // namespace problem_2073
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_TIME_NEEDED_TO_BUY_TICKETS_H_
