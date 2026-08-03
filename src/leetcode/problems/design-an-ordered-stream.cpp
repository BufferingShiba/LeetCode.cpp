#include "leetcode/problems/design-an-ordered-stream.h"

namespace leetcode {
namespace problem_1656 {

OrderedStream::OrderedStream(int n) : stream_(n + 1), ptr_(1) {}

std::vector<std::string> OrderedStream::insert(int idKey, std::string value) {
  stream_[idKey] = std::move(value);
  std::vector<std::string> chunk;
  while (ptr_ < static_cast<int>(stream_.size()) && !stream_[ptr_].empty()) {
    chunk.push_back(stream_[ptr_]);
    ++ptr_;
  }
  return chunk;
}

}  // namespace problem_1656
}  // namespace leetcode
