#ifndef LEETCODE_PROBLEMS_FROG_JUMP_II_H__
#define LEETCODE_PROBLEMS_FROG_JUMP_II_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_2498 {

using Func = std::function<int(std::vector<int>&)>;

class FrogJumpIiSolution : public SolutionBase<Func> {
 public:
  FrogJumpIiSolution() {
    setMetaInfo({.id = 2498,
                 .title = "Frog Jump II",
                 .url = "https://leetcode.com/problems/frog-jump-ii/"});
    registerStrategy(
        {.name = "greedy",
         .expected = "Accepted",
         .time_complexity = "O(n)",
         .space_complexity = "O(1)",
         .tags = {"Array", "Greedy"},
         .notes =
             "Forward visits even-indexed stones and backward visits the rest. "
             "Any valid interleaving forces every gap of index distance 2 to be "
             "a single jump, so the answer is the max such gap plus boundaries."},
        [this](std::vector<int>& stones) { return maxJumpImpl(stones); });
  }

  int maxJump(std::vector<int>& stones) { return getSolution()(stones); }

 private:
  static int maxJumpImpl(std::vector<int>& stones);
};

}  // namespace problem_2498
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FROG_JUMP_II_H__
