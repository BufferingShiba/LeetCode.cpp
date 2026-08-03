#include "leetcode/core.h"
#include <functional>

namespace leetcode::problem_3875 {

using Func = std::function<bool(std::vector<int>&)>;

class ConstructUniformParityArrayISolution : public SolutionBase<Func> {
 public:
  bool uniformArray(std::vector<int>& nums1);

  ConstructUniformParityArrayISolution();
};

}  // namespace leetcode::problem_3875
