#include "leetcode/core.h"

namespace leetcode {
namespace problem_3612 {

using Func = std::function<string(string)>;

class ProcessStringWithSpecialOperationsISolution : public SolutionBase<Func> {
 public:
  //! 3612. Process String with Special Operations I
  //! https://leetcode.com/problems/process-string-with-special-operations-i/
  string processStr(string s);

  ProcessStringWithSpecialOperationsISolution();
};

}  // namespace problem_3612
}  // namespace leetcode
