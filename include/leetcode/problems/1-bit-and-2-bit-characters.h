#include "leetcode/core.h"

namespace leetcode {
namespace problem_717 {

using Func = std::function<bool(vector<int>&)>;

class Problem1BitAnd2BitCharactersSolution : public SolutionBase<Func> {
 public:
  //! 717. 1-bit and 2-bit Characters
  //! https://leetcode.com/problems/1-bit-and-2-bit-characters/
  bool isOneBitCharacter(vector<int>& bits);

  Problem1BitAnd2BitCharactersSolution();
};

}  // namespace problem_717
}  // namespace leetcode
