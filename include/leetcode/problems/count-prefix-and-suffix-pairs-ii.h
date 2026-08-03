#pragma once

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode::problem_3045 {

using Func = std::function<long long(std::vector<std::string>&)>;

class CountPrefixAndSuffixPairsIiSolution : public SolutionBase<Func> {
 public:
  CountPrefixAndSuffixPairsIiSolution();

  long long countPrefixSuffixPairs(std::vector<std::string>& words);
};

}  // namespace leetcode::problem_3045
