#include "leetcode/problems/categorize-box-according-to-criteria.h"

namespace leetcode {
namespace problem_2525 {

namespace {

std::string categorizeBoxImpl(int length, int width, int height, int mass) {
  bool bulky = false;
  if (length >= 10000 || width >= 10000 || height >= 10000) {
    bulky = true;
  }
  long long volume = static_cast<long long>(length) * width * height;
  if (volume >= 1000000000LL) {
    bulky = true;
  }

  bool heavy = mass >= 100;

  if (bulky && heavy) {
    return "Both";
  }
  if (bulky) {
    return "Bulky";
  }
  if (heavy) {
    return "Heavy";
  }
  return "Neither";
}

}  // namespace

CategorizeBoxAccordingToCriteriaSolution::CategorizeBoxAccordingToCriteriaSolution() {
  setMetaInfo({2525, "Categorize Box According to Criteria",
               "https://leetcode.com/problems/categorize-box-according-to-criteria/"});
  registerStrategy(
      {.name = "DirectCondition",
       .expected = "Accepted",
       .time_complexity = "O(1)",
       .space_complexity = "O(1)",
       .tags = {"Math"}},
      categorizeBoxImpl);
}

std::string CategorizeBoxAccordingToCriteriaSolution::categorizeBox(
    int length, int width, int height, int mass) {
  return getSolution()(length, width, height, mass);
}

}  // namespace problem_2525
}  // namespace leetcode
