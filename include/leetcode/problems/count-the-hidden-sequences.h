#include "leetcode/core.h"

namespace leetcode {
namespace problem_2145 {

using Func = std::function<int(vector<int>&, int, int)>;

class CountTheHiddenSequencesSolution : public SolutionBase<Func> {
 public:
  //! 2145. Count the Hidden Sequences
  //! https://leetcode.com/problems/count-the-hidden-sequences/
  int numberOfArrays(vector<int>& differences, int lower, int upper);

  CountTheHiddenSequencesSolution();
};

}  // namespace problem_2145
}  // namespace leetcode
