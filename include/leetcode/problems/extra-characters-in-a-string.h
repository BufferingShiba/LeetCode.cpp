#ifndef LEETCODE_PROBLEM_2707_H_
#define LEETCODE_PROBLEM_2707_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2707 {

using Func = std::function<int(std::string, std::vector<std::string>&)>;

class ExtraCharactersInAStringSolution : public SolutionBase<Func> {
 public:
  ExtraCharactersInAStringSolution();
  int minExtraChar(std::string s, std::vector<std::string>& dictionary);
};

}  // namespace problem_2707
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_2707_H_
