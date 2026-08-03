#include "leetcode/core.h"

namespace leetcode {
namespace problem_1052 {

using Func = std::function<int(vector<int>&, vector<int>&, int)>;

class GrumpyBookstoreOwnerSolution : public SolutionBase<Func> {
 public:
  //! 1052. Grumpy Bookstore Owner
  //! https://leetcode.com/problems/grumpy-bookstore-owner/
  int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes);

  GrumpyBookstoreOwnerSolution();
};

}  // namespace problem_1052
}  // namespace leetcode
