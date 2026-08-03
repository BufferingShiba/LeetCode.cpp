#include "leetcode/problems/smallest-sufficient-team.h"

#include <algorithm>
#include <cstdint>
#include <limits>
#include <unordered_map>

namespace leetcode {
namespace problem_1125 {

namespace {

std::vector<int> smallestSufficientTeamImpl(
    std::vector<std::string>& req_skills,
    std::vector<std::vector<std::string>>& people) {
  const int skill_count = static_cast<int>(req_skills.size());
  const int state_count = 1 << skill_count;
  const int full_mask = state_count - 1;

  std::unordered_map<std::string, int> skill_id;
  for (int i = 0; i < skill_count; ++i) {
    skill_id.emplace(req_skills[i], i);
  }

  std::vector<int> person_masks;
  person_masks.reserve(people.size());
  for (const auto& person : people) {
    int mask = 0;
    for (const auto& skill : person) {
      const auto it = skill_id.find(skill);
      if (it != skill_id.end()) {
        mask |= 1 << it->second;
      }
    }
    person_masks.push_back(mask);
  }

  constexpr int kInf = std::numeric_limits<int>::max() / 4;
  std::vector<int> size(state_count, kInf);
  std::vector<std::uint64_t> team(state_count, 0);
  size[0] = 0;

  // Use a fresh state array for every person so no person can be selected
  // more than once.  The bitset stores original people indices directly.
  for (int person_index = 0;
       person_index < static_cast<int>(person_masks.size()); ++person_index) {
    const int person_mask = person_masks[person_index];
    const std::uint64_t person_bit = std::uint64_t{1} << person_index;
    const auto previous_size = size;
    const auto previous_team = team;

    for (int mask = 0; mask < state_count; ++mask) {
      if (previous_size[mask] == kInf) {
        continue;
      }
      const int next_mask = mask | person_mask;
      const int candidate_size = previous_size[mask] + 1;
      if (candidate_size < size[next_mask]) {
        size[next_mask] = candidate_size;
        team[next_mask] = previous_team[mask] | person_bit;
      }
    }
  }

  std::vector<int> answer;
  if (size[full_mask] == kInf) {
    return answer;
  }
  const std::uint64_t selected = team[full_mask];
  for (int i = 0; i < static_cast<int>(people.size()); ++i) {
    if ((selected & (std::uint64_t{1} << i)) != 0) {
      answer.push_back(i);
    }
  }
  return answer;
}

}  // namespace

SmallestSufficientTeamSolution::SmallestSufficientTeamSolution() {
  setMetaInfo({.id = 1125,
               .title = "Smallest Sufficient Team",
               .url = "https://leetcode.com/problems/smallest-sufficient-team/"});
  registerStrategy(
      {.name = "bitmask_dp",
       .expected = "Accepted",
       .time_complexity = "O(people * 2^skills)",
       .space_complexity = "O(2^skills)",
       .tags = {"Dynamic Programming", "Bitmask"},
       .notes = "Keep original people indices in a uint64_t team mask."},
      smallestSufficientTeamImpl);
}

std::vector<int> SmallestSufficientTeamSolution::smallestSufficientTeam(
    std::vector<std::string>& req_skills,
    std::vector<std::vector<std::string>>& people) {
  return getSolution()(req_skills, people);
}

}  // namespace problem_1125
}  // namespace leetcode
