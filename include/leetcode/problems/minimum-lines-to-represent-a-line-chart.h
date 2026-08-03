#include "leetcode/core.h"

namespace leetcode {
namespace problem_2280 {

using Func = std::function<int(vector<vector<int>>&)>;

class MinimumLinesToRepresentALineChartSolution : public SolutionBase<Func> {
 public:
  //! 2280. Minimum Lines to Represent a Line Chart
  //! https://leetcode.com/problems/minimum-lines-to-represent-a-line-chart/
  int minimumLines(vector<vector<int>>& stockPrices);

  MinimumLinesToRepresentALineChartSolution();
};

}  // namespace problem_2280
}  // namespace leetcode
