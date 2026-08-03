#ifndef LEETCODE_PROBLEMS_EVEN_NUMBER_OF_KNIGHT_MOVES_H__
#define LEETCODE_PROBLEMS_EVEN_NUMBER_OF_KNIGHT_MOVES_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3996 {

using Func = std::function<bool(std::vector<int>&, std::vector<int>&)>;

class EvenNumberOfKnightMovesSolution : public SolutionBase<Func> {
 public:
  EvenNumberOfKnightMovesSolution();

  bool canReach(std::vector<int>& start, std::vector<int>& target);
};

}  // namespace problem_3996
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_EVEN_NUMBER_OF_KNIGHT_MOVES_H__
