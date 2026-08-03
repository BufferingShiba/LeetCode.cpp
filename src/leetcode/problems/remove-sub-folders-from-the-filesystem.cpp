#include "leetcode/problems/remove-sub-folders-from-the-filesystem.h"

#include <algorithm>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_1233 {
namespace {

std::vector<std::string> removeSubfoldersImpl(std::vector<std::string>& folder) {
  std::sort(folder.begin(), folder.end());
  std::vector<std::string> result;
  for (const std::string& path : folder) {
    if (!result.empty() &&
        path.size() > result.back().size() &&
        path.compare(0, result.back().size(), result.back()) == 0 &&
        path[result.back().size()] == '/') {
      continue;
    }
    result.push_back(path);
  }
  return result;
}

}  // namespace

RemoveSubFoldersFromTheFilesystemSolution::
    RemoveSubFoldersFromTheFilesystemSolution() {
  setMetaInfo({.id = 1233,
               .title = "Remove Sub-Folders from the Filesystem",
               .url = "https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/"});
  registerStrategy(
      {"SortAndPrefixCheck", "Accepted", "O(n log n * L)", "O(n)",
       {"Array", "String", "Sorting"}},
      removeSubfoldersImpl);
}

std::vector<std::string>
RemoveSubFoldersFromTheFilesystemSolution::removeSubfolders(
    std::vector<std::string>& folder) {
  return getSolution()(folder);
}

}  // namespace problem_1233
}  // namespace leetcode
