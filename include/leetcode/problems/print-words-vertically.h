#ifndef LEETCODE_PROBLEM_1324_H_
#define LEETCODE_PROBLEM_1324_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1324 {

using Func = std::function<std::vector<std::string>(std::string)>;

class PrintWordsVerticallySolution : public SolutionBase<Func> {
 public:
  std::vector<std::string> printVertically(std::string s);

  PrintWordsVerticallySolution();
};

}  // namespace problem_1324
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_1324_H_
