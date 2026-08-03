#include "leetcode/problems/magnetic-force-between-two-balls.h"

#include <algorithm>

namespace leetcode {
namespace problem_1552 {

namespace {

bool canPlace(const std::vector<int>& position, int m, int minDist) {
  int count = 1;
  int lastPos = position[0];
  for (size_t i = 1; i < position.size() && count < m; ++i) {
    if (position[i] - lastPos >= minDist) {
      ++count;
      lastPos = position[i];
    }
  }
  return count >= m;
}

int maxDistanceImpl(std::vector<int>& position, int m) {
  std::sort(position.begin(), position.end());
  int left = 1;
  int right = position.back() - position.front();
  int answer = 0;

  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (canPlace(position, m, mid)) {
      answer = mid;
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return answer;
}

}  // namespace

MagneticForceBetweenTwoBallsSolution::MagneticForceBetweenTwoBallsSolution() {
  setMetaInfo({.id = 1552,
               .title = "Magnetic Force Between Two Balls",
               .url = "https://leetcode.com/problems/magnetic-force-between-two-balls/"});
  registerStrategy(
      {.name = "Binary Search + Greedy",
       .expected = "Accepted",
       .time_complexity = "O(n log n + n log D)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Binary Search", "Sorting"}},
      maxDistanceImpl);
}

int MagneticForceBetweenTwoBallsSolution::maxDistance(
    std::vector<int>& position, int m) {
  return getSolution()(position, m);
}

}  // namespace problem_1552
}  // namespace leetcode
