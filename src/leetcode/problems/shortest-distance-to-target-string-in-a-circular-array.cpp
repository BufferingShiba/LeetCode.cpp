#include "leetcode/problems/shortest-distance-to-target-string-in-a-circular-array.h"

namespace leetcode::problem_2515 {

namespace {

int closestTargetImpl(std::vector<std::string>& words, const std::string& target,
                      int startIndex) {
  const int n = static_cast<int>(words.size());
  int best = -1;
  for (int i = 0; i < n; ++i) {
    if (words[i] == target) {
      int dist =
          std::min((i - startIndex + n) % n, (startIndex - i + n) % n);
      if (best == -1 || dist < best) {
        best = dist;
      }
    }
  }
  return best;
}

}  // namespace

ShortestDistanceToTargetStringInACircularArraySolution::
    ShortestDistanceToTargetStringInACircularArraySolution() {
  setMetaInfo({.id = 2515,
               .title = "Shortest Distance to Target String in a Circular "
                        "Array",
               .url = "https://leetcode.com/problems/"
                      "shortest-distance-to-target-string-in-a-circular-"
                      "array/"});

  registerStrategy(
      {.name = "linear_scan",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "String"}},
      [](std::vector<std::string>& words, std::string target,
         int startIndex) -> int {
        return closestTargetImpl(words, target, startIndex);
      });
}

int ShortestDistanceToTargetStringInACircularArraySolution::closestTarget(
    std::vector<std::string>& words, std::string target, int startIndex) {
  return getSolution()(words, target, startIndex);
}

}  // namespace leetcode::problem_2515
