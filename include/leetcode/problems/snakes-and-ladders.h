#ifndef LEETCODE_PROBLEMS_SNAKES_AND_LADDERS_H_
#define LEETCODE_PROBLEMS_SNAKES_AND_LADDERS_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_909 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class SnakesAndLaddersSolution : public SolutionBase<Func> {
 public:
  SnakesAndLaddersSolution();

  int snakesAndLadders(std::vector<std::vector<int>>& board);
};

}  // namespace problem_909
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SNAKES_AND_LADDERS_H_
