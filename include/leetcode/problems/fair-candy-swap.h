#ifndef LEETCODE_PROBLEMS_FAIR_CANDY_SWAP_H__
#define LEETCODE_PROBLEMS_FAIR_CANDY_SWAP_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_888 {

using Func = std::function<std::vector<int>(std::vector<int>&, std::vector<int>&)>;

class FairCandySwapSolution : public SolutionBase<Func> {
 public:
  FairCandySwapSolution();

  std::vector<int> fairCandySwap(std::vector<int>& aliceSizes,
                                 std::vector<int>& bobSizes);
};

}  // namespace problem_888
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FAIR_CANDY_SWAP_H__
