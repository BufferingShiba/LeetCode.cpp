#include "leetcode/problems/replace-words.h"

#include <memory>
#include <sstream>
#include <string>
#include <vector>

namespace leetcode::problem_648 {

namespace {

// Trie node with 26 children (lowercase letters only)
struct TrieNode {
  std::unique_ptr<TrieNode> children[26];
  bool isEnd = false;
};

class Trie {
 public:
  void insert(const std::string& word) {
    TrieNode* node = &root_;
    for (char ch : word) {
      int idx = ch - 'a';
      if (!node->children[idx]) {
        node->children[idx] = std::make_unique<TrieNode>();
      }
      node = node->children[idx].get();
    }
    node->isEnd = true;
  }

  // Returns the shortest root prefix of `word` if any, otherwise returns `word`.
  std::string findRoot(const std::string& word) const {
    const TrieNode* node = &root_;
    for (size_t i = 0; i < word.size(); ++i) {
      int idx = word[i] - 'a';
      if (!node->children[idx]) {
        break;  // no further match, return original word
      }
      node = node->children[idx].get();
      if (node->isEnd) {
        return word.substr(0, i + 1);  // shortest root found
      }
    }
    return word;  // no root matched
  }

 private:
  TrieNode root_;
};

std::string replaceWordsImpl(std::vector<std::string>& dictionary,
                             std::string sentence) {
  // Build Trie from dictionary
  Trie trie;
  for (const auto& root : dictionary) {
    trie.insert(root);
  }

  // Process sentence word by word
  std::istringstream iss(sentence);
  std::ostringstream oss;
  std::string word;
  bool first = true;

  while (iss >> word) {
    if (!first) {
      oss << ' ';
    }
    oss << trie.findRoot(word);
    first = false;
  }

  return oss.str();
}

}  // namespace

ReplaceWordsSolution::ReplaceWordsSolution() {
  setMetaInfo({.id = 648,
               .title = "Replace Words",
               .url = "https://leetcode.com/problems/replace-words/"});
  registerStrategy({.name = "Trie",
                    .expected = "Accepted",
                    .time_complexity = "O(D*L + S)",
                    .space_complexity = "O(D*L)",
                    .tags = {"Trie", "Hash Table", "String"}},
                   replaceWordsImpl);
}

std::string ReplaceWordsSolution::replaceWords(std::vector<std::string>& dictionary,
                                               std::string sentence) {
  return getSolution()(dictionary, sentence);
}

}  // namespace leetcode::problem_648
