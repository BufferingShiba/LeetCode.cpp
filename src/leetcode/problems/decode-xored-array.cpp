#include "leetcode/problems/decode-xored-array.h"

#include <vector>

namespace leetcode::problem_1720 {

namespace {

std::vector<int> decodeImpl(std::vector<int>& encoded, int first) {
    std::vector<int> decoded;
    decoded.reserve(encoded.size() + 1);
    decoded.push_back(first);
    for (int e : encoded) {
        decoded.push_back(decoded.back() ^ e);
    }
    return decoded;
}

}  // namespace

DecodeXoredArray::DecodeXoredArray() {
    setMetaInfo({.id = 1720,
                 .title = "Decode XORed Array",
                 .url = "https://leetcode.com/problems/decode-xored-array/"});
    registerStrategy(
        {.name = "linear-xor",
         .expected = "Accepted",
         .time_complexity = "O(n)",
         .space_complexity = "O(n)",
         .tags = {"Array", "Bit Manipulation"}},
        decodeImpl);
}

std::vector<int> DecodeXoredArray::decode(std::vector<int>& encoded, int first) {
    return getSolution()(encoded, first);
}

}  // namespace leetcode::problem_1720
