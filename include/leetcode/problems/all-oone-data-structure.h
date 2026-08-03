#ifndef LEETCODE_PROBLEMS_ALL_OONE_DATA_STRUCTURE_H
#define LEETCODE_PROBLEMS_ALL_OONE_DATA_STRUCTURE_H

#include <string>
#include <list>
#include <unordered_set>
#include <unordered_map>

namespace leetcode {
namespace problem_432 {

class AllOne {
public:
    AllOne();
    void inc(std::string key);
    void dec(std::string key);
    std::string getMaxKey();
    std::string getMinKey();

private:
    struct Node {
        int count;
        std::unordered_set<std::string> keys;
        explicit Node(int c) : count(c) {}
    };

    std::list<Node> nodes_;
    std::unordered_map<std::string, std::list<Node>::iterator> key_to_node_;
};

} // namespace problem_432
} // namespace leetcode

#endif
