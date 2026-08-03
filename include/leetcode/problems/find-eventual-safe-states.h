#include "leetcode/core.h"

namespace leetcode {
namespace problem_802 {

using Func = std::function<vector<int>(vector<vector<int>>&)>;

class FindEventualSafeStatesSolution : public SolutionBase<Func> {
 public:
  //! 802. Find Eventual Safe States
  //! https://leetcode.com/problems/find-eventual-safe-states/
  vector<int> eventualSafeNodes(vector<vector<int>>& graph);

  FindEventualSafeStatesSolution();
};

}  // namespace problem_802
}  // namespace leetcode
