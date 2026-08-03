#include <gtest/gtest.h>
#include "leetcode/problems/all-oone-data-structure.h"

using namespace leetcode::problem_432;

class AllOoneDataStructureTest : public ::testing::TestWithParam<int> {
protected:
    AllOne allOne;
};

TEST_P(AllOoneDataStructureTest, Example1) {
    allOne.inc("hello");
    allOne.inc("hello");
    EXPECT_EQ(allOne.getMaxKey(), "hello");
    EXPECT_EQ(allOne.getMinKey(), "hello");
    allOne.inc("leet");
    EXPECT_EQ(allOne.getMaxKey(), "hello");
    EXPECT_EQ(allOne.getMinKey(), "leet");
}

TEST_P(AllOoneDataStructureTest, SelfAuthoredDecToRemove) {
    AllOne obj;
    obj.inc("a");
    obj.inc("a");
    obj.inc("b");
    // a:2, b:1
    EXPECT_EQ(obj.getMaxKey(), "a");
    EXPECT_EQ(obj.getMinKey(), "b");
    obj.dec("a");
    // a:1, b:1
    EXPECT_EQ(obj.getMaxKey(), "a"); // any of a or b
    // min should also be 1
    obj.dec("b");
    // b removed, a:1
    EXPECT_EQ(obj.getMaxKey(), "a");
    EXPECT_EQ(obj.getMinKey(), "a");
    obj.dec("a");
    // a removed
    EXPECT_EQ(obj.getMaxKey(), "");
    EXPECT_EQ(obj.getMinKey(), "");
}

TEST_P(AllOoneDataStructureTest, SelfAuthoredMultipleKeysSameCount) {
    AllOne obj;
    obj.inc("a");
    obj.inc("b");
    obj.inc("c");
    // all count 1
    std::string max_key = obj.getMaxKey();
    std::string min_key = obj.getMinKey();
    EXPECT_TRUE(max_key == "a" || max_key == "b" || max_key == "c");
    EXPECT_TRUE(min_key == "a" || min_key == "b" || min_key == "c");
    EXPECT_EQ(max_key, min_key); // same count, any is fine

    obj.inc("a");
    // a:2, b:1, c:1
    EXPECT_EQ(obj.getMaxKey(), "a");
    std::string min2 = obj.getMinKey();
    EXPECT_TRUE(min2 == "b" || min2 == "c");
}

TEST_P(AllOoneDataStructureTest, SelfAuthoredEmptyOperations) {
    AllOne obj;
    EXPECT_EQ(obj.getMaxKey(), "");
    EXPECT_EQ(obj.getMinKey(), "");
}

INSTANTIATE_TEST_SUITE_P(AllOne, AllOoneDataStructureTest, ::testing::Values(0));
