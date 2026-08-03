#ifndef LEETCODE_PROBLEMS_CRAWLER_LOG_FOLDER_H_
#define LEETCODE_PROBLEMS_CRAWLER_LOG_FOLDER_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1598 {

using Func = std::function<int(std::vector<std::string>&)>;

class CrawlerLogFolderSolution : public SolutionBase<Func> {
 public:
  CrawlerLogFolderSolution();
  int minOperations(std::vector<std::string>& logs);
};

}  // namespace problem_1598
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CRAWLER_LOG_FOLDER_H_
