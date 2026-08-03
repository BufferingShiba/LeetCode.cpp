#include "leetcode/problems/successful-pairs-of-spells-and-potions.h"

#include <algorithm>

namespace leetcode {
namespace problem_2300 {

static vector<int> solution1(vector<int>& spells, vector<int>& potions, long long success) {
  // Sort potions so we can binary search the first potion that forms a
  // successful pair for each spell.
  std::sort(potions.begin(), potions.end());

  const int m = static_cast<int>(potions.size());
  vector<int> result;
  result.reserve(spells.size());

  for (int spell : spells) {
    // Need spell * potion >= success  =>  potion >= ceil(success / spell).
    long long need = (success + spell - 1) / spell;  // ceil(success / spell)
    // Lower bound: first potion >= need.
    auto it = std::lower_bound(potions.begin(), potions.end(), need);
    int count = m - static_cast<int>(it - potions.begin());
    result.push_back(count);
  }

  return result;
}

SuccessfulPairsOfSpellsAndPotionsSolution::SuccessfulPairsOfSpellsAndPotionsSolution() {
  setMetaInfo({
      .id = 2300,
      .title = "Successful Pairs of Spells and Potions",
      .url = "https://leetcode.com/problems/successful-pairs-of-spells-and-potions"
  });
  registerStrategy({.name = "Binary Search",
                    .time_complexity = "O(n log n + m log m)",
                    .space_complexity = "O(log m)",
                    .tags = {"Array", "Sorting", "Binary Search"}},
                   solution1);
}

vector<int> SuccessfulPairsOfSpellsAndPotionsSolution::successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
  return getSolution()(spells, potions, success);
}

}  // namespace problem_2300
}  // namespace leetcode
