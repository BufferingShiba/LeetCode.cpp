#include "leetcode/core.h"

namespace leetcode {
namespace problem_1705 {

using Func = std::function<int(vector<int>&, vector<int>&)>;

class MaximumNumberOfEatenApplesSolution : public SolutionBase<Func> {
 public:
  //! 1705. Maximum Number of Eaten Apples
  //! https://leetcode.com/problems/maximum-number-of-eaten-apples/
  int eatenApples(vector<int>& apples, vector<int>& days);

  MaximumNumberOfEatenApplesSolution();
};

}  // namespace problem_1705
}  // namespace leetcode
