#ifndef LEETCODE_PROBLEMS_CONVERT_THE_TEMPERATURE_H__
#define LEETCODE_PROBLEMS_CONVERT_THE_TEMPERATURE_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_2469 {

using Func = std::function<std::vector<double>(double)>;

class ConvertTheTemperatureSolution : public SolutionBase<Func> {
 public:
  ConvertTheTemperatureSolution();

  std::vector<double> convertTemperature(double celsius);
};

}  // namespace leetcode::problem_2469

#endif  // LEETCODE_PROBLEMS_CONVERT_THE_TEMPERATURE_H__
