#include "leetcode/problems/count-beautiful-substrings-i.h"

#include <string>

namespace leetcode {
namespace problem_2947 {

static int beautifulSubstringsImpl(std::string s, int k) {
  int n = static_cast<int>(s.size());
  int ans = 0;

  auto isVowel = [](char c) -> bool {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  };

  for (int i = 0; i < n; ++i) {
    int vowels = 0;
    int consonants = 0;
    for (int j = i; j < n; ++j) {
      if (isVowel(s[j])) {
        ++vowels;
      } else {
        ++consonants;
      }
      if (vowels == consonants && (vowels * consonants) % k == 0) {
        ++ans;
      }
    }
  }

  return ans;
}

CountBeautifulSubstringsISolution::CountBeautifulSubstringsISolution() {
  setMetaInfo({.id = 2947,
               .title = "Count Beautiful Substrings I",
               .url = "https://leetcode.com/problems/count-beautiful-substrings-i/"});
  registerStrategy({.name = "brute_force",
                    .expected = "Accepted",
                    .time_complexity = "O(n^2)",
                    .space_complexity = "O(1)",
                    .tags = {"String", "Enumeration"}},
                   beautifulSubstringsImpl);
  setDefaultStrategy();
}

int CountBeautifulSubstringsISolution::beautifulSubstrings(std::string s, int k) {
  return getSolution()(s, k);
}

}  // namespace problem_2947
}  // namespace leetcode
