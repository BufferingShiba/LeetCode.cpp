#include "leetcode/problems/remove-comments.h"

namespace leetcode {
namespace problem_722 {

namespace {

std::vector<std::string> removeCommentsImpl(std::vector<std::string>& source) {
  std::vector<std::string> result;
  bool inBlock = false;
  std::string cur;

  for (const std::string& line : source) {
    int i = 0;
    int n = static_cast<int>(line.size());
    while (i < n) {
      if (inBlock) {
        if (i + 1 < n && line[i] == '*' && line[i + 1] == '/') {
          inBlock = false;
          i += 2;
        } else {
          ++i;
        }
      } else {
        if (i + 1 < n && line[i] == '/' && line[i + 1] == '*') {
          inBlock = true;
          i += 2;
        } else if (i + 1 < n && line[i] == '/' && line[i + 1] == '/') {
          break;  // 跳过剩余行
        } else {
          cur.push_back(line[i]);
          ++i;
        }
      }
    }
    if (!inBlock && !cur.empty()) {
      result.push_back(cur);
      cur.clear();
    }
  }
  return result;
}

}  // namespace

RemoveCommentsSolution::RemoveCommentsSolution() {
  setMetaInfo({.id = 722,
               .title = "Remove Comments",
               .url = "https://leetcode.com/problems/remove-comments/"});
  registerStrategy(
      {.name = "StateMachine",
       .expected = "Accepted",
       .time_complexity = "O(N)",
       .space_complexity = "O(N)",
       .tags = {"Array", "String"},
       .notes =
           "单趟扫描状态机：维护块注释状态，遇 // 跳过行，遇 /* 进入块注释，遇 */ 退出"},
      removeCommentsImpl);
}

std::vector<std::string> RemoveCommentsSolution::removeComments(
    std::vector<std::string>& source) {
  return getSolution()(source);
}

}  // namespace problem_722
}  // namespace leetcode
