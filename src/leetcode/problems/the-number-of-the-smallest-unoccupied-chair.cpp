#include "leetcode/problems/the-number-of-the-smallest-unoccupied-chair.h"

#include <algorithm>
#include <queue>
#include <tuple>
#include <vector>

namespace leetcode::problem_1942 {

namespace {

int smallestChairImpl(std::vector<std::vector<int>>& times, int targetFriend) {
  int n = times.size();
  std::vector<std::tuple<int, int, int>> friends;
  friends.reserve(n);
  for (int i = 0; i < n; ++i) {
    friends.emplace_back(times[i][0], times[i][1], i);
  }

  // Sort by arrival time
  std::sort(friends.begin(), friends.end(),
            [](const auto& a, const auto& b) {
              return std::get<0>(a) < std::get<0>(b);
            });

  // Min-heap of available chair numbers
  std::priority_queue<int, std::vector<int>, std::greater<int>> available;
  // Min-heap of occupied chairs: (leaving_time, chair_number)
  std::priority_queue<std::pair<int, int>,
                      std::vector<std::pair<int, int>>,
                      std::greater<>>
      occupied;

  int nextChair = 0;

  for (const auto& [arrival, leaving, idx] : friends) {
    // Release all chairs whose friend leaves at or before current arrival
    while (!occupied.empty() && occupied.top().first <= arrival) {
      available.push(occupied.top().second);
      occupied.pop();
    }

    int chair;
    if (!available.empty()) {
      chair = available.top();
      available.pop();
    } else {
      chair = nextChair++;
    }

    if (idx == targetFriend) {
      return chair;
    }

    occupied.emplace(leaving, chair);
  }

  return -1;  // Should never reach here
}

}  // namespace

TheNumberOfTheSmallestUnoccupiedChairSolution::
    TheNumberOfTheSmallestUnoccupiedChairSolution() {
  setMetaInfo({.id = 1942,
               .title = "The Number of the Smallest Unoccupied Chair",
               .url = "https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/"});
  registerStrategy({.name = "EventSimulation",
                    .expected = "Accepted",
                    .time_complexity = "O(n log n)",
                    .space_complexity = "O(n)",
                    .tags = {"Array", "Heap", "Sorting"}},
                   smallestChairImpl);
}

int TheNumberOfTheSmallestUnoccupiedChairSolution::smallestChair(
    std::vector<std::vector<int>>& times, int targetFriend) {
  return getSolution()(times, targetFriend);
}

}  // namespace leetcode::problem_1942
