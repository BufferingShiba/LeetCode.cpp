#ifndef LEETCODE_PROBLEM_3210_FIND_THE_ENCRYPTED_STRING_H
#define LEETCODE_PROBLEM_3210_FIND_THE_ENCRYPTED_STRING_H

#include "leetcode/core.h"

namespace leetcode::problem_3210 {

using Func = std::function<std::string(std::string, int)>;

class FindTheEncryptedStringSolution : public SolutionBase<Func> {
 public:
  FindTheEncryptedStringSolution();
  std::string getEncryptedString(std::string s, int k);
};

}  // namespace leetcode::problem_3210

#endif
