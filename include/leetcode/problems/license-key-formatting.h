#pragma once

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_482 {

using Func = std::function<std::string(std::string, int)>;

class LicenseKeyFormattingSolution : public SolutionBase<Func> {
 public:
  LicenseKeyFormattingSolution();

  std::string licenseKeyFormatting(std::string s, int k);
};

}  // namespace leetcode::problem_482
