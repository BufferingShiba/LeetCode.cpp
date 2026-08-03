
#include "leetcode/core.h"

namespace leetcode {
namespace problem_880 {

using Func = std::function<std::string(std::string, int)>;

class DecodedStringAtIndexSolution : public SolutionBase<Func> {
 public:
  //! 880. Decoded String at Index
  //! https://leetcode.com/problems/decoded-string-at-index/
  std::string decodeAtIndex(std::string s, int k);

  DecodedStringAtIndexSolution();
};

}  // namespace problem_880
}  // namespace leetcode
