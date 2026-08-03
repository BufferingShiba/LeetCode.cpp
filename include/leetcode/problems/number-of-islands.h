
#include "leetcode/core.h"

namespace leetcode {
namespace problem_200 {

using Func = std::function<int(vector<vector<char>>&)>;

class NumberOfIslandsSolution : public SolutionBase<Func> {
 public:
  //! 200. Number of Islands
  //! https://leetcode.com/problems/number-of-islands/
  int numIslands(vector<vector<char>>& grid);

  NumberOfIslandsSolution();
};

}  // namespace problem_200
}  // namespace leetcode
