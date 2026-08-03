#include "leetcode/problems/construct-the-rectangle.h"

#include <cmath>

namespace leetcode {
namespace problem_492 {

namespace {

std::vector<int> constructRectangleImpl(int area) {
  int w = static_cast<int>(std::sqrt(area));
  while (area % w != 0) {
    --w;
  }
  return {area / w, w};
}

}  // namespace

ConstructTheRectangleSolution::ConstructTheRectangleSolution() {
  setMetaInfo({.id = 492,
               .title = "Construct the Rectangle",
               .url = "https://leetcode.com/problems/construct-the-rectangle/"});

  registerStrategy({.name = "sqrt-downward",
                    .expected = "Accepted",
                    .time_complexity = "O(sqrt(n))",
                    .space_complexity = "O(1)",
                    .tags = {"Math"}},
                   constructRectangleImpl);

  setDefaultStrategy();
}

std::vector<int> ConstructTheRectangleSolution::constructRectangle(int area) {
  return getSolution()(area);
}

}  // namespace problem_492
}  // namespace leetcode
