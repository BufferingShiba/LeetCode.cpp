#include "leetcode/problems/maximum-candies-you-can-get-from-boxes.h"

#include <queue>

namespace leetcode {
namespace problem_1298 {

static int maxCandiesImpl(std::vector<int>& status, std::vector<int>& candies,
                          std::vector<std::vector<int>>& keys,
                          std::vector<std::vector<int>>& containedBoxes,
                          std::vector<int>& initialBoxes) {
  int n = static_cast<int>(status.size());

  std::vector<bool> hasBox(n, false);
  std::vector<bool> hasKey(n, false);
  std::vector<bool> opened(n, false);

  // Initial boxes we own
  for (int b : initialBoxes) {
    hasBox[b] = true;
  }

  // Initially open boxes → we have their keys
  for (int i = 0; i < n; ++i) {
    if (status[i] == 1) {
      hasKey[i] = true;
    }
  }

  // Queue of boxes ready to open (have both box and key)
  std::queue<int> q;
  for (int i = 0; i < n; ++i) {
    if (hasBox[i] && hasKey[i]) {
      q.push(i);
      opened[i] = true;  // mark as being processed to avoid duplicates in queue
    }
  }

  int totalCandies = 0;

  while (!q.empty()) {
    int b = q.front();
    q.pop();

    // Collect candies from this box
    totalCandies += candies[b];

    // Process keys found in this box
    for (int k : keys[b]) {
      hasKey[k] = true;
      if (hasBox[k] && !opened[k]) {
        opened[k] = true;
        q.push(k);
      }
    }

    // Process boxes found inside this box
    for (int cb : containedBoxes[b]) {
      hasBox[cb] = true;
      if (hasKey[cb] && !opened[cb]) {
        opened[cb] = true;
        q.push(cb);
      }
    }
  }

  return totalCandies;
}

MaximumCandiesYouCanGetFromBoxesSolution::MaximumCandiesYouCanGetFromBoxesSolution() {
  setMetaInfo({.id = 1298,
               .title = "Maximum Candies You Can Get from Boxes",
               .url = "https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes/"});

  registerStrategy(
      {.name = "BFS",
       .expected = "Accepted",
       .time_complexity = "O(n + E)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Breadth-First Search", "Graph Theory"}},
      maxCandiesImpl);
}

int MaximumCandiesYouCanGetFromBoxesSolution::maxCandies(
    std::vector<int>& status, std::vector<int>& candies,
    std::vector<std::vector<int>>& keys,
    std::vector<std::vector<int>>& containedBoxes,
    std::vector<int>& initialBoxes) {
  return getSolution()(status, candies, keys, containedBoxes, initialBoxes);
}

}  // namespace problem_1298
}  // namespace leetcode
