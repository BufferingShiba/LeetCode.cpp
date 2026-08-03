#include "leetcode/problems/prefix-and-suffix-search.h"

namespace leetcode {
namespace problem_745 {

WordFilter::WordFilter(std::vector<std::string>& words) {
  for (int i = 0; i < static_cast<int>(words.size()); ++i) {
    const std::string& word = words[i];
    int len = static_cast<int>(word.length());
    // Enumerate every possible prefix and suffix pair
    for (int p = 1; p <= len; ++p) {
      std::string pref = word.substr(0, p);
      for (int s = 1; s <= len; ++s) {
        std::string suff = word.substr(len - s);
        std::string key = pref + "|" + suff;
        cache_[key] = i;  // later index overwrites earlier → keeps max
      }
    }
  }
}

int WordFilter::f(std::string pref, std::string suff) {
  std::string key = pref + "|" + suff;
  auto it = cache_.find(key);
  if (it != cache_.end()) {
    return it->second;
  }
  return -1;
}

}  // namespace problem_745
}  // namespace leetcode
