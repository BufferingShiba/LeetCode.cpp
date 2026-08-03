#include "leetcode/problems/find-the-prefix-common-array-of-two-arrays.h"

namespace leetcode {
namespace problem_2657 {

namespace {

std::vector<int> findThePrefixCommonArrayImpl(std::vector<int>& A,
                                              std::vector<int>& B) {
  int n = static_cast<int>(A.size());
  std::vector<int> seen(n + 1, 0);
  std::vector<int> result(n, 0);
  int common = 0;
  for (int i = 0; i < n; ++i) {
    if (++seen[A[i]] == 2) ++common;
    if (++seen[B[i]] == 2) ++common;
    result[i] = common;
  }
  return result;
}

}  // namespace

FindThePrefixCommonArrayOfTwoArraysSolution::
    FindThePrefixCommonArrayOfTwoArraysSolution() {
  setMetaInfo({2657,
               "Find the Prefix Common Array of Two Arrays",
               "https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/"});
  registerStrategy(
      {"counting-in-one-pass", "Accepted", "O(n)", "O(n)",
       {"Array", "Hash Table", "Bit Manipulation"}, "单遍扫描计数，达到2即为共同元素"},
      findThePrefixCommonArrayImpl);
}

std::vector<int> FindThePrefixCommonArrayOfTwoArraysSolution::
    findThePrefixCommonArray(std::vector<int>& A, std::vector<int>& B) {
  return getSolution()(A, B);
}

}  // namespace problem_2657
}  // namespace leetcode
