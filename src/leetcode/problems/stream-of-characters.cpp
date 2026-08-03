#include "leetcode/problems/stream-of-characters.h"

#include <algorithm>

namespace leetcode {
namespace problem_1032 {

StreamChecker::StreamChecker(const std::vector<std::string>& words) {
  root_ = new TrieNode();
  maxLen_ = 0;
  for (const auto& w : words) {
    maxLen_ = std::max(maxLen_, static_cast<int>(w.size()));
    TrieNode* node = root_;
    // 将单词反转插入 Trie：后缀匹配 => 从尾部向前匹配
    for (int i = static_cast<int>(w.size()) - 1; i >= 0; --i) {
      int c = w[i] - 'a';
      if (!node->next[c]) node->next[c] = new TrieNode();
      node = node->next[c];
    }
    node->isEnd = true;
  }
}

StreamChecker::~StreamChecker() { destroyTrie(root_); }

void StreamChecker::destroyTrie(TrieNode* node) {
  if (!node) return;
  for (int i = 0; i < 26; ++i) {
    destroyTrie(node->next[i]);
  }
  delete node;
}

bool StreamChecker::query(char letter) {
  stream_.push_back(letter);
  // 只保留最近 maxLen_ 个字符，避免缓冲无限增长
  while (static_cast<int>(stream_.size()) > maxLen_) {
    stream_.erase(stream_.begin());
  }
  // 从尾向前在反转 Trie 中逐字符匹配，检查是否存在某个后缀是单词
  TrieNode* node = root_;
  for (int i = static_cast<int>(stream_.size()) - 1; i >= 0; --i) {
    int c = stream_[i] - 'a';
    if (!node->next[c]) return false;
    node = node->next[c];
    if (node->isEnd) return true;
  }
  return false;
}

}  // namespace problem_1032
}  // namespace leetcode
