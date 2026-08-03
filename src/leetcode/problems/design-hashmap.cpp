#include "leetcode/problems/design-hashmap.h"

namespace problem_706 {

namespace {
constexpr int kMaxKey = 1000000;
}

DesignHashmap::DesignHashmap() : table_(kMaxKey + 1, -1) {}

void DesignHashmap::put(int key, int value) { table_[key] = value; }

int DesignHashmap::get(int key) { return table_[key]; }

void DesignHashmap::remove(int key) { table_[key] = -1; }

}  // namespace problem_706
