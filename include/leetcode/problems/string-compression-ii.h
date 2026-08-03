#ifndef LEETCODE_PROBLEM_1531_H_
#define LEETCODE_PROBLEM_1531_H_

#include <string>
#include <functional>
#include "leetcode/core.h"

namespace leetcode {
namespace problem_1531 {

using Func = std::function<int(std::string, int)>;

class StringCompressionIiSolution : public SolutionBase<Func> {
 public:
  StringCompressionIiSolution();

  int getLengthOfOptimalCompression(std::string s, int k);
};

}  // namespace problem_1531
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_1531_H_
