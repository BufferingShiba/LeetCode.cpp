#ifndef LEETCODE_PROBLEMS_NUMBER_OF_CHANGING_KEYS_H_
#define LEETCODE_PROBLEMS_NUMBER_OF_CHANGING_KEYS_H_

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3019 {

using Func = std::function<int(std::string)>;

class NumberOfChangingKeysSolution : public SolutionBase<Func> {
 public:
  NumberOfChangingKeysSolution();
  int countKeyChanges(std::string s);
};

}  // namespace problem_3019
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_NUMBER_OF_CHANGING_KEYS_H_
