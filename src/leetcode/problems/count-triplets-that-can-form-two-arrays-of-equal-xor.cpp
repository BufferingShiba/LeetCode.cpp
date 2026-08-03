#include "leetcode/problems/count-triplets-that-can-form-two-arrays-of-equal-xor.h"

namespace leetcode {
namespace problem_1442 {

static int solution1(vector<int>& arr) {
  const int n = static_cast<int>(arr.size());
  std::vector<int> prefix(n + 1, 0);
  for (int t = 0; t < n; ++t) {
    prefix[t + 1] = prefix[t] ^ arr[t];
  }
  int count = 0;
  for (int i = 0; i < n; ++i) {
    for (int k = i + 1; k < n; ++k) {
      if (prefix[i] == prefix[k + 1]) {
        count += k - i;
      }
    }
  }
  return count;
}

CountTripletsThatCanFormTwoArraysOfEqualXorSolution::CountTripletsThatCanFormTwoArraysOfEqualXorSolution() {
  setMetaInfo({
      .id = 1442,
      .title = "Count Triplets That Can Form Two Arrays of Equal XOR",
      .url = "https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor"
  });
  registerStrategy({
      .name = "Prefix XOR",
      .expected = "Accepted",
      .time_complexity = "O(n^2)",
      .space_complexity = "O(n)",
      .tags = {"array", "bit manipulation", "prefix xor"},
      .notes = "a==b 等价于 prefix[i]==prefix[k+1]，对每个 (i,k) 贡献 k-i 个 j"
  }, solution1);
}

int CountTripletsThatCanFormTwoArraysOfEqualXorSolution::countTriplets(vector<int>& arr) {
  return getSolution()(arr);
}

}  // namespace problem_1442
}  // namespace leetcode
