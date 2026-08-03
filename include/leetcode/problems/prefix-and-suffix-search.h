#ifndef LEETCODE_PROBLEMS_PREFIX_AND_SUFFIX_SEARCH_H
#define LEETCODE_PROBLEMS_PREFIX_AND_SUFFIX_SEARCH_H

#include <string>
#include <unordered_map>
#include <vector>

namespace leetcode {
namespace problem_745 {

class WordFilter {
 public:
  explicit WordFilter(std::vector<std::string>& words);

  int f(std::string pref, std::string suff);

 private:
  std::unordered_map<std::string, int> cache_;
};

}  // namespace problem_745
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_PREFIX_AND_SUFFIX_SEARCH_H
