#ifndef LEETCODE_PROBLEMS_ENCODE_AND_DECODE_TINYURL_H_
#define LEETCODE_PROBLEMS_ENCODE_AND_DECODE_TINYURL_H_

#include <string>
#include <unordered_map>

namespace leetcode {
namespace problem_535 {

class Solution {
 public:
  Solution();

  std::string encode(std::string longUrl);
  std::string decode(std::string shortUrl);

 private:
  static const std::string BASE62;
  static const std::string PREFIX;

  std::string idToShort(int id) const;
  int shortToId(const std::string& shortCode) const;

  std::unordered_map<int, std::string> idToUrl_;
  std::unordered_map<std::string, int> urlToId_;
  int nextId_;
};

}  // namespace problem_535
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_ENCODE_AND_DECODE_TINYURL_H_
