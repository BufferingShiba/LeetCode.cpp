#include "leetcode/core.h"

namespace leetcode {
namespace problem_3890 {

using Func = std::function<vector<int>(int)>;

class IntegersWithMultipleSumOfTwoCubesSolution : public SolutionBase<Func> {
 public:
  //! 3890. Integers With Multiple Sum of Two Cubes
  //! https://leetcode.com/problems/integers-with-multiple-sum-of-two-cubes/
  vector<int> findGoodIntegers(int n);

  IntegersWithMultipleSumOfTwoCubesSolution();
};

}  // namespace problem_3890
}  // namespace leetcode
