#include "leetcode/problems/number-of-senior-citizens.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_2678 {

namespace {

int countSeniorsImpl(std::vector<std::string>& details) {
  int count = 0;
  for (const auto& d : details) {
    int age = (d[11] - '0') * 10 + (d[12] - '0');
    if (age > 60) {
      ++count;
    }
  }
  return count;
}

}  // namespace

NumberOfSeniorCitizensSolution::NumberOfSeniorCitizensSolution() {
  setMetaInfo({2678, "Number of Senior Citizens",
               "https://leetcode.com/problems/number-of-senior-citizens/"});
  registerStrategy({.name = "LinearScan",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "String"}},
                   countSeniorsImpl);
}

int NumberOfSeniorCitizensSolution::countSeniors(
    std::vector<std::string>& details) {
  return getSolution()(details);
}

}  // namespace problem_2678
}  // namespace leetcode
