#ifndef LEETCODE_PROBLEMS_COUNT_OF_MATCHES_IN_TOURNAMENT_H__
#define LEETCODE_PROBLEMS_COUNT_OF_MATCHES_IN_TOURNAMENT_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_1688 {

using Func = std::function<int(int)>;

class CountOfMatchesInTournamentSolution : public SolutionBase<Func> {
 public:
  CountOfMatchesInTournamentSolution();
};

}  // namespace problem_1688
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COUNT_OF_MATCHES_IN_TOURNAMENT_H__
