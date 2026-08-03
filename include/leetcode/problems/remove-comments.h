#ifndef LEETCODE_PROBLEMS_REMOVE_COMMENTS_H__
#define LEETCODE_PROBLEMS_REMOVE_COMMENTS_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_722 {

using Func = std::function<std::vector<std::string>(std::vector<std::string>&)>;

class RemoveCommentsSolution : public SolutionBase<Func> {
 public:
  RemoveCommentsSolution();

  // 题目公开方法
  std::vector<std::string> removeComments(std::vector<std::string>& source);
};

}  // namespace problem_722
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_REMOVE_COMMENTS_H__
