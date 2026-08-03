#ifndef LEETCODE_PROBLEMS_COUNT_GOOD_MEALS_H__
#define LEETCODE_PROBLEMS_COUNT_GOOD_MEALS_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_1711 {

using Func = std::function<int(std::vector<int>&)>;

class CountGoodMealsSolution : public SolutionBase<Func> {
 public:
  CountGoodMealsSolution();

  int countPairs(std::vector<int>& deliciousness);
};

}  // namespace problem_1711
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COUNT_GOOD_MEALS_H__
