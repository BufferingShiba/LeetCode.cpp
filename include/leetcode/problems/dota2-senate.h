#ifndef LEETCODE_PROBLEMS_DOTA2_SENATE_H_
#define LEETCODE_PROBLEMS_DOTA2_SENATE_H_

#include <functional>
#include <string>
#include "leetcode/core.h"

namespace leetcode {
namespace problem_649 {

using Func = std::function<std::string(std::string)>;

class Dota2SenateSolution : public SolutionBase<Func> {
 public:
  Dota2SenateSolution();

  std::string predictPartyVictory(std::string senate);
};

}  // namespace problem_649
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_DOTA2_SENATE_H_
