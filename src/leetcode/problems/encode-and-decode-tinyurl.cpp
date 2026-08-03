#include "leetcode/problems/encode-and-decode-tinyurl.h"

#include <algorithm>

namespace leetcode {
namespace problem_535 {

const std::string Solution::BASE62 =
    "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
const std::string Solution::PREFIX = "http://tinyurl.com/";

Solution::Solution() : nextId_(0) {}

std::string Solution::encode(std::string longUrl) {
  auto it = urlToId_.find(longUrl);
  if (it != urlToId_.end()) {
    return PREFIX + idToShort(it->second);
  }
  int id = nextId_++;
  urlToId_[longUrl] = id;
  idToUrl_[id] = longUrl;
  return PREFIX + idToShort(id);
}

std::string Solution::decode(std::string shortUrl) {
  // Extract short code: everything after the last '/' (or the whole string)
  size_t pos = shortUrl.rfind('/');
  std::string shortCode =
      (pos != std::string::npos) ? shortUrl.substr(pos + 1) : shortUrl;
  int id = shortToId(shortCode);
  return idToUrl_[id];
}

std::string Solution::idToShort(int id) const {
  if (id == 0) {
    return std::string(1, BASE62[0]);
  }
  std::string result;
  while (id > 0) {
    result.push_back(BASE62[id % 62]);
    id /= 62;
  }
  std::reverse(result.begin(), result.end());
  return result;
}

int Solution::shortToId(const std::string& shortCode) const {
  int id = 0;
  for (char c : shortCode) {
    id = id * 62 + static_cast<int>(BASE62.find(c));
  }
  return id;
}

}  // namespace problem_535
}  // namespace leetcode
