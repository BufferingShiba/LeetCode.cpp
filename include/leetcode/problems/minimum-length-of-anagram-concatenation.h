#include "leetcode/core.h"

namespace leetcode {
namespace problem_3138 {

using Func = std::function<int(string)>;

class MinimumLengthOfAnagramConcatenationSolution : public SolutionBase<Func> {
 public:
  //! 3138. Minimum Length of Anagram Concatenation
  //! https://leetcode.com/problems/minimum-length-of-anagram-concatenation/
  int minAnagramLength(string s);

  MinimumLengthOfAnagramConcatenationSolution();
};

}  // namespace problem_3138
}  // namespace leetcode
