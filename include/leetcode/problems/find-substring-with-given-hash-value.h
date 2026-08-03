#ifndef LEETCODE_PROBLEMS_FIND_SUBSTRING_WITH_GIVEN_HASH_VALUE_H_
#define LEETCODE_PROBLEMS_FIND_SUBSTRING_WITH_GIVEN_HASH_VALUE_H_

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_2156 {

using Func = std::function<std::string(const std::string&, int, int, int, int)>;

class FindSubstringWithGivenHashValueSolution : public SolutionBase<Func> {
 public:
  FindSubstringWithGivenHashValueSolution();

  std::string subStrHash(const std::string& s, int power, int modulo, int k,
                         int hashValue);
};

}  // namespace leetcode::problem_2156

#endif  // LEETCODE_PROBLEMS_FIND_SUBSTRING_WITH_GIVEN_HASH_VALUE_H_
