#ifndef LEETCODE_PROBLEMS_DECODE_THE_MESSAGE_H__
#define LEETCODE_PROBLEMS_DECODE_THE_MESSAGE_H__

#include "leetcode/core.h"

#include <functional>
#include <string>

namespace leetcode {
namespace problem_2325 {

using Func = std::function<std::string(std::string, std::string)>;

class DecodeTheMessageSolution : public SolutionBase<Func> {
 public:
  DecodeTheMessageSolution();
  std::string decodeMessage(std::string key, std::string message);
};

}  // namespace problem_2325
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_DECODE_THE_MESSAGE_H__
