#include "leetcode/problems/finding-the-users-active-minutes.h"

#include <unordered_map>
#include <unordered_set>

namespace leetcode {
namespace problem_1817 {

static std::vector<int> findingUsersActiveMinutesImpl(
    std::vector<std::vector<int>>& logs, int k) {
  std::unordered_map<int, std::unordered_set<int>> userMinutes;
  for (const auto& log : logs) {
    userMinutes[log[0]].insert(log[1]);
  }

  std::vector<int> answer(k, 0);
  for (const auto& [user, minutes] : userMinutes) {
    int uam = static_cast<int>(minutes.size());
    if (uam <= k) {
      answer[uam - 1]++;
    }
  }
  return answer;
}

FindingTheUsersActiveMinutesSolution::FindingTheUsersActiveMinutesSolution() {
  setMetaInfo({.id = 1817,
               .title = "Finding the Users Active Minutes",
               .url = "https://leetcode.com/problems/finding-the-users-active-minutes/"});
  registerStrategy(
      {.name = "HashMapWithSet",
       .expected = "Accepted",
       .time_complexity = "O(N)",
       .space_complexity = "O(N)",
       .tags = {"Hash Table", "Array"}},
      findingUsersActiveMinutesImpl);
}

std::vector<int> FindingTheUsersActiveMinutesSolution::findingUsersActiveMinutes(
    std::vector<std::vector<int>>& logs, int k) {
  return getSolution()(logs, k);
}

}  // namespace problem_1817
}  // namespace leetcode
