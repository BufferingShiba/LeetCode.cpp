#include "leetcode/problems/groups-of-special-equivalent-strings.h"

#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>

namespace leetcode {
namespace problem_893 {
namespace {

// Two strings are special-equivalent iff their even-index characters (sorted)
// match and their odd-index characters (sorted) match. Build a canonical key
// from the sorted even and odd subsequences and count distinct keys.
int numSpecialEquivGroupsImpl(std::vector<std::string>& words) {
  std::unordered_set<std::string> groups;
  for (const std::string& w : words) {
    std::string even;
    std::string odd;
    for (int i = 0; i < static_cast<int>(w.size()); i += 2) {
      even.push_back(w[i]);
    }
    for (int i = 1; i < static_cast<int>(w.size()); i += 2) {
      odd.push_back(w[i]);
    }
    std::sort(even.begin(), even.end());
    std::sort(odd.begin(), odd.end());
    groups.insert(even + "#" + odd);
  }
  return static_cast<int>(groups.size());
}

}  // namespace

GroupsOfSpecialEquivalentStringsSolution::GroupsOfSpecialEquivalentStringsSolution() {
  setMetaInfo({893, "Groups of Special-Equivalent Strings",
               "https://leetcode.com/problems/groups-of-special-equivalent-strings/"});
  registerStrategy(
      {.name = "canonical-key",
       .expected = "Accepted",
       .time_complexity = "O(n * L * log L)",
       .space_complexity = "O(n * L)",
       .tags = {"Array", "Hash Table", "String"}},
      numSpecialEquivGroupsImpl);
}

int GroupsOfSpecialEquivalentStringsSolution::numSpecialEquivGroups(
    std::vector<std::string>& words) {
  return getSolution()(words);
}

}  // namespace problem_893
}  // namespace leetcode
