#include "leetcode/core.h"

namespace leetcode {
namespace problem_14 {

using Func = std::function<string(vector<string>&)>;

class LongestCommonPrefixSolution : public SolutionBase<Func> {
 public:
  //! 14. Longest Common Prefix
  //! https://leetcode.com/problems/longest-common-prefix/
  string longestCommonPrefix(vector<string>& strs);

  LongestCommonPrefixSolution();
};

}  // namespace problem_14
}  // namespace leetcode
