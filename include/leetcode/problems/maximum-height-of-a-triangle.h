#include "leetcode/core.h"

namespace leetcode {
namespace problem_3200 {

using Func = std::function<int(int, int)>;

class MaximumHeightOfATriangleSolution : public SolutionBase<Func> {
 public:
  //! 3200. Maximum Height of a Triangle
  //! https://leetcode.com/problems/maximum-height-of-a-triangle/
  int maxHeightOfTriangle(int red, int blue);

  MaximumHeightOfATriangleSolution();
};

}  // namespace problem_3200
}  // namespace leetcode
