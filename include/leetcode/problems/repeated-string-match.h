#include "leetcode/core.h"

namespace leetcode {
namespace problem_686 {

using Func = std::function<int(string, string)>;

class RepeatedStringMatchSolution : public SolutionBase<Func> {
 public:
  //! 686. Repeated String Match
  //! https://leetcode.com/problems/repeated-string-match/
  int repeatedStringMatch(string a, string b);

  RepeatedStringMatchSolution();
};

}  // namespace problem_686
}  // namespace leetcode
