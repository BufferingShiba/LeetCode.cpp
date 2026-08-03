#ifndef LEETCODE_PROBLEMS_MAXIMUM_GENETIC_DIFFERENCE_QUERY_H_
#define LEETCODE_PROBLEMS_MAXIMUM_GENETIC_DIFFERENCE_QUERY_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1938 {

using Func = std::function<std::vector<int>(std::vector<int>&, std::vector<std::vector<int>>&)>;

class MaximumGeneticDifferenceQuerySolution : public SolutionBase<Func> {
 public:
  MaximumGeneticDifferenceQuerySolution();
};

}  // namespace problem_1938
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_GENETIC_DIFFERENCE_QUERY_H_
