#include "leetcode/problems/time-needed-to-buy-tickets.h"

#include <algorithm>

namespace leetcode {
namespace problem_2073 {

static int timeRequiredToBuyImpl(std::vector<int>& tickets, int k) {
  int target = tickets[k];
  int ans = 0;
  for (int i = 0; i < static_cast<int>(tickets.size()); ++i) {
    if (i <= k) {
      ans += std::min(tickets[i], target);
    } else {
      ans += std::min(tickets[i], target - 1);
    }
  }
  return ans;
}

TimeNeededToBuyTicketsSolution::TimeNeededToBuyTicketsSolution() {
  setMetaInfo({2073, "Time Needed to Buy Tickets",
               "https://leetcode.com/problems/time-needed-to-buy-tickets/"});
  registerStrategy({"math", "Accepted", "O(n)", "O(1)",
                     {"Array", "Queue", "Simulation"}, ""},
                    timeRequiredToBuyImpl);
}

int TimeNeededToBuyTicketsSolution::timeRequiredToBuy(std::vector<int>& tickets,
                                                      int k) {
  return getSolution()(tickets, k);
}

}  // namespace problem_2073
}  // namespace leetcode
