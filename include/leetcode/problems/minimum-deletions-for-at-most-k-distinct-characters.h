#ifndef LEETCODE_PROBLEMS_MINIMUM_DELETIONS_FOR_AT_MOST_K_DISTINCT_CHARACTERS_H__
#define LEETCODE_PROBLEMS_MINIMUM_DELETIONS_FOR_AT_MOST_K_DISTINCT_CHARACTERS_H__

#include "leetcode/core.h"

#include <functional>
#include <string>

namespace leetcode {
namespace problem_3545 {

using Func = std::function<int(std::string, int)>;

class MinimumDeletionsForAtMostKDistinctCharactersSolution
    : public SolutionBase<Func> {
 public:
  MinimumDeletionsForAtMostKDistinctCharactersSolution();

  int minDeletion(std::string s, int k) { return getSolution()(s, k); }

  // Keep the live-site plural spelling available as well; the cached metadata
  // for this recently renamed problem still uses minDeletion.
  int minDeletions(std::string s, int k) { return getSolution()(s, k); }
};

}  // namespace problem_3545
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_DELETIONS_FOR_AT_MOST_K_DISTINCT_CHARACTERS_H__
