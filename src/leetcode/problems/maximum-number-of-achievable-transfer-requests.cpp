#include "leetcode/problems/maximum-number-of-achievable-transfer-requests.h"

namespace leetcode {
namespace problem_1601 {

namespace {

int maximumRequestsImpl(int n, std::vector<std::vector<int>>& requests) {
  const int m = static_cast<int>(requests.size());
  int best = 0;
  for (int mask = 0; mask < (1 << m); ++mask) {
    std::vector<int> balance(n, 0);
    int cnt = 0;
    for (int i = 0; i < m; ++i) {
      if (mask & (1 << i)) {
        --balance[requests[i][0]];
        ++balance[requests[i][1]];
        ++cnt;
      }
    }
    bool ok = true;
    for (int b : balance) {
      if (b != 0) {
        ok = false;
        break;
      }
    }
    if (ok && cnt > best) best = cnt;
  }
  return best;
}

}  // namespace

MaximumNumberOfAchievableTransferRequestsSolution::MaximumNumberOfAchievableTransferRequestsSolution() {
  setMetaInfo({1601, "Maximum Number of Achievable Transfer Requests",
               "https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/"});
  registerStrategy(
      {"Bitmask Enumeration", "Accepted", "O(m * n * 2^m)", "O(n)",
       {"Array", "Backtracking", "Bit Manipulation", "Enumeration"},
       "Enumerate all request subsets and check net balance is zero per building."},
      maximumRequestsImpl);
}

int MaximumNumberOfAchievableTransferRequestsSolution::maximumRequests(
    int n, std::vector<std::vector<int>>& requests) {
  return getSolution()(n, requests);
}

}  // namespace problem_1601
}  // namespace leetcode
