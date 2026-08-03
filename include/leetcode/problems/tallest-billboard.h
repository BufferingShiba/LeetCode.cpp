#ifndef LEETCODE_PROBLEMS_TALLEST_BILLBOARD_H__
#define LEETCODE_PROBLEMS_TALLEST_BILLBOARD_H__

#include "leetcode/core.h"
#include <functional>
#include <unordered_map>
#include <vector>
#include <string>

namespace leetcode {
namespace problem_956 {

using Func = std::function<int(std::vector<int>&)>;

class TallestBillboardSolution : public SolutionBase<Func> {
 public:
  TallestBillboardSolution();

  int tallestBillboard(std::vector<int>& rods);
};

}  // namespace problem_956
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_TALLEST_BILLBOARD_H__
