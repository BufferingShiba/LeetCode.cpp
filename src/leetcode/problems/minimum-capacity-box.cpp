#include "leetcode/problems/minimum-capacity-box.h"

#include <algorithm>

namespace leetcode {
namespace problem_3861 {

namespace {

int linearScanImpl(std::vector<int>& capacity, int itemSize) {
  int bestIndex = -1;
  int bestCapacity = -1;
  for (int i = 0; i < static_cast<int>(capacity.size()); ++i) {
    if (capacity[i] >= itemSize &&
        (bestIndex == -1 || capacity[i] < bestCapacity)) {
      bestIndex = i;
      bestCapacity = capacity[i];
    }
  }
  return bestIndex;
}

}  // namespace

int MinimumCapacityBoxSolution::minimumIndex(std::vector<int>& capacity,
                                             int itemSize) {
  return getSolution()(capacity, itemSize);
}

int MinimumCapacityBoxSolution::minimumIndexImpl(std::vector<int>& capacity,
                                                 int itemSize) {
  return linearScanImpl(capacity, itemSize);
}

}  // namespace problem_3861
}  // namespace leetcode
