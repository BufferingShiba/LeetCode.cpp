#include "leetcode/problems/perfect-number.h"

namespace leetcode {
namespace problem_507 {

static bool solution1(int num) {
  if (num <= 1) {
    return false;
  }
  int sum = 1;  // 1 is always a divisor
  for (int i = 2; i * i <= num; ++i) {
    if (num % i == 0) {
      sum += i;
      if (i != num / i) {
        sum += num / i;
      }
    }
  }
  return sum == num;
}

PerfectNumberSolution::PerfectNumberSolution() {
  setMetaInfo({
      .id = 507,
      .title = "Perfect Number",
      .url = "https://leetcode.com/problems/perfect-number"
  });
  registerStrategy({.name = "Brute Force"}, solution1);
}

bool PerfectNumberSolution::checkPerfectNumber(int num) {
  return getSolution()(num);
}

}  // namespace problem_507
}  // namespace leetcode
