#include "leetcode/problems/grumpy-bookstore-owner.h"

namespace leetcode {
namespace problem_1052 {

static int maxSatisfiedImpl(vector<int>& customers, vector<int>& grumpy, int minutes) {
  int n = static_cast<int>(customers.size());
  // Base satisfied customers (minutes when owner is not grumpy).
  int base = 0;
  for (int i = 0; i < n; ++i) {
    if (grumpy[i] == 0) base += customers[i];
  }

  // Additional customers gained by applying the technique to a window.
  // For grumpy[i]==1, applying technique gains customers[i]; otherwise 0.
  int extra = 0;
  for (int i = 0; i < minutes; ++i) {
    if (grumpy[i] == 1) extra += customers[i];
  }
  int maxExtra = extra;
  for (int i = minutes; i < n; ++i) {
    if (grumpy[i] == 1) extra += customers[i];
    if (grumpy[i - minutes] == 1) extra -= customers[i - minutes];
    if (extra > maxExtra) maxExtra = extra;
  }
  return base + maxExtra;
}

GrumpyBookstoreOwnerSolution::GrumpyBookstoreOwnerSolution() {
  setMetaInfo({
      .id = 1052,
      .title = "Grumpy Bookstore Owner",
      .url = "https://leetcode.com/problems/grumpy-bookstore-owner"
  });
  registerStrategy({.name = "Sliding Window", .time_complexity = "O(n)", .space_complexity = "O(1)", .tags = {"Array", "Sliding Window"}}, maxSatisfiedImpl);
}

int GrumpyBookstoreOwnerSolution::maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
  return getSolution()(customers, grumpy, minutes);
}

}  // namespace problem_1052
}  // namespace leetcode
