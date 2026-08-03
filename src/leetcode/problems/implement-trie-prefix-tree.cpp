#include "leetcode/problems/implement-trie-prefix-tree.h"

namespace leetcode {
namespace problem_208 {
namespace {

int charIndex(char ch) {
  const int index = ch - 'a';
  return index >= 0 && index < 26 ? index : -1;
}

}  // namespace

void Trie::insert(const std::string& word) {
  Node* node = root_.get();
  for (char ch : word) {
    const int idx = charIndex(ch);
    if (idx < 0) {
      return;
    }
    if (!node->next[idx]) {
      node->next[idx] = std::make_unique<Node>();
    }
    node = node->next[idx].get();
  }
  node->isEnd = true;
}

bool Trie::search(const std::string& word) const {
  Node* node = root_.get();
  for (char ch : word) {
    const int idx = charIndex(ch);
    if (idx < 0) {
      return false;
    }
    if (!node->next[idx]) {
      return false;
    }
    node = node->next[idx].get();
  }
  return node->isEnd;
}

bool Trie::startsWith(const std::string& prefix) const {
  Node* node = root_.get();
  for (char ch : prefix) {
    const int idx = charIndex(ch);
    if (idx < 0) {
      return false;
    }
    if (!node->next[idx]) {
      return false;
    }
    node = node->next[idx].get();
  }
  return true;
}

}  // namespace problem_208
}  // namespace leetcode
