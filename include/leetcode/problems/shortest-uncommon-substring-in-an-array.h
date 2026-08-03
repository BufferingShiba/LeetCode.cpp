#include "leetcode/core.h"

namespace leetcode {
namespace problem_3076 {

using Func = std::function<vector<string>(vector<string>&)>;

class ShortestUncommonSubstringInAnArraySolution : public SolutionBase<Func> {
 public:
  //! 3076. Shortest Uncommon Substring in an Array
  //! https://leetcode.com/problems/shortest-uncommon-substring-in-an-array/
  vector<string> shortestSubstrings(vector<string>& arr);

  ShortestUncommonSubstringInAnArraySolution();
};

}  // namespace problem_3076
}  // namespace leetcode
