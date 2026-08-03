#ifndef LEETCODE_PROBLEMS_IMPLEMENT_MAGIC_DICTIONARY_H__
#define LEETCODE_PROBLEMS_IMPLEMENT_MAGIC_DICTIONARY_H__

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_676 {

// 设计题：MagicDictionary
class ImplementMagicDictionarySolution {
 public:
  ImplementMagicDictionarySolution() = default;

  void buildDict(const std::vector<std::string>& dictionary);
  bool search(const std::string& searchWord);

 private:
  void addVariants(const std::string& word);

  // 变换形式（某个字符替换为 '*') -> 产生该形式的字典词个数
  std::unordered_map<std::string, int> variantCount_;
  // 存储所有字典单词本身，用于区分"恰好一位"与"原词相同"
  std::unordered_set<std::string> words_;
};

// 与测试类名一致的别名（保持命名一致性）
using MagicDictionary = ImplementMagicDictionarySolution;

}  // namespace leetcode::problem_676

#endif  // LEETCODE_PROBLEMS_IMPLEMENT_MAGIC_DICTIONARY_H__
