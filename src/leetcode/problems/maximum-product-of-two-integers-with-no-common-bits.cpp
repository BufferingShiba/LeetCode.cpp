#include "leetcode/problems/maximum-product-of-two-integers-with-no-common-bits.h"

#include <algorithm>
#include <array>

namespace leetcode {
namespace problem_3670 {
namespace {

class MaskTrie {
 public:
  static constexpr int kBits = 20;
  static constexpr int kDomainMask = (1 << (kBits + 1)) - 1;

  MaskTrie() { nodes_.push_back(Node{}); }

  void insert(int value) {
    int node = 0;
    for (int bit = kBits; bit >= 0; --bit) {
      const int branch = (value >> bit) & 1;
      if (nodes_[node].child[branch] == -1) {
        nodes_[node].child[branch] = static_cast<int>(nodes_.size());
        nodes_.push_back(Node{});
      }
      node = nodes_[node].child[branch];
    }
    nodes_[node].maxValue = value;
    nodes_[node].orMask = value;
    nodes_[node].andMask = value;
  }

  void finalize() {
    for (int node = static_cast<int>(nodes_.size()) - 1; node >= 0; --node) {
      const int left = nodes_[node].child[0];
      const int right = nodes_[node].child[1];
      if (left == -1 && right == -1) continue;
      if (left == -1) {
        copyStats(node, right);
      } else if (right == -1) {
        copyStats(node, left);
      } else {
        nodes_[node].maxValue =
            std::max(nodes_[left].maxValue, nodes_[right].maxValue);
        nodes_[node].orMask = nodes_[left].orMask | nodes_[right].orMask;
        nodes_[node].andMask = nodes_[left].andMask & nodes_[right].andMask;
      }
    }
  }

  int maximumDisjointValue(int value) const {
    return query(0, kBits, value);
  }

 private:
  struct Node {
    std::array<int, 2> child = {-1, -1};
    int maxValue = 0;
    int orMask = 0;
    int andMask = kDomainMask;
  };

  void copyStats(int target, int source) {
    nodes_[target].maxValue = nodes_[source].maxValue;
    nodes_[target].orMask = nodes_[source].orMask;
    nodes_[target].andMask = nodes_[source].andMask;
  }

  int query(int node, int bit, int value) const {
    if (node == -1) return -1;
    if (bit < 0) return nodes_[node].maxValue;

    const int relevantMask = value & ((1 << (bit + 1)) - 1);
    if ((nodes_[node].orMask & relevantMask) == 0) {
      return nodes_[node].maxValue;
    }
    if ((nodes_[node].andMask & relevantMask) != 0) {
      return -1;
    }

    if ((value >> bit) & 1) {
      return query(nodes_[node].child[0], bit - 1, value);
    }

    const int preferred = query(nodes_[node].child[1], bit - 1, value);
    if (preferred != -1) return preferred;
    return query(nodes_[node].child[0], bit - 1, value);
  }

  std::vector<Node> nodes_;
};

long long trieWithPruning(std::vector<int>& nums) {
  MaskTrie trie;
  for (int value : nums) trie.insert(value);
  trie.finalize();

  long long answer = 0;
  for (int value : nums) {
    const int partner = trie.maximumDisjointValue(value);
    if (partner != -1) {
      answer = std::max(answer, static_cast<long long>(value) * partner);
    }
  }
  return answer;
}

}  // namespace

MaximumProductOfTwoIntegersWithNoCommonBitsSolution::
    MaximumProductOfTwoIntegersWithNoCommonBitsSolution() {
  setMetaInfo({.id = 3670,
               .title = "Maximum Product of Two Integers With No Common Bits",
               .url = "https://leetcode.com/problems/maximum-product-of-two-integers-with-no-common-bits/"});
  registerStrategy({.name = "pruned_binary_trie",
                    .expected = "Accepted",
                    .time_complexity = "O(21n) average",
                    .space_complexity = "O(21n)",
                    .tags = {"Bit Manipulation", "Trie"}},
                   trieWithPruning);
}

long long MaximumProductOfTwoIntegersWithNoCommonBitsSolution::maxProduct(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3670
}  // namespace leetcode
