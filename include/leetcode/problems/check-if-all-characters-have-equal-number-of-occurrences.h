#pragma once

#include "leetcode/core.h"

namespace leetcode::problem_1941 {

using Func = std::function<bool(std::string)>;

class CheckIfAllCharactersHaveEqualNumberOfOccurrencesSolution : public SolutionBase<Func> {
 public:
  CheckIfAllCharactersHaveEqualNumberOfOccurrencesSolution();

  bool areOccurrencesEqual(std::string s);
};

}  // namespace leetcode::problem_1941
