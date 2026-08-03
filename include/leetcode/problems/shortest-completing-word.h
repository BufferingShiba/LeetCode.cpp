#ifndef LEETCODE_PROBLEMS_SHORTEST_COMPLETING_WORD_H__
#define LEETCODE_PROBLEMS_SHORTEST_COMPLETING_WORD_H__

#include "leetcode/core.h"
#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_748 {

using Func = std::function<std::string(std::string, std::vector<std::string>&)>;

class ShortestCompletingWordSolution
    : public SolutionBase<Func> {
 public:
  ShortestCompletingWordSolution();

  std::string shortestCompletingWord(std::string licensePlate,
                                     std::vector<std::string>& words);
};

}  // namespace problem_748
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SHORTEST_COMPLETING_WORD_H__
