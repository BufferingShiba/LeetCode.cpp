#include "leetcode/problems/duplicate-zeros.h"

namespace leetcode {
namespace problem_1089 {

namespace {

void duplicateZerosImpl(std::vector<int>& arr) {
  int n = static_cast<int>(arr.size());

  // Find the prefix whose expanded form reaches the end of the array.  The
  // last zero may fit only once, so keep it separate from the normal copy.
  int duplicateCount = 0;
  int last = 0;
  while (last + duplicateCount < n) {
    if (arr[last] == 0) {
      ++duplicateCount;
    }
    ++last;
  }

  int read = last - 1;
  int write = n - 1;
  if (last + duplicateCount > n) {
    arr[write--] = 0;
    --read;
    --duplicateCount;
  }

  // Write from the end so each source value is read before it is overwritten.
  for (; read >= 0; --read) {
    if (arr[read] == 0) {
      arr[write--] = 0;
      arr[write--] = 0;
    } else {
      arr[write--] = arr[read];
    }
  }
}

}  // namespace

void DuplicateZerosSolution::duplicateZeros(std::vector<int>& arr) {
  return getSolution()(arr);
}

void DuplicateZerosSolution::registerStrategy() {
  SolutionBase<Func>::registerStrategy(
      {.name = "two-pointers",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Two Pointers"}},
      duplicateZerosImpl);
}

}  // namespace problem_1089
}  // namespace leetcode
