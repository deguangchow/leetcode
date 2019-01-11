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
    char buf[64] = { 0 };
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

//2个单链表的节点内容比较
#define  LIST_VAL_COMPARE(l1, l2) {\
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
        LIST_VAL_COMPARE(l, ret);
    }
    {
        ListNode*l = new ListNode(0);
        ListNode*ret = str2list("0");
        LIST_VAL_COMPARE(l, ret);
    }
    {
        ListNode*l = new ListNode(-1);
        ListNode*ret = str2list("-1");
        LIST_VAL_COMPARE(l, ret);
    }
    {
        ListNode*l = new ListNode(1);
        ListNode*ret = str2list("1");
        LIST_VAL_COMPARE(l, ret);
    }
    {
        ListNode*l = new ListNode(1);
        l->next = new ListNode(2);
        ListNode*ret = str2list("1,2");
        LIST_VAL_COMPARE(l, ret);
    }
    {
        ListNode*l = new ListNode(1);
        l->next = new ListNode(2);
        l->next->next = new ListNode(3);
        ListNode*ret = str2list("1,2,3");
        LIST_VAL_COMPARE(l, ret);
    }
    {
        ListNode*l = new ListNode(1);
        l->next = new ListNode(2);
        l->next->next = new ListNode(3);
        l->next->next->next = new ListNode(4);
        ListNode*ret = str2list("1,2,3,4");
        LIST_VAL_COMPARE(l, ret);
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
    ListNode*l1 = new ListNode(1);
    auto ret = solution.removeNthFromEnd(l1, 1);
}


TEST(LeetCode, 021) {
    Solution solution;
    ListNode*l1 = str2list("1,2,4");
    ListNode*l2 = str2list("1,3,4");
    ListNode*exp = str2list("1,1,2,3,4,4");
    auto ret = solution.mergeTwoLists(l1, l2);
    LIST_VAL_COMPARE(exp, ret);
}


TEST(LeetCode, 023) {
    Solution solution;
    ListNode*l1 = str2list("1,2,4");
    ListNode*l2 = str2list("1,3,4");
    ListNode*exp = str2list("1,1,2,3,4,4");
    auto ret = solution.mergeKLists(vector<ListNode*>{ l1, l2 });
    LIST_VAL_COMPARE(exp, ret);
}


TEST(LeetCode, 024) {
    Solution solution;
    {
        ListNode*l1 = nullptr;
        auto ret = solution.swapPairs(l1);
        EXPECT_EQ(l1, ret);
    }
    {
        ListNode*l1 = new ListNode(1);
        auto ret = solution.swapPairs(l1);
        EXPECT_EQ(l1, ret);
    }
    {
        ListNode*l1 = new ListNode(1);
        l1->next = new ListNode(2);
        auto expect = l1->next;
        auto ret = solution.swapPairs(l1);
        EXPECT_EQ(expect, ret);
    }
    {
        ListNode*l1 = new ListNode(1);
        l1->next = new ListNode(2);
        l1->next->next = new ListNode(3);
        auto expect = l1->next;
        auto ret = solution.swapPairs(l1);
        EXPECT_EQ(expect, ret);
    }
    {
        ListNode*l1 = new ListNode(1);
        l1->next = new ListNode(2);
        l1->next->next = new ListNode(3);
        l1->next->next->next = new ListNode(4);
        auto expect = l1->next;
        auto ret = solution.swapPairs(l1);
        EXPECT_EQ(expect, ret);
    }
}


TEST(LeetCode, 025) {
    Solution solution;
    {
        ListNode*l1 = new ListNode(1);
        l1->next = new ListNode(2);
        l1->next->next = new ListNode(3);
        l1->next->next->next = new ListNode(4);
        l1->next->next->next->next = new ListNode(5);
        auto expect = l1->next;
        auto ret = solution.reverseKGroup(l1, 2);
        EXPECT_EQ(expect, ret);
    }
    {
        ListNode*l1 = nullptr;
        auto ret = solution.reverseKGroup(l1, 3);
        EXPECT_EQ(l1, ret);
    }
    {
        ListNode*l1 = new ListNode(1);
        auto ret = solution.reverseKGroup(l1, 3);
        EXPECT_EQ(l1, ret);
    }
    {
        ListNode*l1 = new ListNode(1);
        l1->next = new ListNode(2);
        auto expect = l1;
        auto ret = solution.reverseKGroup(l1, 3);
        EXPECT_EQ(expect, ret);
    }
    {
        ListNode*l1 = new ListNode(1);
        l1->next = new ListNode(2);
        l1->next->next = new ListNode(3);
        auto expect = l1->next->next;
        auto ret = solution.reverseKGroup(l1, 3);
        EXPECT_EQ(expect, ret);
    }
    {
        ListNode*l1 = new ListNode(1);
        l1->next = new ListNode(2);
        l1->next->next = new ListNode(3);
        l1->next->next->next = new ListNode(4);
        auto expect = l1->next->next;
        auto ret = solution.reverseKGroup(l1, 3);
        EXPECT_EQ(expect, ret);
    }
    {
        ListNode*l1 = new ListNode(1);
        l1->next = new ListNode(2);
        l1->next->next = new ListNode(3);
        l1->next->next->next = new ListNode(4);
        l1->next->next->next->next = new ListNode(5);
        auto expect = l1->next->next;
        auto ret = solution.reverseKGroup(l1, 3);
        EXPECT_EQ(expect, ret);
    }
    {
        ListNode*l1 = new ListNode(1);
        l1->next = new ListNode(2);
        l1->next->next = new ListNode(3);
        l1->next->next->next = new ListNode(4);
        l1->next->next->next->next = new ListNode(5);
        l1->next->next->next->next->next = new ListNode(6);
        auto expect = l1->next->next;
        auto ret = solution.reverseKGroup(l1, 3);
        EXPECT_EQ(expect, ret);
    }
    {
        ListNode*l1 = new ListNode(1);
        l1->next = new ListNode(2);
        l1->next->next = new ListNode(3);
        l1->next->next->next = new ListNode(4);
        l1->next->next->next->next = new ListNode(5);
        l1->next->next->next->next->next = new ListNode(6);
        l1->next->next->next->next->next->next = new ListNode(7);
        auto expect = l1->next->next;
        auto ret = solution.reverseKGroup(l1, 3);
        EXPECT_EQ(expect, ret);
    }
    {
        ListNode*l1 = new ListNode(1);
        l1->next = new ListNode(2);
        l1->next->next = new ListNode(3);
        l1->next->next->next = new ListNode(4);
        auto expect = l1->next->next->next;
        auto ret = solution.reverseKGroup(l1, 4);
        EXPECT_EQ(expect, ret);
    }
    {
        ListNode*l1 = new ListNode(1);
        l1->next = new ListNode(2);
        l1->next->next = new ListNode(3);
        l1->next->next->next = new ListNode(4);
        l1->next->next->next->next = new ListNode(5);
        auto expect = l1->next->next->next;
        auto ret = solution.reverseKGroup(l1, 4);
        EXPECT_EQ(expect, ret);
    }
    {
        ListNode*l1 = new ListNode(1);
        l1->next = new ListNode(2);
        l1->next->next = new ListNode(3);
        l1->next->next->next = new ListNode(4);
        l1->next->next->next->next = new ListNode(5);
        auto expect = l1->next->next->next->next;
        auto ret = solution.reverseKGroup(l1, 5);
        EXPECT_EQ(expect, ret);
    }
    {
        ListNode*l1 = new ListNode(1);
        l1->next = new ListNode(2);
        l1->next->next = new ListNode(3);
        l1->next->next->next = new ListNode(4);
        l1->next->next->next->next = new ListNode(5);
        l1->next->next->next->next->next = new ListNode(6);
        auto expect = l1->next->next->next->next;
        auto ret = solution.reverseKGroup(l1, 5);
        EXPECT_EQ(expect, ret);
    }

}

