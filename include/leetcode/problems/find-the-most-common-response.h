#include "leetcode/core.h"

namespace leetcode {
namespace problem_3527 {

using Func = std::function<string(vector<vector<string>>&)>;

class FindTheMostCommonResponseSolution : public SolutionBase<Func> {
 public:
  //! 3527. Find the Most Common Response
  //! https://leetcode.com/problems/find-the-most-common-response/
  string findCommonResponse(vector<vector<string>>& responses);

  FindTheMostCommonResponseSolution();
};

}  // namespace problem_3527
}  // namespace leetcode
