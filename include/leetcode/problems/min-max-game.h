#ifndef LEETCODE_PROBLEMS_MIN_MAX_GAME_H__
#define LEETCODE_PROBLEMS_MIN_MAX_GAME_H__

#include "leetcode/core.h"
#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_2293 {

using Func = std::function<int(std::vector<int>&)>;

class MinMaxGameSolution : public SolutionBase<Func> {
 public:
  MinMaxGameSolution();
  int minMaxGame(std::vector<int>& nums);
};

}  // namespace problem_2293
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MIN_MAX_GAME_H__
