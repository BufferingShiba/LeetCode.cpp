#include "leetcode/core.h"

namespace leetcode {
namespace problem_393 {

using Func = std::function<bool(vector<int>&)>;

class Utf8ValidationSolution : public SolutionBase<Func> {
 public:
  //! 393. UTF-8 Validation
  //! https://leetcode.com/problems/utf-8-validation/
  bool validUtf8(vector<int>& data);

  Utf8ValidationSolution();
};

}  // namespace problem_393
}  // namespace leetcode
