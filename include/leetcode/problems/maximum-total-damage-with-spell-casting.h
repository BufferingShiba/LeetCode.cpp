#ifndef LEETCODE_PROBLEMS_MAXIMUM_TOTAL_DAMAGE_WITH_SPELL_CASTING_H
#define LEETCODE_PROBLEMS_MAXIMUM_TOTAL_DAMAGE_WITH_SPELL_CASTING_H

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3186 {

using Func = std::function<long long(std::vector<int>&)>;

class MaximumTotalDamageWithSpellCastingSolution : public SolutionBase<Func> {
 public:
  MaximumTotalDamageWithSpellCastingSolution();

  long long maximumTotalDamage(std::vector<int>& power);
};

}  // namespace problem_3186
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_TOTAL_DAMAGE_WITH_SPELL_CASTING_H
