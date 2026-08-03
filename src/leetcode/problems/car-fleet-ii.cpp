#include "leetcode/problems/car-fleet-ii.h"

namespace leetcode {
namespace problem_1776 {

namespace {

std::vector<double> getCollisionTimesImpl(std::vector<std::vector<int>>& cars) {
  const int n = static_cast<int>(cars.size());
  std::vector<double> answer(n, -1.0);
  // Stack holds indices of cars ahead. Process from right to left.
  std::vector<int> st;
  for (int i = n - 1; i >= 0; --i) {
    while (!st.empty()) {
      int j = st.back();
      double pos_i = cars[i][0], speed_i = cars[i][1];
      double pos_j = cars[j][0], speed_j = cars[j][1];
      if (speed_i <= speed_j) {
        // Car i can never catch car j (j is faster or equal and ahead).
        st.pop_back();
        continue;
      }
      double catchTime = (pos_j - pos_i) / (speed_i - speed_j);
      if (answer[j] != -1.0 && catchTime >= answer[j]) {
        // Car j will have already collided with cars further ahead before being
        // caught by car i; pop and compare against the merged fleet.
        st.pop_back();
        continue;
      }
      // Car i catches car j directly.
      answer[i] = catchTime;
      break;
    }
    st.push_back(i);
  }
  return answer;
}

}  // namespace

CarFleetIiSolution::CarFleetIiSolution() {
  setMetaInfo({.id = 1776,
               .title = "Car Fleet II",
               .url = "https://leetcode.com/problems/car-fleet-ii/"});
  registerStrategy(
      {.name = "monotonic-stack",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Stack", "Monotonic Stack", "Math"}},
      &getCollisionTimesImpl);
}

std::vector<double> CarFleetIiSolution::getCollisionTimes(
    std::vector<std::vector<int>>& cars) {
  return getSolution()(cars);
}

}  // namespace problem_1776
}  // namespace leetcode
