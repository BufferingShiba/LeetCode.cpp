#ifndef LEETCODE_PROBLEMS_MAXIMUM_SCORE_FROM_REMOVING_STONES_H__
#define LEETCODE_PROBLEMS_MAXIMUM_SCORE_FROM_REMOVING_STONES_H__

#include "leetcode/core.h"

#include <functional>

namespace leetcode {
namespace problem_1753 {

using Func = std::function<int(int, int, int)>;

class MaximumScoreFromRemovingStonesSolution
    : public SolutionBase<Func> {
 public:
  MaximumScoreFromRemovingStonesSolution();

  int maximumScore(int a, int b, int c);
};

}  // namespace problem_1753
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_SCORE_FROM_REMOVING_STONES_H__
