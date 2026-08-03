#include "leetcode/core.h"

namespace leetcode {
namespace problem_3752 {

using Func = std::function<vector<int>(int, long long)>;

class LexicographicallySmallestNegatedPermutationThatSumsToTargetSolution : public SolutionBase<Func> {
 public:
  //! 3752. Lexicographically Smallest Negated Permutation that Sums to Target
  //! https://leetcode.com/problems/lexicographically-smallest-negated-permutation-that-sums-to-target/
  vector<int> lexSmallestNegatedPerm(int n, long long target);

  LexicographicallySmallestNegatedPermutationThatSumsToTargetSolution();
};

}  // namespace problem_3752
}  // namespace leetcode
