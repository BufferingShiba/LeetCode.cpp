#ifndef LEETCODE_PROBLEMS_MAXIMUM_GOOD_SUBTREE_SCORE_H_
#define LEETCODE_PROBLEMS_MAXIMUM_GOOD_SUBTREE_SCORE_H_

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_3575 {

using Func = std::function<int(std::vector<int>&, std::vector<int>&)>;

class MaximumGoodSubtreeScoreSolution : public SolutionBase<Func> {
 public:
  MaximumGoodSubtreeScoreSolution();

  int goodSubtreeSum(std::vector<int>& vals, std::vector<int>& par) {
    return getSolution()(vals, par);
  }
};

}  // namespace problem_3575
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_GOOD_SUBTREE_SCORE_H_
