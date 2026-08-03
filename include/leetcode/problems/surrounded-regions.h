#ifndef LEETCODE_PROBLEMS_SURROUNDED_REGIONS_H__
#define LEETCODE_PROBLEMS_SURROUNDED_REGIONS_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_130 {

using Func = std::function<void(std::vector<std::vector<char>>&)>;

class SurroundedRegionsSolution : public SolutionBase<Func> {
 public:
  SurroundedRegionsSolution();

  void solve(std::vector<std::vector<char>>& board);
};

}  // namespace problem_130
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SURROUNDED_REGIONS_H__
