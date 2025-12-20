#include "leetcode/core.h"

namespace leetcode {
namespace problem_944 {

using Func = std::function<int(vector<string>&)>;

class DeleteColumnsToMakeSortedSolution : public SolutionBase<Func> {
 public:
  //! 944. Delete Columns to Make Sorted
  //! https://leetcode.com/problems/delete-columns-to-make-sorted/
  int minDeletionSize(vector<string>& strs);

  DeleteColumnsToMakeSortedSolution();
};

}  // namespace problem_944
}  // namespace leetcode