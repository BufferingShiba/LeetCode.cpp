#include "leetcode/problems/first-day-where-you-have-been-in-all-the-rooms.h"

#include <vector>

namespace leetcode {
namespace problem_1997 {

static int firstDayBeenInAllRoomsImpl(std::vector<int>& nextVisit) {
  const int MOD = 1000000007;
  const int n = static_cast<int>(nextVisit.size());
  std::vector<int> dp(n);
  dp[0] = 0;
  for (int i = 0; i < n - 1; ++i) {
    long long val = 2LL * dp[i] - dp[nextVisit[i]] + 2;
    val %= MOD;
    if (val < 0) val += MOD;
    dp[i + 1] = static_cast<int>(val);
  }
  return dp[n - 1];
}

FirstDayWhereYouHaveBeenInAllTheRoomsSolution::FirstDayWhereYouHaveBeenInAllTheRoomsSolution() {
  setMetaInfo({.id = 1997,
               .title = "First Day Where You Have Been in All the Rooms",
               .url = "https://leetcode.com/problems/first-day-where-you-have-been-in-all-the-rooms/"});
  registerStrategy({.name = "DP",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"Array", "Dynamic Programming"}},
                   firstDayBeenInAllRoomsImpl);
  setDefaultStrategy();
}

int FirstDayWhereYouHaveBeenInAllTheRoomsSolution::firstDayBeenInAllRooms(
    std::vector<int>& nextVisit) {
  return getSolution()(nextVisit);
}

}  // namespace problem_1997
}  // namespace leetcode
