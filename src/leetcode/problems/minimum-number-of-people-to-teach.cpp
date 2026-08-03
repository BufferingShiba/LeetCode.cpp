#include "leetcode/problems/minimum-number-of-people-to-teach.h"

#include <algorithm>
#include <utility>
#include <vector>

namespace leetcode {
namespace problem_1733 {

static int minimumTeachingsImpl(int n,
                                std::vector<std::vector<int>>& languages,
                                std::vector<std::vector<int>>& friendships) {
  int m = static_cast<int>(languages.size());

  // knows[i][l]: user i (1-indexed) knows language l (1-indexed)
  std::vector<std::vector<bool>> knows(m + 1,
                                       std::vector<bool>(n + 1, false));
  for (int i = 0; i < m; ++i) {
    for (int lang : languages[i]) {
      knows[i + 1][lang] = true;
    }
  }

  // Collect friendships that currently lack any common language
  std::vector<std::pair<int, int>> problematic;
  for (const auto& f : friendships) {
    int u = f[0];
    int v = f[1];
    bool common = false;
    for (int l = 1; l <= n; ++l) {
      if (knows[u][l] && knows[v][l]) {
        common = true;
        break;
      }
    }
    if (!common) {
      problematic.emplace_back(u, v);
    }
  }

  if (problematic.empty()) {
    return 0;
  }

  int ans = m;  // worst case: teach every user
  for (int lang = 1; lang <= n; ++lang) {
    std::vector<bool> need_teach(m + 1, false);
    int cnt = 0;
    for (auto [u, v] : problematic) {
      if (!knows[u][lang] && !need_teach[u]) {
        need_teach[u] = true;
        ++cnt;
      }
      if (!knows[v][lang] && !need_teach[v]) {
        need_teach[v] = true;
        ++cnt;
      }
    }
    ans = std::min(ans, cnt);
  }

  return ans;
}

MinimumNumberOfPeopleToTeachSolution::MinimumNumberOfPeopleToTeachSolution() {
  setMetaInfo(
      {.id = 1733,
       .title = "Minimum Number of People to Teach",
       .url = "https://leetcode.com/problems/minimum-number-of-people-to-teach/"});
  registerStrategy(
      {.name = "brute_force_language_selection",
       .expected = "Accepted",
       .time_complexity = "O(n * (m + f))",
       .space_complexity = "O(m * n)",
       .tags = {"Array", "Hash Table", "Greedy"}},
      minimumTeachingsImpl);
}

int MinimumNumberOfPeopleToTeachSolution::minimumTeachings(
    int n,
    std::vector<std::vector<int>>& languages,
    std::vector<std::vector<int>>& friendships) {
  return getSolution()(n, languages, friendships);
}

}  // namespace problem_1733
}  // namespace leetcode
