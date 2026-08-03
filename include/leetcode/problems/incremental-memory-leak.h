#include "leetcode/core.h"

namespace leetcode {
namespace problem_1860 {

using Func = std::function<vector<int>(int, int)>;

class IncrementalMemoryLeakSolution : public SolutionBase<Func> {
 public:
  //! 1860. Incremental Memory Leak
  //! https://leetcode.com/problems/incremental-memory-leak/
  vector<int> memLeak(int memory1, int memory2);

  IncrementalMemoryLeakSolution();
};

}  // namespace problem_1860
}  // namespace leetcode
