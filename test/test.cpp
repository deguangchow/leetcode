///    Copyright (C) 2018 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    LeetCode No.001 unit test.
///
///    \author   deguangchow
///    \version  1.0
///    \2019/01/08

#include "stdafx.h"
#include <gtest/gtest.h>
#include "Solution.h"


//单链表转字符串
std::string list2str(ListNode* l) {
    std::string s;
    while (l) {
        s += std::to_string(l->val);
        l = l->next;
        if (l) {
            s += ',';
        }
    }
    return s;
}

//字符串转单链表
ListNode* str2list(const std::string& s) {
    ListNode* ret = new ListNode(-1);
    ListNode* p = ret;
    unsigned len = s.length();
    unsigned count = 0;
    unsigned begin = 0;
    unsigned i = 0;
    while (s[i] != '\0') {
        if (s[i] == ',') {
            p->next = new ListNode(atoi(s.substr(begin, count).c_str()));
            p = p->next;
            begin = i + 1;
            count = 0;
        }
        ++count;
        ++i;
    }
    if (count != 0) {
        p->next = new ListNode(atoi(s.substr(begin, count).c_str()));
    }
    return ret->next;
}

//二叉树转字符串
std::string tree2str(TreeNode* t) {
    std::string s;
    while (t) {
        s += std::to_string(t->val);
        t = t->left;
        if (t) {
            s += ',';
        }
    }
    return s;
}

//字符串转二叉树
TreeNode* str2tree(const std::string& s) {

    TreeNode* ret = nullptr;
    unsigned count_level = 1, count = 1;
    bool end = false;
    queue<int> nodes;

    while (!nodes.empty()) {
        count = (unsigned)pow(2, count_level);
        for (unsigned i = 0; i < count; ++i) {
            if (s[i] == '\0') {
                end = true;
                break;
            }
        }
        if (end) {
            break;
        }
    }

    return ret;
}

//2个单链表的节点内容比较
#define  EXPECT_LIST_VAL_EQ(l1, l2) {\
    while (l1 && l2) {\
        EXPECT_EQ(l1->val, l2->val);\
        l1 = l1->next;\
        l2 = l2->next;\
    }\
    EXPECT_TRUE(nullptr == l1);\
    EXPECT_TRUE(nullptr == l2);\
}


TEST(ListNodeString, str2list) {
    {
        ListNode*l = nullptr;
        ListNode*ret = str2list("");
        EXPECT_LIST_VAL_EQ(l, ret);
    }
    {
        ListNode*l = new ListNode(0);
        ListNode*ret = str2list("0");
        EXPECT_LIST_VAL_EQ(l, ret);
    }
    {
        ListNode*l = new ListNode(-1);
        ListNode*ret = str2list("-1");
        EXPECT_LIST_VAL_EQ(l, ret);
    }
    {
        ListNode*l = new ListNode(1);
        ListNode*ret = str2list("1");
        EXPECT_LIST_VAL_EQ(l, ret);
    }
    {
        ListNode*l = new ListNode(1);
        l->next = new ListNode(2);
        ListNode*ret = str2list("1,2");
        EXPECT_LIST_VAL_EQ(l, ret);
    }
    {
        ListNode*l = new ListNode(1);
        l->next = new ListNode(2);
        l->next->next = new ListNode(3);
        ListNode*ret = str2list("1,2,3");
        EXPECT_LIST_VAL_EQ(l, ret);
    }
    {
        ListNode*l = new ListNode(1);
        l->next = new ListNode(2);
        l->next->next = new ListNode(3);
        l->next->next->next = new ListNode(4);
        ListNode*ret = str2list("1,2,3,4");
        EXPECT_LIST_VAL_EQ(l, ret);
    }
}

TEST(ListNodeString, list2str) {
    {
        ListNode*l = nullptr;
        EXPECT_EQ("", list2str(l));
    }
    {
        ListNode*l = new ListNode(0);
        EXPECT_EQ("0", list2str(l));
    }
    {
        ListNode*l = new ListNode(-1);
        EXPECT_EQ("-1", list2str(l));
    }
    {
        ListNode*l = new ListNode(1);
        EXPECT_EQ("1", list2str(l));
    }
    {
        ListNode*l = new ListNode(1);
        l->next = new ListNode(2);
        EXPECT_EQ("1,2", list2str(l));
    }
    {
        ListNode*l = new ListNode(1);
        l->next = new ListNode(2);
        l->next->next = new ListNode(3);
        EXPECT_EQ("1,2,3", list2str(l));
    }
    {
        ListNode*l = new ListNode(1);
        l->next = new ListNode(2);
        l->next->next = new ListNode(3);
        l->next->next->next = new ListNode(4);
        EXPECT_EQ("1,2,3,4", list2str(l));
    }
}


TEST(LeetCode, 003) {
    Solution solution;
    EXPECT_EQ(0, solution.lengthOfLongestSubstring(""));
    EXPECT_EQ(1, solution.lengthOfLongestSubstring(" "));
    EXPECT_EQ(2, solution.lengthOfLongestSubstring("aab"));
    EXPECT_EQ(3, solution.lengthOfLongestSubstring("abcabcbb"));
    EXPECT_EQ(1, solution.lengthOfLongestSubstring("bbbbb"));
    EXPECT_EQ(3, solution.lengthOfLongestSubstring("pwwkew"));
    EXPECT_EQ(5, solution.lengthOfLongestSubstring("qrsvbspk"));
    EXPECT_EQ(3, solution.lengthOfLongestSubstring("aabaab!bb"));
    EXPECT_EQ(5, solution.lengthOfLongestSubstring("12123536216"));
    EXPECT_EQ(4, solution.lengthOfLongestSubstring("',...1212353632.2.16"));
}


TEST(LeetCode, 004) {
    Solution solution;
    {
        vector<int> nums1 = {}, nums2 = { 1 };
        EXPECT_EQ(1, solution.findMedianSortedArrays(nums1, nums2));
    }
    {
        vector<int> nums1 = { 1,3 }, nums2 = { 2 };
        EXPECT_EQ(2, solution.findMedianSortedArrays(nums1, nums2));
    }
    {
        vector<int> nums1 = { 1, 2, 3, 4 }, nums2 = { 5,6,7 };
        EXPECT_EQ(4, solution.findMedianSortedArrays(nums1, nums2));
    }
    {
        vector<int> nums1 = { 1, 2, 3, 4 }, nums2 = { 5,6,7,8 };
        EXPECT_EQ(4.5, solution.findMedianSortedArrays(nums1, nums2));
    }
    {
        vector<int> nums1 = { 1, 2, 3 }, nums2 = { 5,6,7,8 };
        EXPECT_EQ(5, solution.findMedianSortedArrays(nums1, nums2));
    }
    {
        vector<int> nums1 = { 9, 9, 13 }, nums2 = { 5,6,7,8 };
        EXPECT_EQ(8, solution.findMedianSortedArrays(nums1, nums2));
    }
    {
        vector<int> nums1 = { 1, 3, 5 }, nums2 = { 1,4,8 };
        EXPECT_EQ(3.5, solution.findMedianSortedArrays(nums1, nums2));
    }
    {
        vector<int> nums1 = { 3,4 }, nums2 = { 1,2,5,7,8 };
        EXPECT_EQ(4, solution.findMedianSortedArrays(nums1, nums2));
    }
}


TEST(LeetCode, 019) {
    Solution solution;
    {
        ListNode*l1 = str2list("1");
        ListNode*exp = str2list("");
        ListNode*ret = solution.removeNthFromEnd(l1, 1);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1,2");
        ListNode*exp = str2list("1");
        ListNode*ret = solution.removeNthFromEnd(l1, 1);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1,2,3");
        ListNode*exp = str2list("1,2");
        ListNode*ret = solution.removeNthFromEnd(l1, 1);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1,2,3");
        ListNode*exp = str2list("1,3");
        ListNode*ret = solution.removeNthFromEnd(l1, 2);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1,2,3");
        ListNode*exp = str2list("2,3");
        ListNode*ret = solution.removeNthFromEnd(l1, 3);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
}


TEST(LeetCode, 021) {
    Solution solution;
    ListNode*l1 = str2list("1,2,4");
    ListNode*l2 = str2list("1,3,4");
    ListNode*exp = str2list("1,1,2,3,4,4");
    ListNode*ret = solution.mergeTwoLists(l1, l2);
    EXPECT_LIST_VAL_EQ(exp, ret);
}


TEST(LeetCode, 023) {
    Solution solution;
    ListNode*l1 = str2list("1,2,4");
    ListNode*l2 = str2list("1,3,4");
    ListNode*exp = str2list("1,1,2,3,4,4");
    ListNode*ret = solution.mergeKLists(vector<ListNode*>{ l1, l2 });
    EXPECT_LIST_VAL_EQ(exp, ret);
}


TEST(LeetCode, 024) {
    Solution solution;
    {
        ListNode*l1 = str2list("");
        ListNode*exp = str2list("");
        ListNode*ret = solution.swapPairs(l1);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1");
        ListNode*exp = str2list("1");
        ListNode*ret = solution.swapPairs(l1);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1,2");
        ListNode*exp = str2list("2,1");
        ListNode*ret = solution.swapPairs(l1);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1,2,3");
        ListNode*exp = str2list("2,1,3");
        ListNode*ret = solution.swapPairs(l1);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1,2,3,4");
        ListNode*exp = str2list("2,1,4,3");
        ListNode*ret = solution.swapPairs(l1);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
}


TEST(LeetCode, 025) {
    Solution solution;
    {
        ListNode*l1 = str2list("1,2,3,4,5");
        ListNode*exp = str2list("2,1,4,3,5");
        ListNode*ret = solution.reverseKGroup(l1, 2);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("");
        ListNode*exp = str2list("");
        ListNode*ret = solution.reverseKGroup(l1, 3);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1");
        ListNode*exp = str2list("1");
        ListNode*ret = solution.reverseKGroup(l1, 3);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1,2");
        ListNode*exp = str2list("1,2");
        ListNode*ret = solution.reverseKGroup(l1, 3);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1,2,3");
        ListNode*exp = str2list("3,2,1");
        ListNode*ret = solution.reverseKGroup(l1, 3);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1,2,3,4");
        ListNode*exp = str2list("3,2,1,4");
        ListNode*ret = solution.reverseKGroup(l1, 3);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1,2,3,4,5");
        ListNode*exp = str2list("3,2,1,4,5");
        ListNode*ret = solution.reverseKGroup(l1, 3);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1,2,3,4,5,6");
        ListNode*exp = str2list("3,2,1,6,5,4");
        ListNode*ret = solution.reverseKGroup(l1, 3);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1,2,3,4,5,6,7");
        ListNode*exp = str2list("3,2,1,6,5,4,7");
        ListNode*ret = solution.reverseKGroup(l1, 3);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1,2,3,4");
        ListNode*exp = str2list("4,3,2,1");
        ListNode*ret = solution.reverseKGroup(l1, 4);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1,2,3,4,5");
        ListNode*exp = str2list("4,3,2,1,5");
        ListNode*ret = solution.reverseKGroup(l1, 4);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1,2,3,4,5");
        ListNode*exp = str2list("5,4,3,2,1");
        ListNode*ret = solution.reverseKGroup(l1, 5);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1,2,3,4,5,6");
        ListNode*exp = str2list("5,4,3,2,1,6");
        ListNode*ret = solution.reverseKGroup(l1, 5);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
}


TEST(LeetCode, 061) {
    Solution solution;
    {
        ListNode*l1 = str2list("");
        ListNode*exp = str2list("");
        ListNode*ret = solution.rotateRight(l1, 0);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1,2,3,4,5");
        ListNode*exp = str2list("1,2,3,4,5");
        ListNode*ret = solution.rotateRight(l1, 0);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1,2,3,4,5");
        ListNode*exp = str2list("5,1,2,3,4");
        ListNode*ret = solution.rotateRight(l1, 1);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1,2,3,4,5");
        ListNode*exp = str2list("4,5,1,2,3");
        ListNode*ret = solution.rotateRight(l1, 2);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1,2,3,4,5");
        ListNode*exp = str2list("3,4,5,1,2");
        ListNode*ret = solution.rotateRight(l1, 3);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1,2,3,4,5");
        ListNode*exp = str2list("2,3,4,5,1");
        ListNode*ret = solution.rotateRight(l1, 4);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1,2,3,4,5");
        ListNode*exp = str2list("1,2,3,4,5");
        ListNode*ret = solution.rotateRight(l1, 5);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1,2,3,4,5");
        ListNode*exp = str2list("5,1,2,3,4");
        ListNode*ret = solution.rotateRight(l1, 6);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
}

TEST(LeetCode, 082) {
    Solution solution;
    {
        ListNode*l1 = str2list("");
        ListNode*exp = str2list("");
        ListNode*ret = solution.deleteDuplicates(l1);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1");
        ListNode*exp = str2list("1");
        ListNode*ret = solution.deleteDuplicates(l1);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1,1");
        ListNode*exp = str2list("");
        ListNode*ret = solution.deleteDuplicates(l1);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1,2,2,4,5");
        ListNode*exp = str2list("1,4,5");
        ListNode*ret = solution.deleteDuplicates(l1);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1,1,2,2,5");
        ListNode*exp = str2list("5");
        ListNode*ret = solution.deleteDuplicates(l1);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1,1,1,2,2");
        ListNode*exp = str2list("");
        ListNode*ret = solution.deleteDuplicates(l1);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1,2,5,5,5");
        ListNode*exp = str2list("1,2");
        ListNode*ret = solution.deleteDuplicates(l1);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1,1,1,1,1");
        ListNode*exp = str2list("");
        ListNode*ret = solution.deleteDuplicates(l1);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
}

TEST(LeetCode, 083) {
    Solution solution;
    {
        ListNode*l1 = str2list("");
        ListNode*exp = str2list("");
        ListNode*ret = solution.deleteDuplicatesOne(l1);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1");
        ListNode*exp = str2list("1");
        ListNode*ret = solution.deleteDuplicatesOne(l1);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1,1");
        ListNode*exp = str2list("1");
        ListNode*ret = solution.deleteDuplicatesOne(l1);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1,2,2,4,5");
        ListNode*exp = str2list("1,2,4,5");
        ListNode*ret = solution.deleteDuplicatesOne(l1);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1,1,2,2,5");
        ListNode*exp = str2list("1,2,5");
        ListNode*ret = solution.deleteDuplicatesOne(l1);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1,1,1,2,2");
        ListNode*exp = str2list("1,2");
        ListNode*ret = solution.deleteDuplicatesOne(l1);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1,2,5,5,5");
        ListNode*exp = str2list("1,2,5");
        ListNode*ret = solution.deleteDuplicatesOne(l1);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1,1,1,1,1");
        ListNode*exp = str2list("1");
        ListNode*ret = solution.deleteDuplicatesOne(l1);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
}

TEST(LeetCode, 086) {
#if 0
    Solution solution;
    {
        ListNode*l1 = str2list("");
        ListNode*exp = str2list("");
        ListNode*ret = solution.partition(l1, 3);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1");
        ListNode*exp = str2list("1");
        ListNode*ret = solution.partition(l1, 3);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1,2");
        ListNode*exp = str2list("1,2");
        ListNode*ret = solution.partition(l1, 3);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1,2,3,4,5");
        ListNode*exp = str2list("1,2,3,4,5");
        ListNode*ret = solution.partition(l1, 3);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("3,1,2,2,5");
        ListNode*exp = str2list("1,2,2,3,5");
        ListNode*ret = solution.partition(l1, 3);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1,1,3,2,2");
        ListNode*exp = str2list("1,1,2,2,3");
        ListNode*ret = solution.partition(l1, 3);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1,2,5,3,5");
        ListNode*exp = str2list("1,2,5,3,5");
        ListNode*ret = solution.partition(l1, 3);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("3,1,1,1,1");
        ListNode*exp = str2list("1,1,1,1,3");
        ListNode*ret = solution.partition(l1, 3);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
#endif
}


TEST(LeetCode, 092) {
    Solution solution;
    {
        ListNode*l1 = str2list("");
        ListNode*exp = str2list("");
        ListNode*ret = solution.reverseBetween(l1, 1, 1);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1");
        ListNode*exp = str2list("1");
        ListNode*ret = solution.reverseBetween(l1, 1, 1);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1,2");
        ListNode*exp = str2list("1,2");
        ListNode*ret = solution.reverseBetween(l1, 1, 1);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1,2");
        ListNode*exp = str2list("2,1");
        ListNode*ret = solution.reverseBetween(l1, 1, 2);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1,2,3,4,5");
        ListNode*exp = str2list("2,1,3,4,5");
        ListNode*ret = solution.reverseBetween(l1, 1, 2);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1,2,3,4,5");
        ListNode*exp = str2list("5,4,3,2,1");
        ListNode*ret = solution.reverseBetween(l1, 1, 5);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1,1,1,2,2");
        ListNode*exp = str2list("2,1,1,1,2");
        ListNode*ret = solution.reverseBetween(l1, 1, 4);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1,1,1,1,2");
        ListNode*exp = str2list("2,1,1,1,1");
        ListNode*ret = solution.reverseBetween(l1, 1, 5);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1,1,1,2,2");
        ListNode*exp = str2list("1,1,1,2,2");
        ListNode*ret = solution.reverseBetween(l1, 2, 2);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1,2,3,4,5");
        ListNode*exp = str2list("1,3,2,4,5");
        ListNode*ret = solution.reverseBetween(l1, 2, 3);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1,2,3,4,5");
        ListNode*exp = str2list("1,5,4,3,2");
        ListNode*ret = solution.reverseBetween(l1, 2, 5);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
    {
        ListNode*l1 = str2list("1,2,3,4,5");
        ListNode*exp = str2list("1,2,5,4,3");
        ListNode*ret = solution.reverseBetween(l1, 3, 5);
        EXPECT_LIST_VAL_EQ(exp, ret);
    }
}

TEST(LeetCode, 105) {
    Solution solution;
    {
        TreeNode* exp = new TreeNode(3);
        exp->left = new TreeNode(9);
        exp->right = new TreeNode(20);
        exp->right->left = new TreeNode(15);
        exp->right->right = new TreeNode(7);
        TreeNode* ret = solution.buildTree(vector<int>{ 3, 9, 20, 15, 7 }, vector<int>{ 9, 3, 15, 20, 7 });
        EXPECT_TRUE(solution.isSameTree(ret, exp));
    }
    {
        TreeNode* exp = new TreeNode(2);
        exp->left = new TreeNode(3);
        exp->right = new TreeNode(5);
        exp->left->left = new TreeNode(9);
        exp->left->right = new TreeNode(8);
        TreeNode* ret = solution.buildTree(vector<int>{ 2, 3, 9, 8, 5 }, vector<int>{ 9, 3, 8, 2, 5 });
        EXPECT_TRUE(solution.isSameTree(ret, exp));
    }
}

TEST(LeetCode, 106) {
    Solution solution;
    {
        TreeNode* exp = new TreeNode(3);
        exp->left = new TreeNode(9);
        exp->right = new TreeNode(20);
        exp->right->left = new TreeNode(15);
        exp->right->right = new TreeNode(7);
        TreeNode* ret = solution.buildTree_in_post(vector<int>{ 9, 3, 15, 20, 7 }, vector<int>{ 9, 15, 7, 20, 3 });
        EXPECT_TRUE(solution.isSameTree(ret, exp));
    }
    {
        TreeNode* exp = new TreeNode(2);
        exp->left = new TreeNode(3);
        exp->right = new TreeNode(5);
        exp->left->left = new TreeNode(9);
        exp->left->right = new TreeNode(8);
        TreeNode* ret = solution.buildTree_in_post(vector<int>{ 9, 3, 8, 2, 5 }, vector<int>{ 9, 8, 3, 5, 2 });
        EXPECT_TRUE(solution.isSameTree(ret, exp));
    }
    {
        TreeNode* exp = new TreeNode(1);
        exp->left = new TreeNode(2);
        exp->left->right = new TreeNode(3);
        TreeNode* ret = solution.buildTree_in_post(vector<int>{ 2, 3, 1 }, vector<int>{ 3, 2, 1 });
        EXPECT_TRUE(solution.isSameTree(ret, exp));
    }
}


TEST(LeetCode, 107) {
    Solution solution;
    {
        TreeNode* exp = new TreeNode(0);
        exp->left = new TreeNode(-3);
        exp->right = new TreeNode(9);
        exp->left->left = new TreeNode(-10);
        exp->right->left = new TreeNode(5);
        TreeNode* ret = solution.sortedArrayToBST(vector<int>{-10, -3, 0, 5, 9});
        EXPECT_TRUE(solution.isSameTree(ret, exp));
    }
}

TEST(LeetCode, 110) {
    Solution solution;
    {
        TreeNode* t = solution.buildTree(vector<int>{ 3, 9, 20, 15, 7 }, vector<int>{ 9, 3, 15, 20, 7 });
        EXPECT_TRUE(solution.isBalanced(t));
    }
    {
        TreeNode* t = solution.buildTree(vector<int>{ 1, 2, 3, 4, 4, 3, 2 }, vector<int>{ 4, 3, 4, 2, 3, 1, 2 });
        EXPECT_FALSE(solution.isBalanced(t));
    }
}

TEST(LeetCode, 111) {
    Solution solution;
    {
        TreeNode* t = nullptr;
        EXPECT_EQ(0, solution.minDepth(t));
    }
    {
        TreeNode* t = new TreeNode(1);
        EXPECT_EQ(1, solution.minDepth(t));
    }
    {
        TreeNode* t = solution.buildTree(vector<int>{ 1, 2 }, vector<int>{ 1, 2 });
        EXPECT_EQ(2, solution.minDepth(t));
    }
    {
        TreeNode* t = solution.buildTree(vector<int>{ 3, 9, 20, 15, 7 }, vector<int>{ 9, 3, 15, 20, 7 });
        EXPECT_EQ(2, solution.minDepth(t));
    }
    {
        TreeNode* t = solution.buildTree(vector<int>{ 1, 2, 3, 4, 4, 3, 2 }, vector<int>{ 4, 3, 4, 2, 3, 1, 2 });
        EXPECT_EQ(2, solution.minDepth(t));
    }
    {
        TreeNode* t = solution.buildTree(vector<int>{ 1, 2, 3, 4, 5 }, vector<int>{ 5, 4, 3, 2, 1 });
        EXPECT_EQ(5, solution.minDepth(t));
    }
}

TEST(LeetCode, 112) {
    Solution solution;
    {
        TreeNode* t = solution.buildTree(vector<int>{ 5, 4, 11, 7, 2, 8, 13, 4 }, vector<int>{ 7, 11, 2, 4, 5, 13, 8, 4 });
        EXPECT_TRUE(solution.hasPathSum(t, 22));
    }
    {
        TreeNode* t = nullptr;
        EXPECT_FALSE(solution.hasPathSum(t, 22));
    }
    {
        TreeNode* t = new TreeNode(1);
        EXPECT_FALSE(solution.hasPathSum(t, 22));
    }
    {
        TreeNode* t = solution.buildTree(vector<int>{ 1, 2 }, vector<int>{ 1, 2 });
        EXPECT_FALSE(solution.hasPathSum(t, 22));
    }
    {
        TreeNode* t = solution.buildTree(vector<int>{ 3, 9, 20, 15, 7 }, vector<int>{ 9, 3, 15, 20, 7 });
        EXPECT_FALSE(solution.hasPathSum(t, 22));
    }
    {
        TreeNode* t = solution.buildTree(vector<int>{ 1, 2, 3, 4, 4, 3, 2 }, vector<int>{ 4, 3, 4, 2, 3, 1, 2 });
        EXPECT_FALSE(solution.hasPathSum(t, 22));
    }
    {
        TreeNode* t = solution.buildTree(vector<int>{ 1, 2, 3, 4, 5 }, vector<int>{ 5, 4, 3, 2, 1 });
        EXPECT_FALSE(solution.hasPathSum(t, 22));
    }
}