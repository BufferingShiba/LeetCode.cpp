#include "leetcode/core.h"

namespace leetcode {
namespace problem_1869 {

using Func = std::function<bool(string)>;

class LongerContiguousSegmentsOfOnesThanZerosSolution : public SolutionBase<Func> {
 public:
  //! 1869. Longer Contiguous Segments of Ones than Zeros
  //! https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros/
  bool checkZeroOnes(string s);

  LongerContiguousSegmentsOfOnesThanZerosSolution();
};

}  // namespace problem_1869
}  // namespace leetcode
