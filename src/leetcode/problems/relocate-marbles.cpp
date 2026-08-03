#include "leetcode/problems/relocate-marbles.h"

#include <algorithm>
#include <unordered_set>
#include <vector>

namespace leetcode {
namespace problem_2766 {

std::vector<int> RelocateMarblesSolution::relocateMarblesImpl(
    std::vector<int>& nums, std::vector<int>& moveFrom, std::vector<int>& moveTo) {
  std::unordered_set<int> occupied(nums.begin(), nums.end());

  for (std::size_t i = 0; i < moveFrom.size(); ++i) {
    occupied.erase(moveFrom[i]);
    occupied.insert(moveTo[i]);
  }

  std::vector<int> result(occupied.begin(), occupied.end());
  std::sort(result.begin(), result.end());
  return result;
}

}  // namespace problem_2766
}  // namespace leetcode
