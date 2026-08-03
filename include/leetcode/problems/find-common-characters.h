#ifndef LEETCODE_PROBLEMS_FIND_COMMON_CHARACTERS_H__
#define LEETCODE_PROBLEMS_FIND_COMMON_CHARACTERS_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1002 {

using Func = std::function<std::vector<std::string>(std::vector<std::string>&)>;

class FindCommonCharactersSolution : public SolutionBase<Func> {
 public:
  FindCommonCharactersSolution();

  std::vector<std::string> commonChars(std::vector<std::string>& words);
};

}  // namespace problem_1002
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_COMMON_CHARACTERS_H__
