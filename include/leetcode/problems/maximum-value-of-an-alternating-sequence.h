#include "leetcode/core.h"

namespace leetcode {
namespace problem_3993 {

using Func = std::function<long(int, int, int)>;

class MaximumValueOfAnAlternatingSequenceSolution : public SolutionBase<Func> {
 public:
  //! 3993. Maximum Value of an Alternating Sequence
  //! https://leetcode.com/problems/maximum-value-of-an-alternating-sequence/
  long maximumValue(int n, int s, int m);

  MaximumValueOfAnAlternatingSequenceSolution();
};

}  // namespace problem_3993
}  // namespace leetcode
