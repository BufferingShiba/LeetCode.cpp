#include "leetcode/problems/maximum-points-after-enemy-battles.h"

#include <algorithm>
#include <numeric>

namespace leetcode {
namespace problem_3207 {

namespace {

long long maximumPointsImpl(std::vector<int>& enemyEnergies, int currentEnergy) {
    long long minE = *std::min_element(enemyEnergies.begin(), enemyEnergies.end());
    if (static_cast<long long>(currentEnergy) < minE) {
        return 0;
    }
    long long sum =
        std::accumulate(enemyEnergies.begin(), enemyEnergies.end(), 0LL);
    // 第一分消耗 minE，然后吸收所有其他 (n-1) 个敌人获得 (sum - minE) 能量。
    long long totalEnergy =
        static_cast<long long>(currentEnergy) - minE + (sum - minE);
    return 1 + totalEnergy / minE;
}

}  // namespace

MaximumPointsAfterEnemyBattlesSolution::MaximumPointsAfterEnemyBattlesSolution() {
    this->setMetaInfo({
        .id = 3207,
        .title = "Maximum Points After Enemy Battles",
        .url =
            "https://leetcode.com/problems/maximum-points-after-enemy-battles/",
    });
    this->registerStrategy(
        {
            .name = "greedy",
            .expected = "Accepted",
            .time_complexity = "O(n)",
            .space_complexity = "O(1)",
            .tags = {"Array", "Greedy"},
        },
        maximumPointsImpl);
}

long long MaximumPointsAfterEnemyBattlesSolution::maximumPoints(
    std::vector<int>& enemyEnergies, int currentEnergy) {
    return this->getSolution()(enemyEnergies, currentEnergy);
}

}  // namespace problem_3207
}  // namespace leetcode
