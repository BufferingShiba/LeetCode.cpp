#ifndef LEETCODE_PROBLEMS_STREAM_OF_CHARACTERS_H__
#define LEETCODE_PROBLEMS_STREAM_OF_CHARACTERS_H__

#include <string>
#include <vector>

namespace leetcode {
namespace problem_1032 {

//! LeetCode 1032: Stream of Characters
//! 每次 query 判断当前字符流中是否有某个后缀等于给定 words 中的任一单词。
class StreamChecker {
 public:
  StreamChecker(const std::vector<std::string>& words);
  ~StreamChecker();

  bool query(char letter);

 private:
  struct TrieNode {
    TrieNode* next[26];
    bool isEnd;
    TrieNode() {
      for (int i = 0; i < 26; ++i) next[i] = nullptr;
      isEnd = false;
    }
  };

  TrieNode* root_;
  std::vector<char> stream_;
  int maxLen_;

  void destroyTrie(TrieNode* node);
};

}  // namespace problem_1032
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_STREAM_OF_CHARACTERS_H__
