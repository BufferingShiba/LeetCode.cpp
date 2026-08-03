#include "leetcode/core.h"

namespace leetcode {
namespace problem_1039 {

using Func = std::function<int(vector<int>&)>;

class MinimumScoreTriangulationOfPolygonSolution : public SolutionBase<Func> {
 public:
  //! 1039. Minimum Score Triangulation of Polygon
  //! https://leetcode.com/problems/minimum-score-triangulation-of-polygon/
  int minScoreTriangulation(vector<int>& values);

  MinimumScoreTriangulationOfPolygonSolution();
};

}  // namespace problem_1039
}  // namespace leetcode
