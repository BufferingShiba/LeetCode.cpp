#include "leetcode/problems/calculate-delayed-arrival-time.h"

namespace leetcode::problem_2651 {

CalculateDelayedArrivalTimeSolution& CalculateDelayedArrivalTimeSolution::shared() {
    static CalculateDelayedArrivalTimeSolution solution;
    return solution;
}

int CalculateDelayedArrivalTimeSolution::findDelayedArrivalTime(
    int arrivalTime, int delayedTime) {
    return getSolution()(arrivalTime, delayedTime);
}

static bool registered = []() {
    auto& solution = CalculateDelayedArrivalTimeSolution::shared();
    if (solution.getStrategyNames().empty()) {
        solution.setMetaInfo({2651, "Calculate Delayed Arrival Time",
                              "https://leetcode.com/problems/calculate-delayed-arrival-time/"});
        solution.registerStrategy(
            {"Modulo24", "Accepted", "O(1)", "O(1)", {"Math"}},
            [](int arrivalTime, int delayedTime) -> int {
                return (arrivalTime + delayedTime) % 24;
            });
    }
    return true;
}();

}  // namespace leetcode::problem_2651
