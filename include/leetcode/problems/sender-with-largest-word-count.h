#ifndef LEETCODE_PROBLEMS_SENDER_WITH_LARGEST_WORD_COUNT_H__
#define LEETCODE_PROBLEMS_SENDER_WITH_LARGEST_WORD_COUNT_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_2284 {

using Func = std::function<std::string(std::vector<std::string>&,
                                       std::vector<std::string>&)>;

class SenderWithLargestWordCountSolution
    : public SolutionBase<Func> {
 public:
  SenderWithLargestWordCountSolution();

  std::string largestWordCount(std::vector<std::string>& messages,
                               std::vector<std::string>& senders) {
    return getSolution()(messages, senders);
  }
};

}  // namespace problem_2284
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SENDER_WITH_LARGEST_WORD_COUNT_H__
