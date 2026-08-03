#include "leetcode/core.h"

namespace leetcode {
namespace problem_948 {

using Func = std::function<int(vector<int>&, int)>;

class BagOfTokensSolution : public SolutionBase<Func> {
 public:
  //! 948. Bag of Tokens
  //! https://leetcode.com/problems/bag-of-tokens/
  int bagOfTokensScore(vector<int>& tokens, int power);

  BagOfTokensSolution();
};

}  // namespace problem_948
}  // namespace leetcode
