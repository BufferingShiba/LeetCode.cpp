#ifndef LEETCODE_PROBLEMS_LATEST_TIME_YOU_CAN_OBTAIN_AFTER_REPLACING_CHARACTERS_H__
#define LEETCODE_PROBLEMS_LATEST_TIME_YOU_CAN_OBTAIN_AFTER_REPLACING_CHARACTERS_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3114 {

using Func = std::function<std::string(std::string)>;

class LatestTimeYouCanObtainAfterReplacingCharactersSolution
    : public SolutionBase<Func> {
 public:
  LatestTimeYouCanObtainAfterReplacingCharactersSolution();

  std::string findLatestTime(std::string s);
};

}  // namespace problem_3114
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_LATEST_TIME_YOU_CAN_OBTAIN_AFTER_REPLACING_CHARACTERS_H__
