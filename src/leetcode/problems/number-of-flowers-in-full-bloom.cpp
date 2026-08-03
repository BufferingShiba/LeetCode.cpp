#include "leetcode/problems/number-of-flowers-in-full-bloom.h"

#include <algorithm>

namespace leetcode {
namespace problem_2251 {

namespace {

std::vector<int> fullBloomFlowersImpl(std::vector<std::vector<int>>& flowers,
                                      std::vector<int>& people) {
  std::vector<int> starts;
  std::vector<int> ends;  // end + 1
  starts.reserve(flowers.size());
  ends.reserve(flowers.size());
  for (const auto& f : flowers) {
    starts.push_back(f[0]);
    ends.push_back(f[1] + 1);
  }
  std::sort(starts.begin(), starts.end());
  std::sort(ends.begin(), ends.end());

  std::vector<int> answer;
  answer.reserve(people.size());
  for (int t : people) {
    int opened =
        static_cast<int>(std::upper_bound(starts.begin(), starts.end(), t) -
                         starts.begin());
    int closed =
        static_cast<int>(std::upper_bound(ends.begin(), ends.end(), t) -
                         ends.begin());
    answer.push_back(opened - closed);
  }
  return answer;
}

}  // namespace

NumberOfFlowersInFullBloomSolution::NumberOfFlowersInFullBloomSolution() {
  setMetaInfo({.id = 2251,
               .title = "Number of Flowers in Full Bloom",
               .url =
                   "https://leetcode.com/problems/number-of-flowers-in-full-bloom/"});
  registerStrategy(
      {.name = "differential-binary-search",
       .expected = "Accepted",
       .time_complexity = "O((n + m) log n)",
       .space_complexity = "O(n)",
       .tags = {"Sorting", "Binary Search", "Difference Array"}},
      fullBloomFlowersImpl);
}

std::vector<int> NumberOfFlowersInFullBloomSolution::fullBloomFlowers(
    std::vector<std::vector<int>>& flowers, std::vector<int>& people) {
  return getSolution()(flowers, people);
}

}  // namespace problem_2251
}  // namespace leetcode
