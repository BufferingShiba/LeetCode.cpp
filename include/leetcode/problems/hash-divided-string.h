#ifndef LEETCODE_PROBLEMS_HASH_DIVIDED_STRING_H_
#define LEETCODE_PROBLEMS_HASH_DIVIDED_STRING_H_

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3271 {

using Func = std::function<std::string(std::string, int)>;

class HashDividedStringSolution : public SolutionBase<Func> {
 public:
  std::string stringHash(std::string s, int k);

  explicit HashDividedStringSolution();
};

}  // namespace problem_3271
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_HASH_DIVIDED_STRING_H_
