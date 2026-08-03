#ifndef LEETCODE_PROBLEMS_FREQUENCIES_OF_SHORTEST_SUPERSEQUENCES_H_
#define LEETCODE_PROBLEMS_FREQUENCIES_OF_SHORTEST_SUPERSEQUENCES_H_

#include "leetcode/core.h"
#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3435 {

using Func = std::function<std::vector<std::vector<int>>(std::vector<std::string>&)>;

class FrequenciesOfShortestSupersequencesSolution
    : public SolutionBase<Func> {
 public:
  FrequenciesOfShortestSupersequencesSolution();
  std::vector<std::vector<int>> supersequences(std::vector<std::string>& words);
};

}  // namespace problem_3435
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FREQUENCIES_OF_SHORTEST_SUPERSEQUENCES_H_
