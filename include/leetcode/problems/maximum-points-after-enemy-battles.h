#ifndef LEETCODE_PROBLEMS_MAXIMUM_POINTS_AFTER_ENEMY_BATTLES_H__
#define LEETCODE_PROBLEMS_MAXIMUM_POINTS_AFTER_ENEMY_BATTLES_H__

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode {
namespace problem_3207 {

using Func = std::function<long long(std::vector<int>&, int)>;

class MaximumPointsAfterEnemyBattlesSolution : public SolutionBase<Func> {
public:
    MaximumPointsAfterEnemyBattlesSolution();
    long long maximumPoints(std::vector<int>& enemyEnergies, int currentEnergy);
};

}  // namespace problem_3207
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_POINTS_AFTER_ENEMY_BATTLES_H__
