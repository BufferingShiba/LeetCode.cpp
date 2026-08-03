#include "leetcode/problems/count-number-of-teams.h"

namespace leetcode {
namespace problem_1395 {

namespace {

int numTeamsImpl(std::vector<int>& rating) {
  const int n = static_cast<int>(rating.size());
  int count = 0;
  for (int j = 1; j < n - 1; ++j) {
    int lessLeft = 0;
    int greaterLeft = 0;
    for (int i = 0; i < j; ++i) {
      if (rating[i] < rating[j]) {
        ++lessLeft;
      } else {
        ++greaterLeft;
      }
    }
    int lessRight = 0;
    int greaterRight = 0;
    for (int k = j + 1; k < n; ++k) {
      if (rating[k] < rating[j]) {
        ++lessRight;
      } else {
        ++greaterRight;
      }
    }
    count += lessLeft * greaterRight;
    count += greaterLeft * lessRight;
  }
  return count;
}

}  // namespace

CountNumberOfTeamsSolution::CountNumberOfTeamsSolution() {
  setMetaInfo({1395, "Count Number of Teams",
               "https://leetcode.com/problems/count-number-of-teams/"});
  registerStrategy(
      {"EnumerateMiddle", "Accepted", "O(n^2)", "O(1)",
       {"Array", "Dynamic Programming"}}, numTeamsImpl);
}

int CountNumberOfTeamsSolution::numTeams(std::vector<int>& rating) {
  return getSolution()(rating);
}

}  // namespace problem_1395
}  // namespace leetcode
