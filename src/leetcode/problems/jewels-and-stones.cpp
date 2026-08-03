#include "leetcode/problems/jewels-and-stones.h"

#include <unordered_set>

namespace leetcode {
namespace problem_771 {

namespace {

int numJewelsInStonesImpl(std::string jewels, std::string stones) {
  std::unordered_set<char> jewelSet;
  for (char c : jewels) {
    jewelSet.insert(c);
  }
  int count = 0;
  for (char c : stones) {
    if (jewelSet.count(c)) {
      ++count;
    }
  }
  return count;
}

}  // namespace

JewelsAndStonesSolution::JewelsAndStonesSolution() {
  setMetaInfo({.id = 771,
               .title = "Jewels and Stones",
               .url = "https://leetcode.com/problems/jewels-and-stones/"});
  registerStrategy({.name = "hash_set",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(k)",
                    .tags = {"Hash Table", "String"}},
                   numJewelsInStonesImpl);
}

int JewelsAndStonesSolution::numJewelsInStones(std::string jewels,
                                                std::string stones) {
  return getSolution()(jewels, stones);
}

}  // namespace problem_771
}  // namespace leetcode
