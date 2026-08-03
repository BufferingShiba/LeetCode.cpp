#include "leetcode/core.h"

namespace leetcode {
namespace problem_3393 {

using Func = std::function<int(vector<vector<int>>&, int)>;

class CountPathsWithTheGivenXorValueSolution : public SolutionBase<Func> {
 public:
  //! 3393. Count Paths With the Given XOR Value
  //! https://leetcode.com/problems/count-paths-with-the-given-xor-value/
  int countPathsWithXorValue(vector<vector<int>>& grid, int k);

  CountPathsWithTheGivenXorValueSolution();
};

}  // namespace problem_3393
}  // namespace leetcode
