#ifndef LEETCODE_PROBLEMS_PASCALS_TRIANGLE_H
#define LEETCODE_PROBLEMS_PASCALS_TRIANGLE_H

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_118 {

using Func = std::function<std::vector<std::vector<int>>(int)>;

class PascalsTriangleSolution : public SolutionBase<Func> {
 public:
  PascalsTriangleSolution();

  std::vector<std::vector<int>> generate(int numRows);
};

}  // namespace problem_118
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_PASCALS_TRIANGLE_H
