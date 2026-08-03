#include "leetcode/problems/alternating-groups-i.h"

namespace leetcode {
namespace problem_3206 {

namespace {

int numberOfAlternatingGroupsImpl(std::vector<int>& colors) {
  const int n = static_cast<int>(colors.size());
  int count = 0;
  for (int i = 0; i < n; ++i) {
    if (colors[i] != colors[(i + 1) % n] &&
        colors[(i + 1) % n] != colors[(i + 2) % n]) {
      ++count;
    }
  }
  return count;
}

}  // namespace

AlternatingGroupsISolution::AlternatingGroupsISolution() {
  setMetaInfo({.id = 3206,
               .title = "Alternating Groups I",
               .url = "https://leetcode.com/problems/alternating-groups-i/"});
  registerStrategy({"Sliding Window", "Accepted", "O(n)", "O(1)",
                    {"Array", "Sliding Window"}},
                   numberOfAlternatingGroupsImpl);
}

int AlternatingGroupsISolution::numberOfAlternatingGroups(
    std::vector<int>& colors) {
  return getSolution()(colors);
}

}  // namespace problem_3206
}  // namespace leetcode
