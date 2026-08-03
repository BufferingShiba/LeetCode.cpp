#ifndef LEETCODE_PROBLEM_886_H__
#define LEETCODE_PROBLEM_886_H__

#include "leetcode/core.h"

namespace leetcode {
namespace problem_886 {

using Func = std::function<bool(int, std::vector<std::vector<int>>&)>;

class PossibleBipartitionSolution : public SolutionBase<Func> {
 public:
  PossibleBipartitionSolution();

  bool possibleBipartition(int n, std::vector<std::vector<int>>& dislikes);
};

}  // namespace problem_886
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_886_H__
