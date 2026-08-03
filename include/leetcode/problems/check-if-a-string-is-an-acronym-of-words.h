#ifndef LEETCODE_PROBLEMS_CHECK_IF_A_STRING_IS_AN_ACRONYM_OF_WORDS_H_
#define LEETCODE_PROBLEMS_CHECK_IF_A_STRING_IS_AN_ACRONYM_OF_WORDS_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2828 {

using Func = std::function<bool(std::vector<std::string>&, std::string)>;

class CheckIfAStringIsAnAcronymOfWordsSolution
    : public SolutionBase<Func> {
 public:
  CheckIfAStringIsAnAcronymOfWordsSolution();
  bool isAcronym(std::vector<std::string>& words, std::string s);
};

}  // namespace problem_2828
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CHECK_IF_A_STRING_IS_AN_ACRONYM_OF_WORDS_H_
