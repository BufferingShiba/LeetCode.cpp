#include "leetcode/problems/daily-temperatures.h"

#include <stack>
#include <vector>

namespace leetcode {
namespace problem_739 {

namespace {

std::vector<int> dailyTemperaturesImpl(std::vector<int>& temperatures) {
  int n = static_cast<int>(temperatures.size());
  std::vector<int> answer(n, 0);
  std::stack<int> st;  // indices, temperatures decreasing

  for (int i = 0; i < n; ++i) {
    while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
      int prev = st.top();
      st.pop();
      answer[prev] = i - prev;
    }
    st.push(i);
  }

  return answer;
}

}  // namespace

DailyTemperaturesSolution::DailyTemperaturesSolution() {
  setMetaInfo({.id = 739,
               .title = "Daily Temperatures",
               .url = "https://leetcode.com/problems/daily-temperatures/"});

  registerStrategy(
      {.name = "Monotonic Stack",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Stack", "Monotonic Stack"}},
      dailyTemperaturesImpl);
}

std::vector<int> DailyTemperaturesSolution::dailyTemperatures(
    std::vector<int>& temperatures) {
  return getSolution()(temperatures);
}

}  // namespace problem_739
}  // namespace leetcode
