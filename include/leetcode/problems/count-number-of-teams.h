#ifndef LEETCODE_PROBLEMS_COUNT_NUMBER_OF_TEAMS_H_
#define LEETCODE_PROBLEMS_COUNT_NUMBER_OF_TEAMS_H_

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_1395 {

using Func = std::function<int(std::vector<int>&)>;

class CountNumberOfTeamsSolution
    : public SolutionBase<Func> {
 public:
  CountNumberOfTeamsSolution();

  int numTeams(std::vector<int>& rating);
};

}  // namespace problem_1395
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COUNT_NUMBER_OF_TEAMS_H_
