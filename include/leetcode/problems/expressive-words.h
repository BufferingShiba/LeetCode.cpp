#ifndef LEETCODE_PROBLEM_809_H_
#define LEETCODE_PROBLEM_809_H_

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_809 {

using Func = std::function<int(std::string, std::vector<std::string>&)>;

class ExpressiveWordsSolution : public SolutionBase<Func> {
 public:
  ExpressiveWordsSolution();

  int expressiveWords(std::string s, std::vector<std::string>& words);
};

}  // namespace problem_809
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_809_H_
