#ifndef LEETCODE_PROBLEMS_MAJORITY_FREQUENCY_CHARACTERS_H__
#define LEETCODE_PROBLEMS_MAJORITY_FREQUENCY_CHARACTERS_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3692 {

using Func = std::function<std::string(std::string)>;

class MajorityFrequencyCharactersSolution
    : public SolutionBase<Func> {
 public:
  MajorityFrequencyCharactersSolution();

  std::string majorityFrequencyGroup(std::string s);
};

}  // namespace problem_3692
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAJORITY_FREQUENCY_CHARACTERS_H__
