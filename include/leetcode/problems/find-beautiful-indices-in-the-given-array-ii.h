#ifndef LEETCODE_PROBLEMS_FIND_BEAUTIFUL_INDICES_IN_THE_GIVEN_ARRAY_II_H
#define LEETCODE_PROBLEMS_FIND_BEAUTIFUL_INDICES_IN_THE_GIVEN_ARRAY_II_H

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3008 {

using Func = std::function<std::vector<int>(std::string, std::string, std::string, int)>;

class FindBeautifulIndicesInTheGivenArrayIiSolution
    : public SolutionBase<Func> {
 public:
  FindBeautifulIndicesInTheGivenArrayIiSolution();

  std::vector<int> beautifulIndices(std::string s, std::string a, std::string b,
                                    int k);
};

}  // namespace problem_3008
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_BEAUTIFUL_INDICES_IN_THE_GIVEN_ARRAY_II_H
