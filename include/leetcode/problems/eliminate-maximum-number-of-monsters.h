#ifndef LEETCODE_PROBLEMS_ELIMINATE_MAXIMUM_NUMBER_OF_MONSTERS_H_
#define LEETCODE_PROBLEMS_ELIMINATE_MAXIMUM_NUMBER_OF_MONSTERS_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1921 {

using Func = std::function<int(std::vector<int>&, std::vector<int>&)>;

class EliminateMaximumNumberOfMonstersSolution
    : public SolutionBase<Func> {
 public:
  EliminateMaximumNumberOfMonstersSolution();

  int eliminateMaximum(std::vector<int>& dist, std::vector<int>& speed);
};

}  // namespace problem_1921
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_ELIMINATE_MAXIMUM_NUMBER_OF_MONSTERS_H_
