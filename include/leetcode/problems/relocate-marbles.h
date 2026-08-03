#ifndef LEETCODE_PROBLEMS_RELOCATE_MARBLES_H_
#define LEETCODE_PROBLEMS_RELOCATE_MARBLES_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2766 {

using Func = std::function<std::vector<int>(std::vector<int>&, std::vector<int>&,
                                            std::vector<int>&)>;

class RelocateMarblesSolution : public SolutionBase<Func> {
 public:
  RelocateMarblesSolution() {
    setMetaInfo({.id = 2766,
                 .title = "Relocate Marbles",
                 .url = "https://leetcode.com/problems/relocate-marbles/"});

    registerStrategy({.name = "hashset-simulation",
                      .expected = "Accepted",
                      .time_complexity = "O((n + m) log n)",
                      .space_complexity = "O(n)",
                      .tags = {"Hash Table", "Simulation"},
                      .notes = "Use a hash set to track occupied positions; each move erases moveFrom[i] and inserts moveTo[i]."},
                     relocateMarblesImpl);
  }

  std::vector<int> relocateMarbles(std::vector<int>& nums, std::vector<int>& moveFrom,
                                   std::vector<int>& moveTo) {
    return getSolution()(nums, moveFrom, moveTo);
  }

 private:
  static std::vector<int> relocateMarblesImpl(std::vector<int>& nums, std::vector<int>& moveFrom,
                                              std::vector<int>& moveTo);
};

}  // namespace problem_2766
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_RELOCATE_MARBLES_H_
