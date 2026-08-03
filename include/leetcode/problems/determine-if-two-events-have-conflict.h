#ifndef LEETCODE_PROBLEMS_DETERMINE_IF_TWO_EVENTS_HAVE_CONFLICT_H__
#define LEETCODE_PROBLEMS_DETERMINE_IF_TWO_EVENTS_HAVE_CONFLICT_H__

#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2446 {

using Func = std::function<bool(std::vector<std::string>&, std::vector<std::string>&)>;

class DetermineIfTwoEventsHaveConflictSolution
    : public SolutionBase<Func> {
 public:
  DetermineIfTwoEventsHaveConflictSolution();

  bool haveConflict(std::vector<std::string>& event1,
                    std::vector<std::string>& event2);
};

}  // namespace problem_2446
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_DETERMINE_IF_TWO_EVENTS_HAVE_CONFLICT_H__
