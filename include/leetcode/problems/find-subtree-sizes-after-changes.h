#ifndef LEETCODE_PROBLEMS_FIND_SUBTREE_SIZES_AFTER_CHANGES_H__
#define LEETCODE_PROBLEMS_FIND_SUBTREE_SIZES_AFTER_CHANGES_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3331 {

using Func = std::function<std::vector<int>(std::vector<int>&, std::string)>;

class FindSubtreeSizesAfterChangesSolution : public SolutionBase<Func> {
 public:
  FindSubtreeSizesAfterChangesSolution();

  std::vector<int> findSubtreeSizes(std::vector<int>& parent, std::string s);
};

}  // namespace problem_3331
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_SUBTREE_SIZES_AFTER_CHANGES_H__
