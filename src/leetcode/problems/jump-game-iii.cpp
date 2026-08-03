#include "leetcode/problems/jump-game-iii.h"
#include <queue>

namespace leetcode {
namespace problem_1306 {

static bool canReachImpl(std::vector<int>& arr, int start) {
  int n = static_cast<int>(arr.size());
  std::vector<bool> visited(n, false);
  std::queue<int> q;
  q.push(start);
  visited[start] = true;

  while (!q.empty()) {
    int i = q.front();
    q.pop();

    if (arr[i] == 0) {
      return true;
    }

    int left = i - arr[i];
    if (left >= 0 && !visited[left]) {
      visited[left] = true;
      q.push(left);
    }

    int right = i + arr[i];
    if (right < n && !visited[right]) {
      visited[right] = true;
      q.push(right);
    }
  }

  return false;
}

JumpGameIiiSolution::JumpGameIiiSolution() {
  setMetaInfo({.id = 1306, .title = "Jump Game III", .url = "https://leetcode.com/problems/jump-game-iii/"});
  registerStrategy({
    .name = "BFS",
    .expected = "Accepted",
    .time_complexity = "O(n)",
    .space_complexity = "O(n)",
    .tags = {"Array", "Breadth-First Search"}
  }, canReachImpl);
}

bool JumpGameIiiSolution::canReach(std::vector<int>& arr, int start) {
  return getSolution()(arr, start);
}

}  // namespace problem_1306
}  // namespace leetcode
