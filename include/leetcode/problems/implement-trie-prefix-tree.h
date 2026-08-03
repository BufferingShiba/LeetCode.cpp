#ifndef LEETCODE_PROBLEMS_IMPLEMENT_TRIE_PREFIX_TREE_H__
#define LEETCODE_PROBLEMS_IMPLEMENT_TRIE_PREFIX_TREE_H__

#include <memory>
#include <string>

namespace leetcode {
namespace problem_208 {

// Implementation of the Trie (prefix tree) class.
// Only lowercase English letters are stored.
class Trie {
 private:
  struct Node {
    std::unique_ptr<Node> next[26];
    bool isEnd = false;
  };

  std::unique_ptr<Node> root_;

 public:
  Trie() : root_(std::make_unique<Node>()) {}

  void insert(const std::string& word);
  bool search(const std::string& word) const;
  bool startsWith(const std::string& prefix) const;
};

}  // namespace problem_208
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_IMPLEMENT_TRIE_PREFIX_TREE_H__
