#include "leetcode/core.h"

namespace leetcode {
namespace problem_3517 {

using Func = std::function<string(string)>;

class SmallestPalindromicRearrangementISolution : public SolutionBase<Func> {
 public:
  //! 3517. Smallest Palindromic Rearrangement I
  //! https://leetcode.com/problems/smallest-palindromic-rearrangement-i/
  string smallestPalindrome(string s);

  SmallestPalindromicRearrangementISolution();
};

}  // namespace problem_3517
}  // namespace leetcode
