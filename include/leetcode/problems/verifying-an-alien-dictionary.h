#pragma once

#include "leetcode/core.h"
#include <functional>
#include <string>
#include <vector>

namespace leetcode::problem_953 {

using Func = std::function<bool(std::vector<std::string>&, std::string)>;

class VerifyingAnAlienDictionarySolution : public SolutionBase<Func> {
 public:
  VerifyingAnAlienDictionarySolution();
  bool isAlienSorted(std::vector<std::string>& words, std::string order);
};

}  // namespace leetcode::problem_953
