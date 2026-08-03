#include "leetcode/problems/string-compression-iii.h"

namespace leetcode {
namespace problem_3163 {

namespace {

std::string compressedStringImpl(std::string word) {
    std::string comp;
    comp.reserve(word.size());
    const int n = static_cast<int>(word.size());
    int i = 0;
    while (i < n) {
        char c = word[i];
        int cnt = 0;
        while (i < n && word[i] == c && cnt < 9) {
            ++cnt;
            ++i;
        }
        comp.push_back(static_cast<char>('0' + cnt));
        comp.push_back(c);
    }
    return comp;
}

}  // namespace

std::string StringCompressionIiiSolution::compressedString(std::string word) {
    return getSolution()(word);
}

StringCompressionIiiSolution::StringCompressionIiiSolution() {
    setMetaInfo({.id = 3163,
                 .title = "String Compression III",
                 .url = "https://leetcode.com/problems/string-compression-iii/"});
    registerStrategy({.name = "single-pass",
                      .expected = "Accepted",
                      .time_complexity = "O(n)",
                      .space_complexity = "O(1)",
                      .tags = {"String"}},
                     compressedStringImpl);
}

}  // namespace problem_3163
}  // namespace leetcode
