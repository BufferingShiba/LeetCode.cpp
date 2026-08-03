#include "leetcode/problems/find-the-longest-valid-obstacle-course-at-each-position.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_1964 {

static std::vector<int> longestObstacleCourseAtEachPositionImpl(
    std::vector<int>& obstacles) {
  std::vector<int> ans;
  ans.reserve(obstacles.size());

  std::vector<int> tails;
  tails.reserve(obstacles.size());

  for (int h : obstacles) {
    auto it = std::upper_bound(tails.begin(), tails.end(), h);
    int pos = static_cast<int>(it - tails.begin());
    ans.push_back(pos + 1);

    if (it == tails.end()) {
      tails.push_back(h);
    } else {
      *it = h;
    }
  }

  return ans;
}

FindTheLongestValidObstacleCourseAtEachPositionSolution::
    FindTheLongestValidObstacleCourseAtEachPositionSolution() {
  setMetaInfo({.id = 1964,
               .title = "Find the Longest Valid Obstacle Course at Each Position",
               .url = "https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/"});

  registerStrategy(
      {.name = "Binary Search (Patience Sorting)",
       .expected = "Accepted",
       .time_complexity = "O(n log n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Binary Search"}},
      longestObstacleCourseAtEachPositionImpl);
}

std::vector<int>
FindTheLongestValidObstacleCourseAtEachPositionSolution::
    longestObstacleCourseAtEachPosition(std::vector<int>& obstacles) {
  return getSolution()(obstacles);
}

}  // namespace problem_1964
}  // namespace leetcode
