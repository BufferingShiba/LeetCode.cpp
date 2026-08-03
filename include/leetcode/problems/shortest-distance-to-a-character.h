#ifndef LEETCODE_PROBLEMS_SHORTEST_DISTANCE_TO_A_CHARACTER_H__
#define LEETCODE_PROBLEMS_SHORTEST_DISTANCE_TO_A_CHARACTER_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_821 {

using Func = std::function<std::vector<int>(std::string, char)>;

class ShortestDistanceToACharacterSolution
    : public SolutionBase<Func> {
 public:
  ShortestDistanceToACharacterSolution();

  std::vector<int> shortestToChar(std::string s, char c);
};

}  // namespace problem_821
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SHORTEST_DISTANCE_TO_A_CHARACTER_H__
