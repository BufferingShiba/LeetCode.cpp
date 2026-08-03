#include "leetcode/problems/online-election.h"

#include <algorithm>
#include <unordered_map>

namespace leetcode {
namespace problem_911 {

TopVotedCandidate::TopVotedCandidate(std::vector<int>& persons,
                                     std::vector<int>& times)
    : times_(times) {
  int n = static_cast<int>(persons.size());
  leaders_.resize(n);

  std::unordered_map<int, int> votes;
  int leader = -1;
  int max_votes = 0;

  for (int i = 0; i < n; ++i) {
    int p = persons[i];
    int v = ++votes[p];
    if (v >= max_votes) {
      leader = p;
      max_votes = v;
    }
    leaders_[i] = leader;
  }
}

int TopVotedCandidate::q(int t) {
  auto it = std::upper_bound(times_.begin(), times_.end(), t);
  int idx = static_cast<int>(std::distance(times_.begin(), it)) - 1;
  return leaders_[idx];
}

}  // namespace problem_911
}  // namespace leetcode
