#ifndef LEETCODE_PROBLEMS_DEFUSE_THE_BOMB_H__
#define LEETCODE_PROBLEMS_DEFUSE_THE_BOMB_H__

#include "leetcode/core.h"
#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_1652 {

using Func = std::function<std::vector<int>(std::vector<int>&, int)>;

class DefuseTheBombSolution : public SolutionBase<Func> {
 public:
  DefuseTheBombSolution();
  std::vector<int> decrypt(std::vector<int>& code, int k);
};

}  // namespace problem_1652
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_DEFUSE_THE_BOMB_H__
