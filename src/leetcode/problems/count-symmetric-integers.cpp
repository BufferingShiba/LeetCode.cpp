#include "leetcode/problems/count-symmetric-integers.h"

#include <string>

namespace leetcode::problem_2843 {

namespace {

bool isSymmetric(int x) {
  std::string s = std::to_string(x);
  const int n = static_cast<int>(s.size());
  if (n % 2 == 1) {
    return false;
  }
  int leftSum = 0;
  int rightSum = 0;
  for (int i = 0; i < n / 2; ++i) {
    leftSum += s[i] - '0';
    rightSum += s[n - 1 - i] - '0';
  }
  return leftSum == rightSum;
}

int countSymmetricIntegersImpl(int low, int high) {
  int count = 0;
  for (int x = low; x <= high; ++x) {
    if (isSymmetric(x)) {
      ++count;
    }
  }
  return count;
}

}  // namespace

CountSymmetricIntegersSolution::CountSymmetricIntegersSolution() {
  setMetaInfo({.id = 2843,
               .title = "Count Symmetric Integers",
               .url = "https://leetcode.com/problems/count-symmetric-integers/"});
  registerStrategy({.name = "BruteForceEnumeration",
                    .expected = "Accepted",
                    .time_complexity = "O((high-low+1) * d)",
                    .space_complexity = "O(d)",
                    .tags = {"Math", "Enumeration"}},
                   countSymmetricIntegersImpl);
}

int CountSymmetricIntegersSolution::countSymmetricIntegers(int low, int high) {
  return getSolution()(low, high);
}

}  // namespace leetcode::problem_2843
