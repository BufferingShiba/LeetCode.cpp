#ifndef LEETCODE_PROBLEMS_SHORTEST_IMPOSSIBLE_SEQUENCE_OF_ROLLS_H_
#define LEETCODE_PROBLEMS_SHORTEST_IMPOSSIBLE_SEQUENCE_OF_ROLLS_H_

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_2350 {

using Func = std::function<int(std::vector<int>&, int)>;

class ShortestImpossibleSequenceOfRollsSolution : public SolutionBase<Func> {
 public:
  ShortestImpossibleSequenceOfRollsSolution();

  int shortestSequence(std::vector<int>& rolls, int k);
};

}  // namespace problem_2350
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SHORTEST_IMPOSSIBLE_SEQUENCE_OF_ROLLS_H_
