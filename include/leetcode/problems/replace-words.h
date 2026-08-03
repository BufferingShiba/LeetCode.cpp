#ifndef LEETCODE_PROBLEMS_REPLACE_WORDS_H_
#define LEETCODE_PROBLEMS_REPLACE_WORDS_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_648 {

using Func = std::function<std::string(std::vector<std::string>&, std::string)>;

class ReplaceWordsSolution : public SolutionBase<Func> {
 public:
  ReplaceWordsSolution();
  std::string replaceWords(std::vector<std::string>& dictionary, std::string sentence);
};

}  // namespace leetcode::problem_648

#endif  // LEETCODE_PROBLEMS_REPLACE_WORDS_H_
