#include "leetcode/problems/maximum-containers-on-a-ship.h"

#include <algorithm>
#include <cstdint>

namespace leetcode {
namespace problem_3492 {

namespace {

int maxContainersImpl(int n, int w, int maxWeight) {
  long long cells = static_cast<long long>(n) * n;
  long long weightLimit = maxWeight / w;
  return static_cast<int>(std::min(cells, weightLimit));
}

}  // namespace

MaximumContainersOnAShipSolution::MaximumContainersOnAShipSolution() {
  setMetaInfo({3492, "Maximum Containers on a Ship",
               "https://leetcode.com/problems/maximum-containers-on-a-ship/"});
  registerStrategy({"greedy-math", "Accepted", "O(1)", "O(1)", {"Math"}},
                    maxContainersImpl);
}

int MaximumContainersOnAShipSolution::maxContainers(int n, int w,
                                                     int maxWeight) {
  return getSolution()(n, w, maxWeight);
}

}  // namespace problem_3492
}  // namespace leetcode
