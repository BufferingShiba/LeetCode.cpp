#include "leetcode/core.h"

namespace leetcode {
namespace problem_8 {

using Func = std::function<int(string)>;

class StringToIntegerAtoiSolution : public SolutionBase<Func> {
 public:
  //! 8. String to Integer (atoi)
  //! https://leetcode.com/problems/string-to-integer-atoi/
  int myAtoi(string s);

  StringToIntegerAtoiSolution();
};

}  // namespace problem_8
}  // namespace leetcode
