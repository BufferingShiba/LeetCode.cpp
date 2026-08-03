#include "leetcode/core.h"

namespace leetcode {
namespace problem_1208 {

using Func = std::function<int(string, string, int)>;

class GetEqualSubstringsWithinBudgetSolution : public SolutionBase<Func> {
 public:
  //! 1208. Get Equal Substrings Within Budget
  //! https://leetcode.com/problems/get-equal-substrings-within-budget/
  int equalSubstring(string s, string t, int maxCost);

  GetEqualSubstringsWithinBudgetSolution();
};

}  // namespace problem_1208
}  // namespace leetcode
