#ifndef LEETCODE_REMOVE_COLORED_PIECES_IF_BOTH_NEIGHBORS_ARE_THE_SAME_COLOR_H__
#define LEETCODE_REMOVE_COLORED_PIECES_IF_BOTH_NEIGHBORS_ARE_THE_SAME_COLOR_H__

#include "leetcode/core.h"

#include <functional>
#include <string>

namespace leetcode {
namespace problem_2038 {

using Func = std::function<bool(std::string)>;

class RemoveColoredPiecesIfBothNeighborsAreTheSameColorSolution
    : public SolutionBase<Func> {
 public:
  RemoveColoredPiecesIfBothNeighborsAreTheSameColorSolution();

  bool winnerOfGame(std::string colors);
};

}  // namespace problem_2038
}  // namespace leetcode

#endif  // LEETCODE_REMOVE_COLORED_PIECES_IF_BOTH_NEIGHBORS_ARE_THE_SAME_COLOR_H__
