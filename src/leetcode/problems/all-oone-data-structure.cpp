#include "leetcode/problems/all-oone-data-structure.h"

namespace leetcode {
namespace problem_432 {

AllOne::AllOne() {}

void AllOne::inc(std::string key) {
    auto it = key_to_node_.find(key);
    if (it == key_to_node_.end()) {
        // Key does not exist, insert into count=1 node
        if (nodes_.empty() || nodes_.front().count != 1) {
            nodes_.push_front(Node(1));
        }
        nodes_.front().keys.insert(key);
        key_to_node_[key] = nodes_.begin();
    } else {
        auto node_it = it->second;
        int count = node_it->count;
        node_it->keys.erase(key);

        auto next_it = std::next(node_it);
        if (next_it == nodes_.end() || next_it->count != count + 1) {
            next_it = nodes_.insert(next_it, Node(count + 1));
        }
        next_it->keys.insert(key);
        key_to_node_[key] = next_it;

        if (node_it->keys.empty()) {
            nodes_.erase(node_it);
        }
    }
}

void AllOne::dec(std::string key) {
    auto it = key_to_node_.find(key);
    // Problem guarantees key exists before dec
    auto node_it = it->second;
    int count = node_it->count;
    node_it->keys.erase(key);

    if (count > 1) {
        std::list<Node>::iterator prev_it;
        if (node_it == nodes_.begin() || std::prev(node_it)->count != count - 1) {
            prev_it = nodes_.insert(node_it, Node(count - 1));
        } else {
            prev_it = std::prev(node_it);
        }
        prev_it->keys.insert(key);
        key_to_node_[key] = prev_it;
    } else {
        key_to_node_.erase(it);
    }

    if (node_it->keys.empty()) {
        nodes_.erase(node_it);
    }
}

std::string AllOne::getMaxKey() {
    if (nodes_.empty()) return "";
    return *nodes_.back().keys.begin();
}

std::string AllOne::getMinKey() {
    if (nodes_.empty()) return "";
    return *nodes_.front().keys.begin();
}

} // namespace problem_432
} // namespace leetcode
