#ifndef LEETCODE_PROBLEMS_TAG_VALIDATOR_H__
#define LEETCODE_PROBLEMS_TAG_VALIDATOR_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_591 {

using Func = std::function<bool(std::string)>;

class TagValidatorSolution : public SolutionBase<Func> {
 public:
  TagValidatorSolution();

  bool isValid(const std::string& code);
};

}  // namespace problem_591
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_TAG_VALIDATOR_H__
