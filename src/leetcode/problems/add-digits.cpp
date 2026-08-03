#include "leetcode/problems/add-digits.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_258 {

namespace {

int addDigitsImpl(int num) {
  if (num == 0) return 0;
  return 1 + (num - 1) % 9;
}

}  // namespace

AddDigitsSolution::AddDigitsSolution() {
  setMetaInfo({.id = 258,
               .title = "Add Digits",
               .url = "https://leetcode.com/problems/add-digits/"});
  registerStrategy(
      {.name = "DigitalRoot",
       .expected = "Accepted",
       .time_complexity = "O(1)",
       .space_complexity = "O(1)",
       .tags = {"Math", "Number Theory"}},
      addDigitsImpl);
}

int AddDigitsSolution::addDigits(int num) { return getSolution()(num); }

}  // namespace problem_258
}  // namespace leetcode
