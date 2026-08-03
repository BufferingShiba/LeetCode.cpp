#include "leetcode/core.h"

namespace leetcode {
namespace problem_347 {

using Func = std::function<vector<int>(vector<int>&, int)>;

class TopKFrequentElementsSolution : public SolutionBase<Func> {
 public:
  //! 347. Top K Frequent Elements
  //! https://leetcode.com/problems/top-k-frequent-elements/
  vector<int> topKFrequent(vector<int>& nums, int k);

  TopKFrequentElementsSolution();
};

}  // namespace problem_347
}  // namespace leetcode
