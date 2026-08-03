#include "leetcode/problems/average-waiting-time.h"

namespace leetcode {
namespace problem_1701 {

static double solution1(vector<vector<int>>& customers) {
  double totalWaiting = 0.0;
  long long current = 0;  // the time when chef finishes the previous order
  for (const auto& c : customers) {
    int arrival = c[0];
    int prep = c[1];
    // The chef starts once idle but not before the customer arrives.
    current = std::max(current, static_cast<long long>(arrival)) + prep;
    totalWaiting += current - arrival;
  }
  return totalWaiting / customers.size();
}

AverageWaitingTimeSolution::AverageWaitingTimeSolution() {
  setMetaInfo({
      .id = 1701,
      .title = "Average Waiting Time",
      .url = "https://leetcode.com/problems/average-waiting-time"
  });
  registerStrategy({.name = "Simulation"}, solution1);
}

double AverageWaitingTimeSolution::averageWaitingTime(vector<vector<int>>& customers) {
  return getSolution()(customers);
}

}  // namespace problem_1701
}  // namespace leetcode
