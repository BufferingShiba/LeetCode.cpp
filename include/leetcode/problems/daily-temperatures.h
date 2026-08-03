#ifndef LEETCODE_PROBLEMS_DAILY_TEMPERATURES_H_
#define LEETCODE_PROBLEMS_DAILY_TEMPERATURES_H_

#include <vector>
#include <functional>
#include "leetcode/core.h"

namespace leetcode {
namespace problem_739 {

using Func = std::function<std::vector<int>(std::vector<int>&)>;

class DailyTemperaturesSolution : public SolutionBase<Func> {
 public:
  DailyTemperaturesSolution();

  std::vector<int> dailyTemperatures(std::vector<int>& temperatures);
};

}  // namespace problem_739
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_DAILY_TEMPERATURES_H_
