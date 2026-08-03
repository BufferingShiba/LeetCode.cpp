#include "leetcode/problems/kth-smallest-path-xor-sum.h"

#include <utility>
#include <vector>

// LeetCode's online compiler does not consistently expose GNU PBDS after the
// project-to-Solution translation.  Keep the order-statistics tree self
// contained so the submitted code only depends on standard C++ facilities.
class OrderedTree {
private:
    struct Node {
        int key;
        unsigned priority;
        int size;
        Node* left;
        Node* right;

        Node(int value, unsigned rank)
            : key(value), priority(rank), size(1), left(nullptr), right(nullptr) {}
    };

    Node* root_ = nullptr;
    unsigned seed_ = 0x9e3779b9u;

    static int nodeSize(Node* node) { return node ? node->size : 0; }

    static void pull(Node* node) {
        if (node) node->size = 1 + nodeSize(node->left) + nodeSize(node->right);
    }

    static bool contains(Node* node, int key) {
        while (node) {
            if (node->key == key) return true;
            node = key < node->key ? node->left : node->right;
        }
        return false;
    }

    // Split into keys < key and keys >= key.
    static void split(Node* node, int key, Node*& left, Node*& right) {
        if (!node) {
            left = nullptr;
            right = nullptr;
            return;
        }
        if (node->key < key) {
            left = node;
            split(node->right, key, left->right, right);
            pull(left);
        } else {
            right = node;
            split(node->left, key, left, right->left);
            pull(right);
        }
    }

    static Node* insertNode(Node* root, Node* item) {
        if (!root) return item;
        if (item->priority > root->priority) {
            split(root, item->key, item->left, item->right);
            pull(item);
            return item;
        }
        if (item->key < root->key) {
            root->left = insertNode(root->left, item);
        } else {
            root->right = insertNode(root->right, item);
        }
        pull(root);
        return root;
    }

    static int kth(Node* node, int index) {
        int leftSize = nodeSize(node->left);
        if (index < leftSize) return kth(node->left, index);
        if (index == leftSize) return node->key;
        return kth(node->right, index - leftSize - 1);
    }

    static void destroy(Node* node) {
        if (!node) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

    unsigned nextPriority() {
        // A tiny deterministic xorshift generator is enough for treap
        // balancing and avoids relying on non-standard random facilities.
        seed_ ^= seed_ << 13;
        seed_ ^= seed_ >> 17;
        seed_ ^= seed_ << 5;
        return seed_;
    }

    void insertAll(Node* node) {
        if (!node) return;
        insert(node->key);
        insertAll(node->left);
        insertAll(node->right);
    }

public:
    ~OrderedTree() { destroy(root_); }

    OrderedTree() = default;
    OrderedTree(const OrderedTree&) = delete;
    OrderedTree& operator=(const OrderedTree&) = delete;

    int size() const { return nodeSize(root_); }

    void insert(int key) {
        if (contains(root_, key)) return;
        root_ = insertNode(root_, new Node(key, nextPriority()));
    }

    void insertAll(const OrderedTree& other) {
        insertAll(other.root_);
    }

    int find_by_order(int index) const { return kth(root_, index); }
};

namespace leetcode::problem_3590 {

static std::vector<int> kthSmallestImpl(std::vector<int>& par, std::vector<int>& vals,
                                        std::vector<std::vector<int>>& queries) {
    int n = static_cast<int>(vals.size());
    std::vector<std::vector<int>> children(n);
    for (int i = 1; i < n; ++i) {
        children[par[i]].push_back(i);
    }

    // Compute path XORs via BFS (avoids deep recursion on chain trees).
    std::vector<int> px(n, 0);
    std::vector<int> order;
    order.reserve(n);
    std::vector<int> queueVec;
    queueVec.reserve(n);
    queueVec.push_back(0);
    px[0] = vals[0];
    for (size_t qi = 0; qi < queueVec.size(); ++qi) {
        int u = queueVec[qi];
        order.push_back(u);
        for (int c : children[u]) {
            px[c] = px[u] ^ vals[c];
            queueVec.push_back(c);
        }
    }

    // Group queries by subtree root u -> (k, queryIndex).
    std::vector<std::vector<std::pair<int, int>>> qgroup(n);
    int Q = static_cast<int>(queries.size());
    std::vector<int> ans(Q, -1);
    for (int j = 0; j < Q; ++j) {
        int u = queries[j][0];
        int k = queries[j][1];
        qgroup[u].push_back(std::make_pair(k, j));
    }

    // Merge subtrees bottom-up (reverse BFS order = children before parents).
    std::vector<OrderedTree*> setPtr(n, nullptr);
    for (int oi = static_cast<int>(order.size()) - 1; oi >= 0; --oi) {
        int u = order[oi];
        OrderedTree* cur = nullptr;
        for (int c : children[u]) {
            if (!cur || setPtr[c]->size() > cur->size()) {
                cur = setPtr[c];
            }
        }
        if (!cur) cur = new OrderedTree();
        for (int c : children[u]) {
            if (setPtr[c] == cur) continue;
            cur->insertAll(*setPtr[c]);
            delete setPtr[c];
        }
        cur->insert(px[u]);
        setPtr[u] = cur;
        for (int c : children[u]) setPtr[c] = nullptr;

        for (const auto& q : qgroup[u]) {
            int k = q.first;
            int j = q.second;
            if (static_cast<long long>(k - 1) < static_cast<long long>(cur->size())) {
                ans[j] = cur->find_by_order(k - 1);
            } else {
                ans[j] = -1;
            }
        }
    }
    return ans;
}

KthSmallestPathXorSumSolution::KthSmallestPathXorSumSolution() {
    setMetaInfo({.id = 3590,
                 .title = "Kth Smallest Path XOR Sum",
                 .url = "https://leetcode.com/problems/kth-smallest-path-xor-sum/"});
    registerStrategy(
        {.name = "small_to_large_dsu_ordered_set",
         .expected = "Accepted",
         .time_complexity = "O(n log^2 n + q log n)",
         .space_complexity = "O(n log n)",
         .tags = {"Array", "Tree", "Depth-First Search", "Ordered Set"}},
        kthSmallestImpl);
}

std::vector<int> KthSmallestPathXorSumSolution::kthSmallest(
    std::vector<int>& par, std::vector<int>& vals, std::vector<std::vector<int>>& queries) {
    return getSolution()(par, vals, queries);
}

}  // namespace leetcode::problem_3590
