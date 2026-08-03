#ifndef LEETCODE_PROBLEMS_RIGHT_TRIANGLES_H_
#define LEETCODE_PROBLEMS_RIGHT_TRIANGLES_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3128 {

using Func = std::function<long long(std::vector<std::vector<int>>&)>;

class RightTrianglesSolution : public SolutionBase<Func> {
 public:
  RightTrianglesSolution();

  long long numberOfRightTriangles(std::vector<std::vector<int>>& grid);
};

}  // namespace problem_3128
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_RIGHT_TRIANGLES_H_
