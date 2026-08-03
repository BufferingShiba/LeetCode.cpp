#include "leetcode/core.h"

namespace leetcode {
namespace problem_3844 {

using Func = std::function<int(string)>;

class LongestAlmostPalindromicSubstringSolution : public SolutionBase<Func> {
 public:
  //! 3844. Longest Almost-Palindromic Substring
  //! https://leetcode.com/problems/longest-almost-palindromic-substring/
  int almostPalindromic(string s);

  LongestAlmostPalindromicSubstringSolution();
};

}  // namespace problem_3844
}  // namespace leetcode
