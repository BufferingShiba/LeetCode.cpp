#include "leetcode/problems/prime-in-diagonal.h"

namespace leetcode {
namespace problem_2614 {

namespace {

bool isPrime(int x) {
  if (x < 2) return false;
  for (int d = 2; static_cast<long long>(d) * d <= x; ++d) {
    if (x % d == 0) return false;
  }
  return true;
}

int diagonalPrimeImpl(std::vector<std::vector<int>>& nums) {
  const int n = static_cast<int>(nums.size());
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (isPrime(nums[i][i]) && nums[i][i] > ans) ans = nums[i][i];
    const int j = n - i - 1;
    if (isPrime(nums[i][j]) && nums[i][j] > ans) ans = nums[i][j];
  }
  return ans;
}

}  // namespace

PrimeInDiagonalSolution::PrimeInDiagonalSolution() {
  setMetaInfo({.id = 2614,
               .title = "Prime In Diagonal",
               .url = "https://leetcode.com/problems/prime-in-diagonal/"});
  registerStrategy({.name = "Diagonal Traversal + Trial Division",
                    .expected = "Accepted",
                    .time_complexity = "O(n * sqrt(maxVal))",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Math", "Matrix", "Number Theory"}},
                   diagonalPrimeImpl);
}

int PrimeInDiagonalSolution::diagonalPrime(std::vector<std::vector<int>>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_2614
}  // namespace leetcode
