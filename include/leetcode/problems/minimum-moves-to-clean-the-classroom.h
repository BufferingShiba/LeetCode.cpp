#ifndef LEETCODE_PROBLEMS_MINIMUM_MOVES_TO_CLEAN_THE_CLASSROOM_H__
#define LEETCODE_PROBLEMS_MINIMUM_MOVES_TO_CLEAN_THE_CLASSROOM_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_3568 {

using Func = std::function<int(std::vector<std::string>&, int)>;

class MinimumMovesToCleanTheClassroom : public SolutionBase<Func> {
 public:
  MinimumMovesToCleanTheClassroom();
  int minMoves(std::vector<std::string>& classroom, int energy);
};

}  // namespace leetcode::problem_3568

#endif  // LEETCODE_PROBLEMS_MINIMUM_MOVES_TO_CLEAN_THE_CLASSROOM_H__
