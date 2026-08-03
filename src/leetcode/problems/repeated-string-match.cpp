#include "leetcode/problems/repeated-string-match.h"

namespace leetcode {
namespace problem_686 {

static int solution1(string a, string b) {
  // Repeat a until its length is at least that of b, then check a couple of times.
  int repeat = (b.size() + a.size() - 1) / a.size();  // ceil(b.len / a.len)
  string rep;
  rep.reserve(repeat * a.size());
  for (int i = 0; i < repeat; ++i) rep += a;
  // b could start near the end of this repeated string, so check one more copy.
  if (rep.find(b) != string::npos) return repeat;
  rep += a;
  if (rep.find(b) != string::npos) return repeat + 1;
  return -1;
}

RepeatedStringMatchSolution::RepeatedStringMatchSolution() {
  setMetaInfo({
      .id = 686,
      .title = "Repeated String Match",
      .url = "https://leetcode.com/problems/repeated-string-match"
  });
  registerStrategy({.name = "Brute Force"}, solution1);
}

int RepeatedStringMatchSolution::repeatedStringMatch(string a, string b) {
  return getSolution()(a, b);
}

}  // namespace problem_686
}  // namespace leetcode
