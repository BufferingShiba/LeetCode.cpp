#ifndef LEETCODE_PROBLEMS_TOGGLE_LIGHT_BULBS_H__
#define LEETCODE_PROBLEMS_TOGGLE_LIGHT_BULBS_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3842 {

using Func = std::function<std::vector<int>(std::vector<int>&)>;

class ToggleLightBulbsSolution : public SolutionBase<Func> {
 public:
  ToggleLightBulbsSolution();

  std::vector<int> toggleLightBulbs(std::vector<int>& bulbs);
};

}  // namespace problem_3842
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_TOGGLE_LIGHT_BULBS_H__
