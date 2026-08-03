#ifndef LEETCODE_PROBLEMS_PASCALS_TRIANGLE_II_H__
#define LEETCODE_PROBLEMS_PASCALS_TRIANGLE_II_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_119 {

using Func =
    std::function<std::vector<int>(int)>;

class PascalsTriangleIiSolution : public SolutionBase<Func> {
 public:
  std::vector<int> getRow(int rowIndex);
  PascalsTriangleIiSolution();
};

}  // namespace problem_119
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_PASCALS_TRIANGLE_II_H__
