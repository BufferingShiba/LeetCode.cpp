#ifndef LEETCODE_PROBLEMS_RESTORE_THE_ARRAY_FROM_ADJACENT_PAIRS_H__
#define LEETCODE_PROBLEMS_RESTORE_THE_ARRAY_FROM_ADJACENT_PAIRS_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1743 {

using Func = std::function<std::vector<int>(std::vector<std::vector<int>>&)>;

class RestoreTheArrayFromAdjacentPairsSolution
    : public SolutionBase<Func> {
 public:
  RestoreTheArrayFromAdjacentPairsSolution();

  std::vector<int> restoreArray(std::vector<std::vector<int>>& adjacentPairs);
};

}  // namespace problem_1743
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_RESTORE_THE_ARRAY_FROM_ADJACENT_PAIRS_H__
