#include "leetcode/problems/type-of-triangle.h"

namespace leetcode {
namespace problem_3024 {

static std::string triangleTypeImpl(std::vector<int>& nums) {
  int a = nums[0], b = nums[1], c = nums[2];

  // Check triangle inequality: sum of any two sides > third side
  if (a + b <= c || a + c <= b || b + c <= a) {
    return "none";
  }

  // Determine triangle type
  if (a == b && b == c) {
    return "equilateral";
  }
  if (a == b || b == c || a == c) {
    return "isosceles";
  }
  return "scalene";
}

TypeOfTriangleSolution::TypeOfTriangleSolution() {
  setMetaInfo({.id = 3024, .title = "Type of Triangle",
               .url = "https://leetcode.com/problems/type-of-triangle/"});
  registerStrategy(
      {.name = "TriangleInequality",
       .expected = "Accepted",
       .time_complexity = "O(1)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Math"}},
      triangleTypeImpl);
}

std::string TypeOfTriangleSolution::triangleType(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3024
}  // namespace leetcode
