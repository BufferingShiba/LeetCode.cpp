#include "leetcode/problems/shortest-impossible-sequence-of-rolls.h"

#include <vector>

namespace leetcode {
namespace problem_2350 {

static int shortestSequenceImpl(std::vector<int>& rolls, int k) {
  int ans = 0;
  std::vector<bool> seen(static_cast<size_t>(k) + 1, false);
  int count = 0;
  for (int x : rolls) {
    if (!seen[x]) {
      seen[x] = true;
      ++count;
      if (count == k) {
        ++ans;
        std::fill(seen.begin(), seen.end(), false);
        count = 0;
      }
    }
  }
  return ans + 1;
}

ShortestImpossibleSequenceOfRollsSolution::ShortestImpossibleSequenceOfRollsSolution() {
  setMetaInfo({.id = 2350,
               .title = "Shortest Impossible Sequence of Rolls",
               .url = "https://leetcode.com/problems/shortest-impossible-sequence-of-rolls/"});
  registerStrategy({.name = "Greedy",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(k)",
                    .tags = {"Array", "Hash Table", "Greedy"}},
                   shortestSequenceImpl);
}

int ShortestImpossibleSequenceOfRollsSolution::shortestSequence(std::vector<int>& rolls, int k) {
  return getSolution()(rolls, k);
}

}  // namespace problem_2350
}  // namespace leetcode
