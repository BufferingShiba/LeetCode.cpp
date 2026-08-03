#ifndef LEETCODE_PROBLEMS_FIND_CHAMPION_II_H__
#define LEETCODE_PROBLEMS_FIND_CHAMPION_II_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2924 {

using Func = std::function<int(int, std::vector<std::vector<int>>&)>;

class FindChampionIiSolution : public SolutionBase<Func> {
 public:
  FindChampionIiSolution();

  int findChampion(int n, std::vector<std::vector<int>>& edges);
};

}  // namespace problem_2924
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_CHAMPION_II_H__
