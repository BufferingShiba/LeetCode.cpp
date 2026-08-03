#include "leetcode/core.h"

namespace leetcode {
namespace problem_1905 {

using Func = std::function<int(vector<vector<int>>&, vector<vector<int>>&)>;

class CountSubIslandsSolution : public SolutionBase<Func> {
 public:
  //! 1905. Count Sub Islands
  //! https://leetcode.com/problems/count-sub-islands/
  int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2);

  CountSubIslandsSolution();
};

}  // namespace problem_1905
}  // namespace leetcode
