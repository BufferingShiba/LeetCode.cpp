#ifndef LEETCODE_PROBLEMS_TWISTED_MIRROR_PATH_COUNT_H_
#define LEETCODE_PROBLEMS_TWISTED_MIRROR_PATH_COUNT_H_

#include <vector>
#include <functional>
#include <string>
#include "leetcode/core.h"

namespace leetcode {
namespace problem_3665 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class TwistedMirrorPathCountSolution : public SolutionBase<Func> {
 public:
  TwistedMirrorPathCountSolution();
  int uniquePaths(std::vector<std::vector<int>>& grid);
};

}  // namespace problem_3665
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_TWISTED_MIRROR_PATH_COUNT_H_
