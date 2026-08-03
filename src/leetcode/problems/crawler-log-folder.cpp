#include <string>
#include <vector>

#include "leetcode/problems/crawler-log-folder.h"

namespace leetcode {
namespace problem_1598 {

namespace {

int minOperationsImpl(std::vector<std::string>& logs) {
  int depth = 0;
  for (const auto& log : logs) {
    if (log == "../") {
      if (depth > 0) --depth;
    } else if (log == "./") {
      // remain in the same folder
    } else {
      ++depth;
    }
  }
  return depth;
}

}  // namespace

CrawlerLogFolderSolution::CrawlerLogFolderSolution() {
  setMetaInfo({.id = 1598,
               .title = "Crawler Log Folder",
               .url = "https://leetcode.com/problems/crawler-log-folder/"});
  registerStrategy({.name = "DepthCounting",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "String"}},
                   minOperationsImpl);
}

int CrawlerLogFolderSolution::minOperations(std::vector<std::string>& logs) {
  return getSolution()(logs);
}

}  // namespace problem_1598
}  // namespace leetcode
