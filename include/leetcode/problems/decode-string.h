#include "leetcode/core.h"

namespace leetcode {
namespace problem_394 {

using Func = std::function<string(string)>;

class DecodeStringSolution : public SolutionBase<Func> {
 public:
  //! 394. Decode String
  //! https://leetcode.com/problems/decode-string/
  string decodeString(string s);

  DecodeStringSolution();
};

}  // namespace problem_394
}  // namespace leetcode
