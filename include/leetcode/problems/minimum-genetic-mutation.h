#include "leetcode/core.h"

namespace leetcode {
namespace problem_433 {

using Func = std::function<int(string, string, vector<string>&)>;

class MinimumGeneticMutationSolution : public SolutionBase<Func> {
 public:
  //! 433. Minimum Genetic Mutation
  //! https://leetcode.com/problems/minimum-genetic-mutation/
  int minMutation(string startGene, string endGene, vector<string>& bank);

  MinimumGeneticMutationSolution();
};

}  // namespace problem_433
}  // namespace leetcode
