#ifndef LEETCODE_PROBLEMS_MINIMUM_STRING_LENGTH_AFTER_BALANCED_REMOVALS_H__
#define LEETCODE_PROBLEMS_MINIMUM_STRING_LENGTH_AFTER_BALANCED_REMOVALS_H__

#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3746 {

using Func = std::function<int(const std::string&)>;

class MinimumStringLengthAfterBalancedRemovalsSolution
    : public SolutionBase<Func> {
 public:
  MinimumStringLengthAfterBalancedRemovalsSolution();

  int minLengthAfterRemovals(const std::string& s);
};

}  // namespace problem_3746
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_STRING_LENGTH_AFTER_BALANCED_REMOVALS_H__
