#ifndef LEETCODE_PROBLEMS_MINIMUM_CAPACITY_BOX_H__
#define LEETCODE_PROBLEMS_MINIMUM_CAPACITY_BOX_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3861 {

using Func = std::function<int(std::vector<int>&, int)>;

class MinimumCapacityBoxSolution : public SolutionBase<Func> {
 public:
  MinimumCapacityBoxSolution() {
    setMetaInfo({.id = 3861,
                 .title = "Minimum Capacity Box",
                 .url =
                     "https://leetcode.com/problems/minimum-capacity-box/"});
    registerStrategy({.name = "LinearScan",
                      .expected = "Accepted",
                      .time_complexity = "O(n)",
                      .space_complexity = "O(1)",
                      .tags = {"Array"}},
                     minimumIndexImpl);
  }

  int minimumIndex(std::vector<int>& capacity, int itemSize);

 private:
  static int minimumIndexImpl(std::vector<int>& capacity, int itemSize);
};

}  // namespace problem_3861
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_CAPACITY_BOX_H__
