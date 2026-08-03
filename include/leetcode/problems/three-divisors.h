#include "leetcode/core.h"

namespace leetcode {
namespace problem_1952 {

using Func = std::function<bool(int)>;

class ThreeDivisorsSolution : public SolutionBase<Func> {
 public:
  //! 1952. Three Divisors
  //! https://leetcode.com/problems/three-divisors/
  bool isThree(int n);

  ThreeDivisorsSolution();
};

}  // namespace problem_1952
}  // namespace leetcode
