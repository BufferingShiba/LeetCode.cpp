#include "leetcode/problems/rings-and-rods.h"

namespace leetcode {
namespace problem_2103 {
namespace {

int countPointsImpl(std::string rings) {
  int masks[10] = {0};
  for (std::size_t i = 0; i < rings.size(); i += 2) {
    char color = rings[i];
    int rod = rings[i + 1] - '0';
    int bit = (color == 'R') ? 1 : (color == 'G') ? 2 : 4;
    masks[rod] |= bit;
  }
  int count = 0;
  for (int m : masks) {
    if (m == 7) ++count;
  }
  return count;
}

}  // namespace

RingsAndRodsSolution::RingsAndRodsSolution() {
  setMetaInfo({.id = 2103,
               .title = "Rings and Rods",
               .url = "https://leetcode.com/problems/rings-and-rods/"});
  registerStrategy({
                       .name = "bitmask",
                       .expected = "Accepted",
                       .time_complexity = "O(n)",
                       .space_complexity = "O(1)",
                       .tags = {"Hash Table", "String"},
                   },
                   countPointsImpl);
}

int RingsAndRodsSolution::countPoints(std::string rings) {
  return getSolution()(std::move(rings));
}

}  // namespace problem_2103
}  // namespace leetcode
