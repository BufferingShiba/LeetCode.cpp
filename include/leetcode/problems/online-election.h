#ifndef LEETCODE_PROBLEMS_ONLINE_ELECTION_H_
#define LEETCODE_PROBLEMS_ONLINE_ELECTION_H_

#include <vector>

namespace leetcode {
namespace problem_911 {

class TopVotedCandidate {
 public:
  TopVotedCandidate(std::vector<int>& persons, std::vector<int>& times);

  int q(int t);

 private:
  std::vector<int> leaders_;
  std::vector<int> times_;
};

}  // namespace problem_911
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_ONLINE_ELECTION_H_
