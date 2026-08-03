#include "leetcode/problems/decode-xored-permutation.h"

namespace {

std::vector<int> decodeImpl(std::vector<int>& encoded) {
  int n = static_cast<int>(encoded.size()) + 1;

  // XOR of 1..n. Since n is always odd:
  //   n % 4 == 1  ->  1
  //   n % 4 == 3  ->  0
  int total_xor = (n % 4 == 1) ? 1 : 0;

  // XOR of encoded elements at odd indices (1, 3, 5, ...)
  // This equals perm[1] ^ perm[2] ^ ... ^ perm[n-1]
  int odd_xor = 0;
  for (int i = 1; i < static_cast<int>(encoded.size()); i += 2) {
    odd_xor ^= encoded[i];
  }

  int first = total_xor ^ odd_xor;

  std::vector<int> perm(n);
  perm[0] = first;
  for (int i = 0; i < static_cast<int>(encoded.size()); ++i) {
    perm[i + 1] = perm[i] ^ encoded[i];
  }

  return perm;
}

}  // namespace

namespace leetcode {
namespace problem_1734 {

std::vector<int> DecodeXoredPermutationSolution::decode(std::vector<int>& encoded) {
  return getSolution()(encoded);
}

DecodeXoredPermutationSolution::DecodeXoredPermutationSolution() {
  setMetaInfo({.id = 1734,
               .title = "Decode XORed Permutation",
               .url = "https://leetcode.com/problems/decode-xored-permutation/"});

  registerStrategy({.name = "XOR Total and Odd Index",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Bit Manipulation"}},
                   decodeImpl);

  setDefaultStrategy();
}

}  // namespace problem_1734
}  // namespace leetcode
