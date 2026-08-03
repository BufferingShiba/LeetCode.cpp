#include "leetcode/core.h"

namespace leetcode {
namespace problem_823 {

using Func = std::function<int(vector<int>&)>;

class BinaryTreesWithFactorsSolution : public SolutionBase<Func> {
 public:
  //! 823. Binary Trees With Factors
  //! https://leetcode.com/problems/binary-trees-with-factors/
  int numFactoredBinaryTrees(vector<int>& arr);

  BinaryTreesWithFactorsSolution();
};

}  // namespace problem_823
}  // namespace leetcode
