#ifndef LEETCODE_PROBLEMS_GENERATE_A_STRING_WITH_CHARACTERS_THAT_HAVE_ODD_COUNTS_H_
#define LEETCODE_PROBLEMS_GENERATE_A_STRING_WITH_CHARACTERS_THAT_HAVE_ODD_COUNTS_H_

#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1374 {

using Func = std::function<std::string(int)>;

class GenerateAStringWithCharactersThatHaveOddCountsSolution : public SolutionBase<Func> {
 public:
  GenerateAStringWithCharactersThatHaveOddCountsSolution();

  std::string generateTheString(int n);
};

}  // namespace problem_1374
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_GENERATE_A_STRING_WITH_CHARACTERS_THAT_HAVE_ODD_COUNTS_H_
