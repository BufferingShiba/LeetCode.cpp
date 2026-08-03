#ifndef LEETCODE_PROBLEMS_DESIGN_BROWSER_HISTORY_H_
#define LEETCODE_PROBLEMS_DESIGN_BROWSER_HISTORY_H_

#include <string>
#include <vector>

namespace leetcode {
namespace problem_1472 {

class BrowserHistory {
 public:
  explicit BrowserHistory(std::string homepage);

  void visit(std::string url);

  std::string back(int steps);

  std::string forward(int steps);

 private:
  std::vector<std::string> history_;
  int cur_;
  int sz_;
};

}  // namespace problem_1472
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_DESIGN_BROWSER_HISTORY_H_
