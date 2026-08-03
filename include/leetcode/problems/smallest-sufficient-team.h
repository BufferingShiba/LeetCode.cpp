#ifndef LEETCODE_PROBLEMS_SMALLEST_SUFFICIENT_TEAM_H__
#define LEETCODE_PROBLEMS_SMALLEST_SUFFICIENT_TEAM_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_1125 {

using Func = std::function<std::vector<int>(
    std::vector<std::string>&, std::vector<std::vector<std::string>>&)>;

class SmallestSufficientTeamSolution : public SolutionBase<Func> {
 public:
  SmallestSufficientTeamSolution();
  std::vector<int> smallestSufficientTeam(
      std::vector<std::string>& req_skills,
      std::vector<std::vector<std::string>>& people);
};

}  // namespace problem_1125
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SMALLEST_SUFFICIENT_TEAM_H__
