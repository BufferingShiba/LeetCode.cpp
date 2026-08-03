#ifndef LEETCODE_PROBLEMS_MAXIMUM_POPULATION_YEAR_H__
#define LEETCODE_PROBLEMS_MAXIMUM_POPULATION_YEAR_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1854 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class MaximumPopulationYearSolution : public SolutionBase<Func> {
 public:
  MaximumPopulationYearSolution();

  void registerStrategies();

  int maximumPopulation(std::vector<std::vector<int>>& logs);
};

}  // namespace problem_1854
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_POPULATION_YEAR_H__
