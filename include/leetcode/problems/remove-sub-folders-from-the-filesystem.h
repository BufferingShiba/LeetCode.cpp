#ifndef LEETCODE_PROBLEMS_REMOVE_SUB_FOLDERS_FROM_THE_FILESYSTEM_H__
#define LEETCODE_PROBLEMS_REMOVE_SUB_FOLDERS_FROM_THE_FILESYSTEM_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_1233 {

using Func = std::function<std::vector<std::string>(std::vector<std::string>&)>;

class RemoveSubFoldersFromTheFilesystemSolution
    : public SolutionBase<Func> {
 public:
  RemoveSubFoldersFromTheFilesystemSolution();

  std::vector<std::string> removeSubfolders(std::vector<std::string>& folder);
};

}  // namespace problem_1233
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_REMOVE_SUB_FOLDERS_FROM_THE_FILESYSTEM_H__
