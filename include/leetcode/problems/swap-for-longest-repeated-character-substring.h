#include "leetcode/core.h"

namespace leetcode {
namespace problem_1156 {

using Func = std::function<int(string)>;

class SwapForLongestRepeatedCharacterSubstringSolution : public SolutionBase<Func> {
 public:
  //! 1156. Swap For Longest Repeated Character Substring
  //! https://leetcode.com/problems/swap-for-longest-repeated-character-substring/
  int maxRepOpt1(string text);

  SwapForLongestRepeatedCharacterSubstringSolution();
};

}  // namespace problem_1156
}  // namespace leetcode
