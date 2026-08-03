#include "leetcode/problems/maximum-height-of-a-triangle.h"

namespace leetcode {
namespace problem_3200 {

static int solution1(int red, int blue) {
  auto build = [](int a, int b) -> int {
    int height = 0;
    int row = 1;
    bool useA = true;
    while (true) {
      if (useA) {
        if (a < row) break;
        a -= row;
      } else {
        if (b < row) break;
        b -= row;
      }
      ++height;
      ++row;
      useA = !useA;
    }
    return height;
  };
  return std::max(build(red, blue), build(blue, red));
}

MaximumHeightOfATriangleSolution::MaximumHeightOfATriangleSolution() {
  setMetaInfo({
      .id = 3200,
      .title = "Maximum Height of a Triangle",
      .url = "https://leetcode.com/problems/maximum-height-of-a-triangle"
  });
  registerStrategy({.name = "Brute Force"}, solution1);
}

int MaximumHeightOfATriangleSolution::maxHeightOfTriangle(int red, int blue) {
  return getSolution()(red, blue);
}

}  // namespace problem_3200
}  // namespace leetcode
