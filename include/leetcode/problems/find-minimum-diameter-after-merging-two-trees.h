#ifndef LEETCODE_PROBLEMS_FIND_MINIMUM_DIAMETER_AFTER_MERGING_TWO_TREES_H__
#define LEETCODE_PROBLEMS_FIND_MINIMUM_DIAMETER_AFTER_MERGING_TWO_TREES_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3203 {

using Func = std::function<int(std::vector<std::vector<int>>&, std::vector<std::vector<int>>&)>;

class FindMinimumDiameterAfterMergingTwoTreesSolution : public SolutionBase<Func> {
 public:
  FindMinimumDiameterAfterMergingTwoTreesSolution();

  int minimumDiameterAfterMerge(std::vector<std::vector<int>>& edges1,
                                std::vector<std::vector<int>>& edges2) {
    return getSolution()(edges1, edges2);
  }
};

}  // namespace problem_3203
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_MINIMUM_DIAMETER_AFTER_MERGING_TWO_TREES_H__
