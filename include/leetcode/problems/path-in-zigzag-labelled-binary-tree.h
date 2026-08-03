#ifndef LEETCODE_PROBLEM_1104_H_
#define LEETCODE_PROBLEM_1104_H_

#include "leetcode/core.h"
#include <vector>

namespace leetcode::problem_1104 {

using Func = std::function<std::vector<int>(int)>;

class PathInZigzagLabelledBinaryTreeSolution : public SolutionBase<Func> {
 public:
  PathInZigzagLabelledBinaryTreeSolution();

  std::vector<int> pathInZigZagTree(int label);
};

}  // namespace leetcode::problem_1104

#endif  // LEETCODE_PROBLEM_1104_H_
