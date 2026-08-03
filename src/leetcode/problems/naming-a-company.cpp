#include "leetcode/problems/naming-a-company.h"

#include <string>
#include <unordered_set>
#include <vector>

namespace leetcode::problem_2306 {

static long long distinctNamesImpl(std::vector<std::string>& ideas) {
  std::vector<std::unordered_set<std::string>> groups(26);
  for (const auto& idea : ideas) {
    groups[idea[0] - 'a'].insert(idea.substr(1));
  }

  long long ans = 0;
  for (int i = 0; i < 26; ++i) {
    if (groups[i].empty()) continue;
    for (int j = i + 1; j < 26; ++j) {
      if (groups[j].empty()) continue;

      // Count intersection by iterating the smaller set
      const auto& smaller =
          groups[i].size() < groups[j].size() ? groups[i] : groups[j];
      const auto& larger =
          groups[i].size() < groups[j].size() ? groups[j] : groups[i];

      int common = 0;
      for (const auto& suffix : smaller) {
        if (larger.count(suffix)) {
          ++common;
        }
      }

      long long count_i = static_cast<long long>(groups[i].size()) - common;
      long long count_j = static_cast<long long>(groups[j].size()) - common;
      ans += 2LL * count_i * count_j;
    }
  }

  return ans;
}

NamingACompanySolution::NamingACompanySolution() {
  setMetaInfo(
      {.id = 2306,
       .title = "Naming a Company",
       .url = "https://leetcode.com/problems/naming-a-company/"});
  registerStrategy(
      {.name = "HashSetByFirstLetter",
       .expected = "Accepted",
       .time_complexity = "O(N * L + 26^2 * L)",
       .space_complexity = "O(N * L)",
       .tags = {"Hash Table", "String", "Enumeration"}},
      distinctNamesImpl);
  setDefaultStrategy();
}

long long NamingACompanySolution::distinctNames(
    std::vector<std::string>& ideas) {
  return getSolution()(ideas);
}

}  // namespace leetcode::problem_2306
