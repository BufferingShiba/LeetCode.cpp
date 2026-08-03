#include "leetcode/core.h"

namespace leetcode {
namespace problem_1540 {

using Func = std::function<bool(string, string, int)>;

class CanConvertStringInKMovesSolution : public SolutionBase<Func> {
 public:
  //! 1540. Can Convert String in K Moves
  //! https://leetcode.com/problems/can-convert-string-in-k-moves/
  bool canConvertString(string s, string t, int k);

  CanConvertStringInKMovesSolution();
};

}  // namespace problem_1540
}  // namespace leetcode
