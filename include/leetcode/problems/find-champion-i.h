#ifndef LEETCODE_PROBLEMS_FIND_CHAMPION_I_H__
#define LEETCODE_PROBLEMS_FIND_CHAMPION_I_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_2923 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class FindChampionISolution : public SolutionBase<Func> {
 public:
  FindChampionISolution();
};

}  // namespace problem_2923
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_CHAMPION_I_H__
