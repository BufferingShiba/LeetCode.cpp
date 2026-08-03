#ifndef LEETCODE_PROBLEMS_SUM_GAME_H__
#define LEETCODE_PROBLEMS_SUM_GAME_H__

#include "leetcode/core.h"

#include <functional>
#include <string>

namespace leetcode {
namespace problem_1927 {

using Func = std::function<bool(std::string)>;

class SumGameSolution : public SolutionBase<Func> {
 public:
  SumGameSolution();
};

}  // namespace problem_1927
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SUM_GAME_H__
