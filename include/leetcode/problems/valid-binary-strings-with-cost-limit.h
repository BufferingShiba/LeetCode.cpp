#ifndef LEETCODE_PROBLEMS_VALID_BINARY_STRINGS_WITH_COST_LIMIT_H__
#define LEETCODE_PROBLEMS_VALID_BINARY_STRINGS_WITH_COST_LIMIT_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3955 {

using Func = std::function<std::vector<std::string>(int n, int k)>;

class ValidBinaryStringsWithCostLimit
    : public SolutionBase<Func> {
 public:
  ValidBinaryStringsWithCostLimit();

  std::vector<std::string> generateValidStrings(int n, int k);
};

}  // namespace problem_3955
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_VALID_BINARY_STRINGS_WITH_COST_LIMIT_H__
