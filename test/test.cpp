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
#include "LRUCache.h"
#include "MinStack.h"
#include "Trie.h"
#include "WordDictionary.h"
#include "MyStack.h"
#include "MyQueue.h"
#include "PeekingIterator.h"
#include "MedianFinder.h"
#include "HeapDemo.h"
#include "MyCircularQueue.h"


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


//2个vector的节点内容比较
#define EXPECT_VECTOR_VAL_EQ(v1, v2) {\
    vector<int>::const_iterator& pos1 = v1.begin();\
    vector<int>::const_iterator& pos2 = v2.begin();\
    for (; pos1 != v1.end() && pos2 != v2.end(); ++pos1, ++pos2) {\
        EXPECT_EQ(*pos1, *pos2);\
    }\
    EXPECT_TRUE(pos1 == v1.end());\
    EXPECT_TRUE(pos2 == v2.end());\
}
#define EXPECT_VECTORS_VAL_EQ(v1, v2) {\
    vector<vector<int>>::const_iterator& pos1 = v1.begin();\
    vector<vector<int>>::const_iterator& pos2 = v2.begin();\
    for (; pos1 != v1.end() && pos2 != v2.end(); ++pos1, ++pos2) {\
        vector<int> const& v1_val = *pos1;\
        vector<int> const& v2_val = *pos2;\
        EXPECT_VECTOR_VAL_EQ(v1_val, v2_val);\
    }\
    EXPECT_TRUE(pos1 == v1.end());\
    EXPECT_TRUE(pos2 == v2.end());\
}


template<class T>
class expect_eq {
private:
    using VECTOR = vector<T>;
    using VECTORS = vector<vector<T>>;

public:
    static void expect_vector_val_eq(VECTOR const& v1, VECTOR const& v2) {
        VECTOR::const_iterator& pos1 = v1.begin();
        VECTOR::const_iterator& pos2 = v2.begin();
        for (; pos1 != v1.end() && pos2 != v2.end(); ++pos1, ++pos2) {
            EXPECT_EQ(*pos1, *pos2);
        }
        EXPECT_TRUE(pos1 == v1.end());
        EXPECT_TRUE(pos2 == v2.end());
    }
    static void expect_vectors_val_eq(VECTORS const& v1, VECTORS const& v2) {
        VECTORS::const_iterator& pos1 = v1.begin();
        VECTORS::const_iterator& pos2 = v2.begin();
        for (; pos1 != v1.end() && pos2 != v2.end(); ++pos1, ++pos2) {
            expect_vector_val_eq(*pos1, *pos2);
        }
        EXPECT_TRUE(pos1 == v1.end());
        EXPECT_TRUE(pos2 == v2.end());
    }
};


//数组长度
#define LENGTH_OF_ARRAY(a) sizeof(a)/sizeof(a[0])


#if 0

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
        vector<int> nums1 = { 1, 3 }, nums2 = { 2 };
        EXPECT_EQ(2, solution.findMedianSortedArrays(nums1, nums2));
    }
    {
        vector<int> nums1 = { 1, 2, 3, 4 }, nums2 = { 5, 6, 7 };
        EXPECT_EQ(4, solution.findMedianSortedArrays(nums1, nums2));
    }
    {
        vector<int> nums1 = { 1, 2, 3, 4 }, nums2 = { 5, 6, 7, 8 };
        EXPECT_EQ(4.5, solution.findMedianSortedArrays(nums1, nums2));
    }
    {
        vector<int> nums1 = { 1, 2, 3 }, nums2 = { 5, 6, 7, 8 };
        EXPECT_EQ(5, solution.findMedianSortedArrays(nums1, nums2));
    }
    {
        vector<int> nums1 = { 9, 9, 13 }, nums2 = { 5, 6, 7, 8 };
        EXPECT_EQ(8, solution.findMedianSortedArrays(nums1, nums2));
    }
    {
        vector<int> nums1 = { 1, 3, 5 }, nums2 = { 1, 4, 8 };
        EXPECT_EQ(3.5, solution.findMedianSortedArrays(nums1, nums2));
    }
    {
        vector<int> nums1 = { 3, 4 }, nums2 = { 1, 2, 5, 7, 8 };
        EXPECT_EQ(4, solution.findMedianSortedArrays(nums1, nums2));
    }
}


TEST(LeetCode, 005) {
    Solution solution;
    EXPECT_EQ("", solution.longestPalindrome(""));
    EXPECT_EQ(" ", solution.longestPalindrome(" "));
    EXPECT_EQ("bacab", solution.longestPalindrome("abacab"));
    EXPECT_EQ("aaabaaa", solution.longestPalindrome("aaaabaaa"));
    EXPECT_EQ("a", solution.longestPalindrome("a"));
    EXPECT_EQ("a", solution.longestPalindrome("ac"));
    EXPECT_EQ("bab", solution.longestPalindrome("babad"));
    EXPECT_EQ("aaabaaa", solution.longestPalindrome("aaabaaaa"));
    EXPECT_EQ("bb", solution.longestPalindrome("cbbd"));
    EXPECT_EQ("aa", solution.longestPalindrome("aab"));
    EXPECT_EQ("bcb", solution.longestPalindrome("abcabcbb"));
    EXPECT_EQ("bbbbb", solution.longestPalindrome("bbbbb"));
    EXPECT_EQ("ww", solution.longestPalindrome("pwwkew"));
    EXPECT_EQ("q", solution.longestPalindrome("qrsvbspk"));
    EXPECT_EQ("aabaa", solution.longestPalindrome("aabaab!bb"));
    EXPECT_EQ("121", solution.longestPalindrome("12123536216"));
    EXPECT_EQ("...", solution.longestPalindrome("',...1212353632.2.16"));
    string const &s = "11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111"
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111"
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111"
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111"
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111"
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111"
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111"
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111"
        "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111"
        "111111111111111111111111111111111";
    EXPECT_EQ(s, solution.longestPalindrome(s));
}


TEST(LeetCode, 006) {
    Solution solution;
    EXPECT_EQ("LEETCODEISHIRING", solution.convert("LEETCODEISHIRING", 1));
    EXPECT_EQ("LECDIHRNETOESIIG", solution.convert("LEETCODEISHIRING", 2));
    EXPECT_EQ("LCIRETOESIIGEDHN", solution.convert("LEETCODEISHIRING", 3));
    EXPECT_EQ("LDREOEIIECIHNTSG", solution.convert("LEETCODEISHIRING", 4));
}


TEST(LeetCode, 007) {
    Solution solution;
    EXPECT_EQ(1, solution.reverse(100));
    EXPECT_EQ(321, solution.reverse(123));
    EXPECT_EQ(-321, solution.reverse(-123));
    EXPECT_EQ(21, solution.reverse(120));
    EXPECT_EQ(0, solution.reverse(0));
    EXPECT_EQ(1, solution.reverse(1));
    EXPECT_EQ(-1, solution.reverse(-1));
    EXPECT_EQ(1, solution.reverse(10));
    EXPECT_EQ(-1, solution.reverse(-10));
    EXPECT_EQ(0, solution.reverse(INT_MAX));
    EXPECT_EQ(0, solution.reverse(INT_MAX + 1));
    EXPECT_EQ(0, solution.reverse(INT_MIN));
}


TEST(LeetCode, 008) {
    Solution solution;
    EXPECT_EQ(0, solution.myAtoi("+0 123"));
    EXPECT_EQ(0, solution.myAtoi("+-2"));
    EXPECT_EQ(0, solution.myAtoi("+0"));
    EXPECT_EQ(1, solution.myAtoi("+1"));
    EXPECT_EQ(123, solution.myAtoi("+123"));
    EXPECT_EQ(42, solution.myAtoi("42"));
    EXPECT_EQ(-42, solution.myAtoi("-42"));
    EXPECT_EQ(-42, solution.myAtoi("   -42"));
    EXPECT_EQ(4193, solution.myAtoi("4193 with words"));
    EXPECT_EQ(0, solution.myAtoi("words and 987"));
    EXPECT_EQ(INT_MIN, solution.myAtoi("-91283472332"));
    EXPECT_EQ(120, solution.myAtoi("120"));
    EXPECT_EQ(0, solution.myAtoi("0"));
    EXPECT_EQ(1, solution.myAtoi("1"));
    EXPECT_EQ(-1, solution.myAtoi("-1"));
    EXPECT_EQ(10, solution.myAtoi("10"));
    EXPECT_EQ(-10, solution.myAtoi("-10"));
    EXPECT_EQ(INT_MAX, solution.myAtoi("2147483647"));
    EXPECT_EQ(INT_MAX, solution.myAtoi("2147483648"));
    EXPECT_EQ(INT_MAX, solution.myAtoi("20000000000000000000"));
    EXPECT_EQ(INT_MIN, solution.myAtoi("-2147483648"));
    EXPECT_EQ(INT_MIN, solution.myAtoi("-2147483649"));
}


TEST(LeetCode, 009) {
    Solution solution;
    EXPECT_TRUE(solution.isPalindrome(121));
    EXPECT_TRUE(solution.isPalindrome(0));
    EXPECT_TRUE(solution.isPalindrome(1));
    EXPECT_TRUE(solution.isPalindrome(12321));

    EXPECT_FALSE(solution.isPalindrome(-121));
    EXPECT_FALSE(solution.isPalindrome(100));
    EXPECT_FALSE(solution.isPalindrome(123));
    EXPECT_FALSE(solution.isPalindrome(-123));
    EXPECT_FALSE(solution.isPalindrome(120));
    EXPECT_FALSE(solution.isPalindrome(-1));
    EXPECT_FALSE(solution.isPalindrome(10));
    EXPECT_FALSE(solution.isPalindrome(-10));
    EXPECT_FALSE(solution.isPalindrome(INT_MAX));
    EXPECT_FALSE(solution.isPalindrome(INT_MAX + 1));
    EXPECT_FALSE(solution.isPalindrome(INT_MIN));
}


TEST(LeetCode, 012) {
    Solution solution;
    EXPECT_EQ("I", solution.intToRoman(1));
    EXPECT_EQ("II", solution.intToRoman(2));
    EXPECT_EQ("III", solution.intToRoman(3));
    EXPECT_EQ("IV", solution.intToRoman(4));
    EXPECT_EQ("V", solution.intToRoman(5));
    EXPECT_EQ("VI", solution.intToRoman(6));
    EXPECT_EQ("VII", solution.intToRoman(7));
    EXPECT_EQ("VIII", solution.intToRoman(8));
    EXPECT_EQ("IX", solution.intToRoman(9));
    EXPECT_EQ("X", solution.intToRoman(10));
    EXPECT_EQ("XI", solution.intToRoman(11));
    EXPECT_EQ("XII", solution.intToRoman(12));
    EXPECT_EQ("XIII", solution.intToRoman(13));
    EXPECT_EQ("XIV", solution.intToRoman(14));
    EXPECT_EQ("XV", solution.intToRoman(15));
    EXPECT_EQ("XVI", solution.intToRoman(16));
    EXPECT_EQ("XVII", solution.intToRoman(17));
    EXPECT_EQ("XVIII", solution.intToRoman(18));
    EXPECT_EQ("XIX", solution.intToRoman(19));
    EXPECT_EQ("XX", solution.intToRoman(20));
    EXPECT_EQ("LIX", solution.intToRoman(59));
    EXPECT_EQ("LXIX", solution.intToRoman(69));
    EXPECT_EQ("LXXIX", solution.intToRoman(79));
    EXPECT_EQ("LXXXIX", solution.intToRoman(89));
    EXPECT_EQ("XCIX", solution.intToRoman(99));
    EXPECT_EQ("C", solution.intToRoman(100));
    EXPECT_EQ("CXX", solution.intToRoman(120));
    EXPECT_EQ("CXXIII", solution.intToRoman(123));
    EXPECT_EQ("MMMCMLIX", solution.intToRoman(3959));
}


TEST(LeetCode, 013) {
    Solution solution;
    EXPECT_EQ(1, solution.romanToInt("I"));
    EXPECT_EQ(2, solution.romanToInt("II"));
    EXPECT_EQ(3, solution.romanToInt("III"));
    EXPECT_EQ(4, solution.romanToInt("IV"));
    EXPECT_EQ(5, solution.romanToInt("V"));
    EXPECT_EQ(6, solution.romanToInt("VI"));
    EXPECT_EQ(7, solution.romanToInt("VII"));
    EXPECT_EQ(8, solution.romanToInt("VIII"));
    EXPECT_EQ(9, solution.romanToInt("IX"));
    EXPECT_EQ(10, solution.romanToInt("X"));
    EXPECT_EQ(11, solution.romanToInt("XI"));
    EXPECT_EQ(12, solution.romanToInt("XII"));
    EXPECT_EQ(13, solution.romanToInt("XIII"));
    EXPECT_EQ(14, solution.romanToInt("XIV"));
    EXPECT_EQ(15, solution.romanToInt("XV"));
    EXPECT_EQ(16, solution.romanToInt("XVI"));
    EXPECT_EQ(17, solution.romanToInt("XVII"));
    EXPECT_EQ(18, solution.romanToInt("XVIII"));
    EXPECT_EQ(19, solution.romanToInt("XIX"));
    EXPECT_EQ(20, solution.romanToInt("XX"));
    EXPECT_EQ(59, solution.romanToInt("LIX"));
    EXPECT_EQ(69, solution.romanToInt("LXIX"));
    EXPECT_EQ(79, solution.romanToInt("LXXIX"));
    EXPECT_EQ(89, solution.romanToInt("LXXXIX"));
    EXPECT_EQ(99, solution.romanToInt("XCIX"));
    EXPECT_EQ(100, solution.romanToInt("C"));
    EXPECT_EQ(120, solution.romanToInt("CXX"));
    EXPECT_EQ(123, solution.romanToInt("CXXIII"));
    EXPECT_EQ(3959, solution.romanToInt("MMMCMLIX"));
}


TEST(LeetCode, 014) {
    Solution solution;
    {
        vector<string> vctS = { "flower", "flow", "flight" };
        EXPECT_EQ("fl", solution.longestCommonPrefix(vctS));
    }
    {
        vector<string> vctS = { "flower", "flow", "flight", "f" };
        EXPECT_EQ("f", solution.longestCommonPrefix(vctS));
    }
    {
        vector<string> vctS = { "flower", "flow", "flo" };
        EXPECT_EQ("flo", solution.longestCommonPrefix(vctS));
    }
    {
        vector<string> vctS = { "flower", "flow", "flows", "f" };
        EXPECT_EQ("f", solution.longestCommonPrefix(vctS));
    }
    {
        vector<string> vctS = { "dog", "racecar", "car" };
        EXPECT_EQ("", solution.longestCommonPrefix(vctS));
    }
    {
        vector<string> vctS = { "a", "ab", "abc" };
        EXPECT_EQ("a", solution.longestCommonPrefix(vctS));
    }
}


TEST(LeetCode, 017) {
    Solution s;
    {
        vector<string> const& exp = {
            "a",
            "b",
            "c"
        };
        expect_eq<string>::expect_vector_val_eq(exp, s.letterCombinations("2"));
    }
    {
        vector<string> const& exp = {
            "p",
            "q",
            "r",
            "s"
        };
        expect_eq<string>::expect_vector_val_eq(exp, s.letterCombinations("7"));
    }
    {
        vector<string> const& exp = {
            "ad", "ae", "af",
            "bd", "be", "bf",
            "cd", "ce", "cf"
        };
        expect_eq<string>::expect_vector_val_eq(exp, s.letterCombinations("23"));
    }
    {
        vector<string> const& exp = {
            "adg", "adh", "adi",
            "aeg", "aeh", "aei",
            "afg", "afh", "afi",
            "bdg", "bdh", "bdi",
            "beg", "beh", "bei",
            "bfg", "bfh", "bfi",
            "cdg", "cdh", "cdi",
            "ceg", "ceh", "cei",
            "cfg", "cfh", "cfi"
        };
        expect_eq<string>::expect_vector_val_eq(exp, s.letterCombinations("234"));
    }
}


TEST(LeetCode, 018) {
    Solution s;
    {
        vector<int> nums = {};
        int target = 0;
        vector<vector<int>> const& exp = {};
        auto const& ret = s.fourSum(nums, target);
        EXPECT_VECTORS_VAL_EQ(exp, ret);
    }
    {
        vector<int> nums = { 1, 0, -1, 0, -2, 2 };
        int target = 0;
        vector<vector<int>> const& exp = {
            { -2, -1, 1, 2 },
            { -2,  0, 0, 2 },
            { -1,  0, 0, 1 }
        };
        auto const& ret = s.fourSum(nums, target);
        EXPECT_VECTORS_VAL_EQ(exp, ret);
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


TEST(LeetCode, 020) {
    Solution solution;
    EXPECT_TRUE(solution.isValid("()"));
    EXPECT_TRUE(solution.isValid("()[]{}"));
    EXPECT_TRUE(solution.isValid("{[]}"));
    EXPECT_FALSE(solution.isValid("(]"));
    EXPECT_FALSE(solution.isValid("([)]"));
}


TEST(LeetCode, 021) {
    Solution solution;
    ListNode*l1 = str2list("1,2,4");
    ListNode*l2 = str2list("1,3,4");
    ListNode*exp = str2list("1,1,2,3,4,4");
    ListNode*ret = solution.mergeTwoLists(l1, l2);
    EXPECT_LIST_VAL_EQ(exp, ret);
}


TEST(LeetCode, 022) {
    Solution s;
    {
        vector<string> const& exp = {
            "()",
        };
        expect_eq<string>::expect_vector_val_eq(exp, s.generateParenthesis(1));
    }
    {
        vector<string> const& exp = {
            "(())",
            "()()",
        };
        expect_eq<string>::expect_vector_val_eq(exp, s.generateParenthesis(2));
    }
    {
        vector<string> const& exp = {
            "((()))",
            "(()())",
            "(())()",
            "()(())",
            "()()()"
        };
        expect_eq<string>::expect_vector_val_eq(exp, s.generateParenthesis(3));
    }
    {
        vector<string> const& exp = {
            "(((())))",
            "((()()))",
            "((())())",
            "((()))()",
            "(()(()))",
            "(()()())",
            "(()())()",
            "(())(())",
            "(())()()",
            "()((()))",
            "()(()())",
            "()(())()",
            "()()(())",
            "()()()()"
        };
        expect_eq<string>::expect_vector_val_eq(exp, s.generateParenthesis(4));
    }
    {
        vector<string> const& exp = {
            "((((()))))",
            "(((()())))",
            "(((())()))",
            "(((()))())",
            "(((())))()",
            "((()(())))",
            "((()()()))",
            "((()())())",
            "((()()))()",
            "((())(()))",
            "((())()())",
            "((())())()",
            "((()))(())",
            "((()))()()",
            "(()((())))",
            "(()(()()))",
            "(()(())())",
            "(()(()))()",
            "(()()(()))",
            "(()()()())",
            "(()()())()",
            "(()())(())",
            "(()())()()",
            "(())((()))",
            "(())(()())",
            "(())(())()",
            "(())()(())",
            "(())()()()",
            "()(((())))",
            "()((()()))",
            "()((())())",
            "()((()))()",
            "()(()(()))",
            "()(()()())",
            "()(()())()",
            "()(())(())",
            "()(())()()",
            "()()((()))",
            "()()(()())",
            "()()(())()",
            "()()()(())",
            "()()()()()"
        };
        expect_eq<string>::expect_vector_val_eq(exp, s.generateParenthesis(5));
    }
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


TEST(LeetCode, 025) {
    Solution s;
    EXPECT_EQ(15, s.strStr("BBC ABCDAB ABCDABCDABDE", "ABCDABD"));
    EXPECT_EQ(2, s.strStr("hello", "ll"));
    EXPECT_EQ(-1, s.strStr("aaaaa", "bba"));
    EXPECT_EQ(0, s.strStr("", ""));
    EXPECT_EQ(-1, s.strStr("", "a"));
    EXPECT_EQ(0, s.strStr("a", ""));
    EXPECT_EQ(0, s.strStr("a", "a"));
}


TEST(LeetCode, 030) {
    Solution s;
    {
        vector<int> const& exp = {};
        vector<string> words = { "a", "b", "c", "d" };
        expect_eq<int>::expect_vector_val_eq(exp, s.findSubstring("abbbcd", words));
    }
    {
        vector<int> const& exp = {};
        vector<string> words = { "word", "good", "best", "good" };
        expect_eq<int>::expect_vector_val_eq(exp, s.findSubstring("wordgoodgoodgoodbestwor", words));
    }
    {
        vector<int> const& exp = { 8 };
        vector<string> words = { "word", "good", "best", "good" };
        expect_eq<int>::expect_vector_val_eq(exp, s.findSubstring("wordgoodgoodgoodbestword", words));
    }
    {
        vector<int> const& exp = { 9 };
        vector<string> words = { "word", "good", "best", "good" };
        expect_eq<int>::expect_vector_val_eq(exp, s.findSubstring("awordgoodgoodgoodbestword", words));
    }
    {
        vector<int> const& exp = { 6, 9, 12 };
        vector<string> words = { "bar", "foo", "the" };
        expect_eq<int>::expect_vector_val_eq(exp, s.findSubstring("barfoofoobarthefoobarman", words));
    }
    {
        vector<int> const& exp = { 0, 9 };
        vector<string> words = { "foo", "bar" };
        expect_eq<int>::expect_vector_val_eq(exp, s.findSubstring("barfoothefoobarman", words));
    }
    {
        vector<int> const& exp = {};
        vector<string> words = { "word", "good", "best", "word" };
        expect_eq<int>::expect_vector_val_eq(exp, s.findSubstring("wordgoodgoodgoodbestword", words));
    }
    {
        vector<int> const& exp = {373};
        vector<string> words = {
            "toiscumkhociglkvispihvyoatxcx", "ndojyyephstlonsplrettspwepipw", "yzfkyoqlkrmmfirchzrphveuwmvga",
            "mxxihihnrfbamcyojqpkzodbejtmm", "fenjcjfdlvcpiatuhjdujhaffqsvq", "ehghndyqjodnnblfwmaygdstotfkv",
            "heoldutddnksutjakhtghpxxnjykx", "cvrwdewsxdeumhzfrvoilmvksuhyq", "ftqjvzyssocftjwemroghrncynmtc",
            "idiwclhuepgyynoslhzahtdqwlikt", "eurttrfrmstrbeokzhuzvbfmwywoh", "jxlluilzpysjcnwguyofnhfvhacez",
            "uskegagtlonducdogwbevugppsptd", "xmcxwufajmnveuwuoyosqnoqwvtjk", "wolpsfxdypmlbjotuxewskisnmczf",
            "fjryanrmzmpzoefapmnsjdgecrdyw", "jgmxawmndhsvwnjdjvjtxcsjapfog", "wuhkzghvmjhawcfszbhzrbpgsidnb",
            "yelbldxympctbzfupeocwhkypchuy", "vzduzxudwwqhpftwdspuimioanlzo", "bdpdeofidldoymakfnpgekmsltcrr",
            "fmyeodowglzyjzuhencufcwdobyds", "dhtypunakzituezjyhbrpuksbamui", "bdmiruibwznqcuczculujfiavzwyn",
            "eudzjxwbjvagnsjntskmocmpgkybq", "tuynydoakejmwkvojuwbfltqjfgxq", "psrdswqxqsegulcwrwsjnihxedfcq",
            "cokfdmtsgboidkpgpnmdeyhawkqqs", "fujhvgzdussqbwynylzvtjapvqtid", "rqeuglrsjnmvdsihicsgkybcjltcs",
            "vhybsbmvymjppfrqmlfrbkpjwpyyy", "aukagphzycvjtvwdhhxzagkevvucc", "hwkduzbxpdhtpvrzrfjndmsqfizmq",
            "ywnuzzmxeppokxksrfwrpuzqhjgqr", "qbajmepmmizaycwcgmjeopbivsyph", "uamscbxnqnfmmjyehvidnoimmxmtc",
            "nxvspywfggjrmxryybdltmsfykstm", "amrjbrsiovrxmqsyxhqmritjeauwq", "yorwboxdauhrkxehiwaputeouwxdf",
            "qkewycsdjglkiwaacdqterkixkgra", "ycngvlvpyvczfxvlwhjgicvempfob", "jgphsxzzqlvujkwwgiodbfjesnbsb",
            "mkxhemwbbclwdxwgngicplzgajmar", "mryvkeevlthvflsvognbxfjilwkdn", "mezrxffujeysplvavtjqjxsgujqsj",
            "rtotxqmzxvsqazajvrwsxyeyjteak", "sabctaegttffigupnwgakylngrrxu", "xccuoccdkbboymjtimdrmerspxpkt",
            "xusnnvngksbjabqjaohdvrniezhmx", "oyuejenqgjheulkxjnqkwvzznricl", "mxszcosgovisnbemrjlndqwkvhqso",
            "wsgnznrfmxjbdrkwjopylxezxgvet", "dxmisfskvevpcnujqxrqedleuyowk", "dhrgijeplijcvqbormrqglgmzsprt",
            "vuxchgerokejovrqonxxstibuniki", "lumyzmnzjzhzfpslwsukykwckvkts", "inwkbqmcobubjjpshucechrqrffqs",
            "ywtxruxokcubekzcrqengviwbtgnz", "ccpnmreqaqjrxwulpunagwxesbila", "pesxtpypenunfpjuyoevzztctecil",
            "sygfymdcjgvdxutlrhffhnpyjuxmx", "uisdfrvbxzxzhmuektssuktoknkfb", "cejvgynwouzhtfwuuukdbwpmkjrqx",
            "oudcoagcxjcuqvenznxxnprgvhasf", "sxnlkwgpbznzszyudpwrlgrdgwdyh", "qqbxkaqcyhiobvtqgqruumvvhxolb",
            "mkhleanvfpemuublnnyzfabtxsest", "bibaxwnriowoavosminabvfxastkc", "bcxgixgrhpfiofpwruzvpqyjzvoll",
            "lzccnsztxfyqhqyhkuppapvgvdtkm", "pdjkpshvrmqlhindhabubyokzdfrw", "qbbnhwpdokcpfpxinlfmkfrfqrtzk",
            "rnyelfschnagucguuqqqwitviynry", "qtrjwhrpisocwderqfiqxsdpkphjs", "vxttqosgpplkmxwgmsgtpantazppg",
            "tyisidnhlksfznubucqxwaheamndj", "kgaqzsckonjuhxdhqztjfxstjvikd", "jeuslzsdwvuoodipdpnlhdihaywzm",
            "vdzrwwkqvacxwgdhffyvjldgvchoi", "cftbefxgasawzagfugmuthjahylkh", "xraytcolbhkiiasaazkvqzvfxbaax",
            "oyqtzozufvvlktnvahvsseymtpeyf", "rnnujgyjugrzjoefmghjfhcrnbrtg", "rfzvgvptbgpwajgtysligupoqeoqx",
            "igbdclqtbikiacwpjrbxhmzejozpy", "dyzwwxgdbeqwlldyezmkopktzugxg", "hmetreydbcstkwoexwsfhfekfvfpl",
            "zcnftuzrvzjjudsgcqmmfpnmyrenu", "zzmvkskzeglxaqrrvmrgcwcnvkhwz", "vjswvekfyqhjnsusefdtakejxbejr",
            "rwwzwbcjwiqzkwzfuxfclmsxpdyvf", "fdbdychmupcsxvhazvrihhnxfyumo", "vdtevyducpdksntgyaqtkrrkwiyuh",
            "nbvqeyoghccxfuwacxzxqkezxefxa", "vpgbefpqpsjmdecmixmmbsjxzwvjd", "jwgqmsvhnykclexepxqxqzghwfxfd",
            "olyfxbvdrspxqnxnuoygkruczddgs", "qgmxtdfoiaakorebqpbbpegawrqym", "liaivbhcgvjjnxpggrewglalthmzv",
            "choncklguqgnyrcslwztbstmycjzi", "fpkdpenxlewyxxgrkmwrmshhzfnor", "hhhcaqxbqpthuaafwgrouaxonzocl",
            "ipahojoysepzhpljpaugrghgjimtd", "wosrmnouwpstgbrvhtlqcnmqbygbf", "nwyskffpxlragrnfffawqtgyfpmzx",
            "bcvvadhnssbvneecglnqxhavhvxpk", "hoavxqksjreddpmibbodtbhzfehgl", "lazxadnftllhmjslfbrtdlahkgwle",
            "uuukupjmbbvshzxyniaowdjamlfss", "tpqtazbphmfoluliznftodyguessh", "ychqumiscfkwmqqxunqrfbgqjdwmk",
            "rkdclgzjvqrjofjjvbyfragofeoaz", "pphhedxdepgfgrqerpuhgmaawhnhq", "cacrsvutylalqrykehjuofisdookj",
            "kyldfriuvjranikluqtjjcoiqffdx", "bnwvrwgoskzqkgffpsyhfmxhymqin", "uzmlliugckuljfkljoshjhlvvlnyw",
            "abfxqbdqnexvwsvzvcsbrmkbkuzsd", "xotbbyvxyovzxgtcyzgqnsvcfhczo", "bwtpqcqhvyyssvfknfhxvtodpzipu",
            "nsfbpjqkijvudpriqrfsrdfortimg", "tgwyqugeuahpuvvzmgarbsyuutmbx", "upnwqzbsazplkyaxqorqsshhlljjl",
            "edfyahijobxyhimebctobsjudkqst", "ialhfmgjohzoxvdaxuywfqrgmyahh", "jlhcpegmtrelbosyajljvwwedtxbd",
            "tpfppjzowoltyqijfoabgzejerpat", "mgogyhzpmsdemugqkspsmoppwbnwa", "nubmpwcdqkvhwfuvcahwibniohiqy",
            "ukfadjvdnrievszilfinxbyrvknfi", "dgnepdiimmkcxhattwglbkicvsfsw", "syqxmarjkshjhxobandwyzggjibjg",
            "bnwxjytnaejivivriamhgqsskqhnq", "hzyjdcbyuijjnkqluaczrnrbbwaee", "yscnqoohcsxenypyqhfklloudgmkl",
            "habidqszhxorzfypcjcnopzwigmbz", "wjdqxdrlsqvsxwxpqkljeyjpulbsw", "tytawuuyjrwxboogfessmltwdcssd",
            "pfixglatdvuogdoizdtsgsztsfcih", "apkvhvsqojyixaechvuoemmyqdlfk", "ouaehwnnxwkdplodpuqxdbemfwahp",
            "ixuckaralemvsnbgooorayceuedto", "ymxdjrqikughquwtenyucjdgrmipi", "smrwrlkvpnhqrvpdekmtpdfuxzjwp",
            "bhjakgajafgzxpqckmhdbbnqmcszp", "beqsmluixgsliatukrecgoldmzfhw", "greuevnjssjifvlqlhkllifxrxkdb",
            "yzsqcrdchhdqprtkkjsccowrjtyjj", "sviyovhitxeajqahshpejaqtcdkuv", "qtwomymjskujjtmxiueopwacrwfuq",
            "mzyjtctvtwgyiesxhynvogxnjdjph", "dyfbxcaypyquodcpwxkstbthuvjqg", "hfmflesfabvanxlrurjtigkjotftq",
            "mxydechlraajjmoqpcyoqmrjwoium", "nabesvshjmdbhyhirfrkqkmfwdguj", "bhrfxxemhgbkgmkhjtkzyzdqmxxwq",
            "gziobrjeanlvyukwlscexbkibvdjh", "mcwwubbnwenybmfqglaceuyqnoadz", "xyzvyblypeongzrttvwqzmrccwkzi",
            "ncfalqenfcswgerbfcqsapzdtscnz", "dtqpezboimeuyyujfjxkdmbjpizpq", "wmuhplfueqnvnhukgjarxlxvwmriq",
            "qwapdkoqswyclqyvbvpedzyoyedvu", "uoqbztnftzgahhxwxbgkilnmzfydy", "zsddaahohbszhqxxgripqlwlomjbw",
            "bwadkiavdswyuxdttoqaaykctprkw", "eixdbntdfcaeatyyainfpkclbgaaq", "nmjnpttflsmjifknezrneedvgzfmn",
            "avlzyhfmeasmgrjawongccgfbgoua", "kklimhhjqkmuaifnodtpredhqygme", "xzbwenvteifxuuefnimnadwxhruvo",
            "ugmwlmidtxkvqhbuaecevwhmwkfqm", "rhpyjfxbjjryslfpqoiphrwfjqqha", "eeaipxrokncholathupdetgaktmvm",
            "ltuimrnsphqslmgvmmojawwptghon", "azitvyhvlspvoaeipdsjhgyfjbxhi", "efrelxezcgikdliyhvpocvvpkvagv",
            "znxforctwzecxyrkwufpdxadrgzcz", "kcqgynjcpbylayvgdqfpbqmshksyf", "hrljvedsywrlyccpaowjaqyfaqioe",
            "cjmfyvfybxiuqtkdlzqedjxxbvdsf", "zeqljuypthkmywaffmcjkickqqsuh", "wnfzoyvkiogisdfyjmfomcazigukq",
            "zyaaqxorqxbkenscbveqbaociwmqx", "ahnpivdtlcnptnxjyiaafislqavam", "edtqirqmjtvsfhadhafktyrmkzmvi",
            "wponuefgdtcrgxswiddygeeflpjee", "xozgwhtbhlkvrzismnozqpfthajaf", "ptnfnojnlinbfmylhdlijcvcxzjhd",
            "uxekzlgigjpsukjvsdihrjzgovnre", "rbohxlytsmoeleqrjvievpjipsgdk", "fxtzaxpcfrcovwgrcwqptoekhmgpo",
            "tvxvvgjbyxpgwpganjiaumojpyhhy", "vqjjhfaupylefbvbsbhdncsshmrhx", "urhedneauccrkyjfiptjfxmpxlssr",
            "ltvgknnlodtbhnbhjkmuhwxvzgmkh", "ucztsneqttsuirmjriohhgunzatyf", "rbzryfaeuqkfxrbldyusoeoldpbwa",
            "atlgpnkuksuesrduxkodwjzgubpsm", "lrdniqbzxrbpcvmzpyqklsskpwctg", "qvnvgzkyhistydagsgnujiviyijdn",
            "uzatydzcnktnkeyztoqvogodxxznh", "ocbvphmtpwhcgjbnmxgidtlqcnnwt", "koudovxrjkusxdazxaawmvoostlvv",
            "ptruqmjtbaapgmkfnbwnlvzlxwdpz", "xdxtpbpoemekvxzrrakwjxcxqsdas", "gdpclnsguabtgbfwdmrmbvydorfrb",
            "htwxdbarwuxykgduxjlkxppwyruih" };
        expect_eq<int>::expect_vector_val_eq(exp,
            s.findSubstring("ejwwmybnorgshugzmoxopwuvshlcwasclobxmckcvtxfndeztdqiakfusswqsovdfwatanwxgtctyjvsmlcoxijra"
                "hivwfybbbudosawnfpmomgczirzscqvlaqhfqkithlhbodptvdhjljltckogcjsdbbktotnxgwyuapnxuwgfirbmdrvgapldsvwgq"
                "jfxggtixjhshnzphcemtzsvodygbxpriwqockyavfscvtsewyqpxlnnqnvrkmjtjbjllilinflkbfoxdhocsbpirmcbznuioevcoj"
                "kdqvoraeqdlhffkwqbjsdkfxstdpxryixrdligpzldgtiqryuasxmxwgtcwsvwasngdwovxzafuixmjrobqbbnhwpdokcpfpxinlf"
                "mkfrfqrtzkhabidqszhxorzfypcjcnopzwigmbznmjnpttflsmjifknezrneedvgzfmnhoavxqksjreddpmibbodtbhzfehgluuuk"
                "upjmbbvshzxyniaowdjamlfssndojyyephstlonsplrettspwepipwcjmfyvfybxiuqtkdlzqedjxxbvdsfurhedneauccrkyjfip"
                "tjfxmpxlssrkyldfriuvjranikluqtjjcoiqffdxaukagphzycvjtvwdhhxzagkevvuccxccuoccdkbboymjtimdrmerspxpktsmr"
                "wrlkvpnhqrvpdekmtpdfuxzjwpvqjjhfaupylefbvbsbhdncsshmrhxoyuejenqgjheulkxjnqkwvzznriclrbzryfaeuqkfxrbld"
                "yusoeoldpbwadhrgijeplijcvqbormrqglgmzsprtmryvkeevlthvflsvognbxfjilwkdndyzwwxgdbeqwlldyezmkopktzugxgkk"
                "limhhjqkmuaifnodtpredhqygmedtqpezboimeuyyujfjxkdmbjpizpqltvgknnlodtbhnbhjkmuhwxvzgmkhbcvvadhnssbvneec"
                "glnqxhavhvxpkjxlluilzpysjcnwguyofnhfvhaceztoiscumkhociglkvispihvyoatxcxbeqsmluixgsliatukrecgoldmzfhwk"
                "gaqzsckonjuhxdhqztjfxstjvikdrhpyjfxbjjryslfpqoiphrwfjqqhaamrjbrsiovrxmqsyxhqmritjeauwqbwtpqcqhvyyssvf"
                "knfhxvtodpzipueixdbntdfcaeatyyainfpkclbgaaqrwwzwbcjwiqzkwzfuxfclmsxpdyvfbnwxjytnaejivivriamhgqsskqhnq"
                "eurttrfrmstrbeokzhuzvbfmwywohmgogyhzpmsdemugqkspsmoppwbnwabdmiruibwznqcuczculujfiavzwynsyqxmarjkshjhx"
                "obandwyzggjibjgzyaaqxorqxbkenscbveqbaociwmqxxyzvyblypeongzrttvwqzmrccwkzidyfbxcaypyquodcpwxkstbthuvjq"
                "gialhfmgjohzoxvdaxuywfqrgmyahhtpqtazbphmfoluliznftodyguesshcacrsvutylalqrykehjuofisdookjhrljvedsywrly"
                "ccpaowjaqyfaqioesxnlkwgpbznzszyudpwrlgrdgwdyhucztsneqttsuirmjriohhgunzatyfrfzvgvptbgpwajgtysligupoqeo"
                "qxoyqtzozufvvlktnvahvsseymtpeyfvxttqosgpplkmxwgmsgtpantazppgnubmpwcdqkvhwfuvcahwibniohiqyywnuzzmxeppo"
                "kxksrfwrpuzqhjgqryorwboxdauhrkxehiwaputeouwxdfoudcoagcxjcuqvenznxxnprgvhasffxtzaxpcfrcovwgrcwqptoekhm"
                "gpoywtxruxokcubekzcrqengviwbtgnzvdzrwwkqvacxwgdhffyvjldgvchoiwnfzoyvkiogisdfyjmfomcazigukqlumyzmnzjzh"
                "zfpslwsukykwckvktswjdqxdrlsqvsxwxpqkljeyjpulbswwmuhplfueqnvnhukgjarxlxvwmriqjgmxawmndhsvwnjdjvjtxcsja"
                "pfogpesxtpypenunfpjuyoevzztctecilqqbxkaqcyhiobvtqgqruumvvhxolbyzsqcrdchhdqprtkkjsccowrjtyjjmkhleanvfp"
                "emuublnnyzfabtxsestncfalqenfcswgerbfcqsapzdtscnzugmwlmidtxkvqhbuaecevwhmwkfqmvpgbefpqpsjmdecmixmmbsjx"
                "zwvjdmxydechlraajjmoqpcyoqmrjwoiumuzatydzcnktnkeyztoqvogodxxznhvzduzxudwwqhpftwdspuimioanlzobhjakgaja"
                "fgzxpqckmhdbbnqmcszpuoqbztnftzgahhxwxbgkilnmzfydyxusnnvngksbjabqjaohdvrniezhmxmkxhemwbbclwdxwgngicplz"
                "gajmaryzfkyoqlkrmmfirchzrphveuwmvgaxzbwenvteifxuuefnimnadwxhruvoavlzyhfmeasmgrjawongccgfbgoualiaivbhc"
                "gvjjnxpggrewglalthmzvgziobrjeanlvyukwlscexbkibvdjhdgnepdiimmkcxhattwglbkicvsfswocbvphmtpwhcgjbnmxgidt"
                "lqcnnwtfujhvgzdussqbwynylzvtjapvqtidpdjkpshvrmqlhindhabubyokzdfrwqvnvgzkyhistydagsgnujiviyijdnabfxqbd"
                "qnexvwsvzvcsbrmkbkuzsdehghndyqjodnnblfwmaygdstotfkvxozgwhtbhlkvrzismnozqpfthajafuxekzlgigjpsukjvsdihr"
                "jzgovnreqwapdkoqswyclqyvbvpedzyoyedvuuamscbxnqnfmmjyehvidnoimmxmtcinwkbqmcobubjjpshucechrqrffqsyscnqo"
                "ohcsxenypyqhfklloudgmklcejvgynwouzhtfwuuukdbwpmkjrqxeeaipxrokncholathupdetgaktmvmftqjvzyssocftjwemrog"
                "hrncynmtchhhcaqxbqpthuaafwgrouaxonzocljeuslzsdwvuoodipdpnlhdihaywzmymxdjrqikughquwtenyucjdgrmipiidiwc"
                "lhuepgyynoslhzahtdqwliktzsddaahohbszhqxxgripqlwlomjbwtuynydoakejmwkvojuwbfltqjfgxqhwkduzbxpdhtpvrzrfj"
                "ndmsqfizmqxdxtpbpoemekvxzrrakwjxcxqsdasptruqmjtbaapgmkfnbwnlvzlxwdpzfjryanrmzmpzoefapmnsjdgecrdywsabc"
                "taegttffigupnwgakylngrrxurtotxqmzxvsqazajvrwsxyeyjteakeudzjxwbjvagnsjntskmocmpgkybqbnwvrwgoskzqkgffps"
                "yhfmxhymqinrbohxlytsmoeleqrjvievpjipsgdkrqeuglrsjnmvdsihicsgkybcjltcswolpsfxdypmlbjotuxewskisnmczfgre"
                "uevnjssjifvlqlhkllifxrxkdbjlhcpegmtrelbosyajljvwwedtxbdccpnmreqaqjrxwulpunagwxesbilalrdniqbzxrbpcvmzp"
                "yqklsskpwctgqtrjwhrpisocwderqfiqxsdpkphjsapkvhvsqojyixaechvuoemmyqdlfkuzmlliugckuljfkljoshjhlvvlnywvj"
                "swvekfyqhjnsusefdtakejxbejrchoncklguqgnyrcslwztbstmycjziuskegagtlonducdogwbevugppsptdqbajmepmmizaycwc"
                "gmjeopbivsyphtvxvvgjbyxpgwpganjiaumojpyhhywosrmnouwpstgbrvhtlqcnmqbygbfnabesvshjmdbhyhirfrkqkmfwdgujh"
                "zyjdcbyuijjnkqluaczrnrbbwaeeupnwqzbsazplkyaxqorqsshhlljjlpphhedxdepgfgrqerpuhgmaawhnhqwsgnznrfmxjbdrk"
                "wjopylxezxgvetcvrwdewsxdeumhzfrvoilmvksuhyqltuimrnsphqslmgvmmojawwptghonigbdclqtbikiacwpjrbxhmzejozpy"
                "pfixglatdvuogdoizdtsgsztsfcihtgwyqugeuahpuvvzmgarbsyuutmbxuisdfrvbxzxzhmuektssuktoknkfbmcwwubbnwenybm"
                "fqglaceuyqnoadzfenjcjfdlvcpiatuhjdujhaffqsvqvuxchgerokejovrqonxxstibunikiedfyahijobxyhimebctobsjudkqs"
                "tbcxgixgrhpfiofpwruzvpqyjzvollheoldutddnksutjakhtghpxxnjykxjwgqmsvhnykclexepxqxqzghwfxfdhfmflesfabvan"
                "xlrurjtigkjotftqnwyskffpxlragrnfffawqtgyfpmzxfpkdpenxlewyxxgrkmwrmshhzfnorolyfxbvdrspxqnxnuoygkruczdd"
                "gssygfymdcjgvdxutlrhffhnpyjuxmxefrelxezcgikdliyhvpocvvpkvagvmezrxffujeysplvavtjqjxsgujqsjznxforctwzec"
                "xyrkwufpdxadrgzczrnyelfschnagucguuqqqwitviynrypsrdswqxqsegulcwrwsjnihxedfcqychqumiscfkwmqqxunqrfbgqjd"
                "wmkyelbldxympctbzfupeocwhkypchuyvhybsbmvymjppfrqmlfrbkpjwpyyytytawuuyjrwxboogfessmltwdcssdqtwomymjsku"
                "jjtmxiueopwacrwfuqazitvyhvlspvoaeipdsjhgyfjbxhityisidnhlksfznubucqxwaheamndjxmcxwufajmnveuwuoyosqnoqw"
                "vtjkwuhkzghvmjhawcfszbhzrbpgsidnbmxxihihnrfbamcyojqpkzodbejtmmipahojoysepzhpljpaugrghgjimtdahnpivdtlc"
                "nptnxjyiaafislqavamqgmxtdfoiaakorebqpbbpegawrqymqkewycsdjglkiwaacdqterkixkgraedtqirqmjtvsfhadhafktyrm"
                "kzmvidxmisfskvevpcnujqxrqedleuyowkjgphsxzzqlvujkwwgiodbfjesnbsbzcnftuzrvzjjudsgcqmmfpnmyrenuxotbbyvxy"
                "ovzxgtcyzgqnsvcfhczoptnfnojnlinbfmylhdlijcvcxzjhdixuckaralemvsnbgooorayceuedtomzyjtctvtwgyiesxhynvogx"
                "njdjphcftbefxgasawzagfugmuthjahylkhatlgpnkuksuesrduxkodwjzgubpsmzzmvkskzeglxaqrrvmrgcwcnvkhwzbibaxwnr"
                "iowoavosminabvfxastkcrkdclgzjvqrjofjjvbyfragofeoazzeqljuypthkmywaffmcjkickqqsuhsviyovhitxeajqahshpeja"
                "qtcdkuvgdpclnsguabtgbfwdmrmbvydorfrbcokfdmtsgboidkpgpnmdeyhawkqqshtwxdbarwuxykgduxjlkxppwyruihkcqgynj"
                "cpbylayvgdqfpbqmshksyfbhrfxxemhgbkgmkhjtkzyzdqmxxwqvdtevyducpdksntgyaqtkrrkwiyuhukfadjvdnrievszilfinx"
                "byrvknfihmetreydbcstkwoexwsfhfekfvfplmxszcosgovisnbemrjlndqwkvhqsofdbdychmupcsxvhazvrihhnxfyumonbvqey"
                "oghccxfuwacxzxqkezxefxarnnujgyjugrzjoefmghjfhcrnbrtgouaehwnnxwkdplodpuqxdbemfwahptpfppjzowoltyqijfoab"
                "gzejerpatwponuefgdtcrgxswiddygeeflpjeelzccnsztxfyqhqyhkuppapvgvdtkmxraytcolbhkiiasaazkvqzvfxbaaxkoudo"
                "vxrjkusxdazxaawmvoostlvvnsfbpjqkijvudpriqrfsrdfortimgdhtypunakzituezjyhbrpuksbamuiycngvlvpyvczfxvlwhj"
                "gicvempfobbwadkiavdswyuxdttoqaaykctprkwfmyeodowglzyjzuhencufcwdobydslazxadnftllhmjslfbrtdlahkgwlebdpd"
                "eofidldoymakfnpgekmsltcrrnxvspywfggjrmxryybdltmsfykstmlnzjitaipfoyohkmzimcozxardydxtpjgquoluzbznzqvle"
                "wtqyhryjldjoadgjlyfckzbnbootlzxhupieggntjxilcqxnocpyesnhjbauaxcvmkzusmodlyonoldequfunsbwudquaurogsiyh"
                "ydswsimflrvfwruouskxjfzfynmrymyyqsvkajpnanvyepnzixyteyafnmwnbwmtojdpsucthxtopgpxgnsmnsrdhpskledapiric"
                "vdmtwaifrhnebzuttzckroywranbrvgmashxurelyrrbslxnmzyeowchwpjplrdnjlkfcoqdhheavbnhdlltjpahflwscafnnsspi"
                "kuqszqpcdyfrkaabdigogatgiitadlinfyhgowjuvqlhrniuvrketfmboibttkgakohbmsvhigqztbvrsgxlnjndrqwmcdnntwofo"
                "jpyrhamivfcdcotodwhvtuyyjlthbaxmrvfzxrhvzkydartfqbalxyjilepmemawjfxhzecyqcdswxxmaaxxyifmouauibstgpcfw"
                "gfmjlfhketkeshfcorqirmssfnbuqiqwqfhbmol", words));
    }
}
#endif


TEST(LeetCode, 032) {
	Solution s;
	EXPECT_EQ(0, s.longestValidParentheses(""));
	EXPECT_EQ(0, s.longestValidParentheses("("));
	EXPECT_EQ(0, s.longestValidParentheses(")"));
	EXPECT_EQ(2, s.longestValidParentheses("()"));
	EXPECT_EQ(0, s.longestValidParentheses(")("));
	EXPECT_EQ(0, s.longestValidParentheses("(("));
	EXPECT_EQ(0, s.longestValidParentheses("))"));
	EXPECT_EQ(0, s.longestValidParentheses("((("));
	EXPECT_EQ(2, s.longestValidParentheses("(()"));
	EXPECT_EQ(2, s.longestValidParentheses("()("));
	EXPECT_EQ(2, s.longestValidParentheses("())"));
	EXPECT_EQ(0, s.longestValidParentheses(")(("));
	EXPECT_EQ(2, s.longestValidParentheses(")()"));
	EXPECT_EQ(0, s.longestValidParentheses("))("));
	EXPECT_EQ(0, s.longestValidParentheses(")))"));
	EXPECT_EQ(2, s.longestValidParentheses("(()"));
	EXPECT_EQ(2, s.longestValidParentheses("()(()"));
	EXPECT_EQ(2, s.longestValidParentheses("()(()("));
	EXPECT_EQ(4, s.longestValidParentheses("()())"));
	EXPECT_EQ(2, s.longestValidParentheses("((()"));
	EXPECT_EQ(4, s.longestValidParentheses("((())"));
	EXPECT_EQ(4, s.longestValidParentheses(")()())"));
	EXPECT_EQ(6, s.longestValidParentheses("((()))"));
	EXPECT_EQ(6, s.longestValidParentheses("()(())"));
	EXPECT_EQ(6, s.longestValidParentheses(")()())()()()"));
}


#if 0
TEST(LeetCode, 036) {
    Solution s;
    {
        vector<vector<char>> board = {
            { '8', '3', '.', '.', '7', '.', '.', '.', '.' },
            { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
            { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
            { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
            { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
            { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
            { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
            { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
            { '.', '.', '.', '.', '8', '.', '.', '7', '9' }
        };
        EXPECT_FALSE(s.isValidSudoku(board));
    }
}

TEST(LeetCode, 037) {
    auto const& lambda_print_sudoku = [](vector<vector<char>> const& board)->void {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << board[i][j] << ' ';
            }
            cout << endl;
        }
    };

    Solution s;
    {
        vector<vector<char>> board = {
            { '5', '3', '.', '.', '7', '.', '.', '.', '.' },
            { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
            { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
            { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
            { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
            { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
            { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
            { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
            { '.', '.', '.', '.', '8', '.', '.', '7', '9' }
        };
        vector<vector<char>> const& exp = {
            { '5', '3', '4', '6', '7', '8', '9', '1', '2' },
            { '6', '7', '2', '1', '9', '5', '3', '4', '8' },
            { '1', '9', '8', '3', '4', '2', '5', '6', '7' },
            { '8', '5', '9', '7', '6', '1', '4', '2', '3' },
            { '4', '2', '6', '8', '5', '3', '7', '9', '1' },
            { '7', '1', '3', '9', '2', '4', '8', '5', '6' },
            { '9', '6', '1', '5', '3', '7', '2', '8', '4' },
            { '2', '8', '7', '4', '1', '9', '6', '3', '5' },
            { '3', '4', '5', '2', '8', '6', '1', '7', '9' }
        };
        EXPECT_NO_THROW(s.solveSudoku(board));
        lambda_print_sudoku(board);
        expect_eq<char>::expect_vectors_val_eq(exp, board);
    }
    {
        vector<vector<char>> board = {
            { '.', '.', '9', '7', '4', '8', '.', '.', '.' },
            { '7', '.', '.', '.', '.', '.', '.', '.', '.' },
            { '.', '2', '.', '1', '.', '9', '.', '.', '.' },
            { '.', '.', '7', '.', '.', '.', '2', '4', '.' },
            { '.', '6', '4', '.', '1', '.', '5', '9', '.' },
            { '.', '9', '8', '.', '.', '.', '3', '.', '.' },
            { '.', '.', '.', '8', '.', '3', '.', '2', '.' },
            { '.', '.', '.', '.', '.', '.', '.', '.', '6' },
            { '.', '.', '.', '2', '7', '5', '9', '.', '.' }
        };
        vector<vector<char>> const& exp = {
            { '5', '1', '9', '7', '4', '8', '6', '3', '2' },
            { '7', '8', '3', '6', '5', '2', '4', '1', '9' },
            { '4', '2', '6', '1', '3', '9', '8', '7', '5' },
            { '3', '5', '7', '9', '8', '6', '2', '4', '1' },
            { '2', '6', '4', '3', '1', '7', '5', '9', '8' },
            { '1', '9', '8', '5', '2', '4', '3', '6', '7' },
            { '9', '7', '5', '8', '6', '3', '1', '2', '4' },
            { '8', '3', '2', '4', '9', '1', '7', '5', '6' },
            { '6', '4', '1', '2', '7', '5', '9', '8', '3' }
        };
        EXPECT_NO_THROW(s.solveSudoku(board));
        lambda_print_sudoku(board);
        expect_eq<char>::expect_vectors_val_eq(exp, board);
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

TEST(LeetCode, 98) {
    Solution solution;
    {
        TreeNode* exp = solution.buildTree(vector<int>{ 1, 1 }, vector<int>{ 1, 1 });
        EXPECT_FALSE(solution.isValidBST(exp));
    }
    {
        TreeNode* exp = solution.buildTree(vector<int>{ 3, 1, 2 }, vector<int>{ 1, 2, 3 });
        EXPECT_TRUE(solution.isValidBST(exp));
    }
    {
        TreeNode* exp = solution.buildTree(vector<int>{ 2, 1, 4, 3 }, vector<int>{ 1, 2, 3, 4 });
        EXPECT_TRUE(solution.isValidBST(exp));
    }
    {
        TreeNode* exp = solution.buildTree(vector<int>{ 5, 2, 3, 8, 9 }, vector<int>{ 2, 3, 5, 8, 9 });
        EXPECT_TRUE(solution.isValidBST(exp));
    }
    {
        TreeNode* exp = solution.buildTree(vector<int>{ 5, 2, 3, 8, 9 }, vector<int>{ 2, 3, 5, 8, 9 });
        EXPECT_TRUE(solution.isValidBST(exp));
    }
    {
        TreeNode* exp = solution.buildTree(vector<int>{ 5, 2, 3, 8, 9 }, vector<int>{ 2, 3, 5, 8, 9 });
        EXPECT_TRUE(solution.isValidBST(exp));
    }
    {
        TreeNode* exp = solution.buildTree(vector<int>{ 5, 2, 3, 8, 9 }, vector<int>{ 2, 3, 5, 8, 9 });
        EXPECT_TRUE(solution.isValidBST(exp));
    }
    {
        TreeNode* exp = solution.buildTree(vector<int>{ 5, 2, 3, 8, 9 }, vector<int>{ 2, 3, 5, 8, 9 });
        EXPECT_TRUE(solution.isValidBST(exp));
    }
    {
        TreeNode* exp = solution.buildTree(vector<int>{ 5, 2, 3, 8, 9 }, vector<int>{ 2, 3, 5, 8, 9 });
        EXPECT_TRUE(solution.isValidBST(exp));
    }
    {
        TreeNode* ret = solution.buildTree(vector<int>{ 1, 3, 2 }, vector<int>{ 3, 2, 1 });
        EXPECT_FALSE(solution.isValidBST(ret));
    }
    {
        TreeNode* ret = solution.buildTree(vector<int>{ 3, 1, 4, 2 }, vector<int>{ 1, 3, 2, 4 });
        EXPECT_FALSE(solution.isValidBST(ret));
    }
    {
        TreeNode* ret = solution.buildTree(vector<int>{ 5, 3, 2, 8, 9 }, vector<int>{ 3, 2, 5, 8, 9 });
        EXPECT_FALSE(solution.isValidBST(ret));
    }
    {
        TreeNode* ret = solution.buildTree(vector<int>{ 2, 5, 3, 8, 9 }, vector<int>{ 5, 3, 2, 8, 9 });
        EXPECT_FALSE(solution.isValidBST(ret));
    }
    {
        TreeNode* ret = solution.buildTree(vector<int>{ 5, 8, 3, 2, 9 }, vector<int>{ 8, 3, 5, 2, 9 });
        EXPECT_FALSE(solution.isValidBST(ret));
    }
    {
        TreeNode* ret = solution.buildTree(vector<int>{ 5, 2, 8, 3, 9 }, vector<int>{ 2, 8, 5, 3, 9 });
        EXPECT_FALSE(solution.isValidBST(ret));
    }
    {
        TreeNode* ret = solution.buildTree(vector<int>{ 9, 2, 3, 8, 5 }, vector<int>{ 2, 3, 9, 8, 5 });
        EXPECT_FALSE(solution.isValidBST(ret));
    }
    {
        TreeNode* ret = solution.buildTree(vector<int>{ 5, 9, 3, 8, 2 }, vector<int>{ 9, 3, 5, 8, 2 });
        EXPECT_FALSE(solution.isValidBST(ret));
    }
}

TEST(LeetCode, 99) {
    Solution solution;
    {
        TreeNode* exp = solution.buildTree(vector<int>{ 3, 1, 2 }, vector<int>{ 1, 2, 3 });
        TreeNode* ret = solution.buildTree(vector<int>{ 1, 3, 2 }, vector<int>{ 3, 2, 1 });
        solution.recoverTree(ret);
        EXPECT_TRUE(solution.isSameTree(ret, exp));
    }
    {
        TreeNode* exp = solution.buildTree(vector<int>{ 2, 1, 4, 3 }, vector<int>{ 1, 2, 3, 4 });
        TreeNode* ret = solution.buildTree(vector<int>{ 3, 1, 4, 2 }, vector<int>{ 1, 3, 2, 4 });
        solution.recoverTree(ret);
        EXPECT_TRUE(solution.isSameTree(ret, exp));
    }
    {
        TreeNode* exp = solution.buildTree(vector<int>{ 5, 2, 3, 8, 9 }, vector<int>{ 2, 3, 5, 8, 9 });
        TreeNode* ret = solution.buildTree(vector<int>{ 5, 3, 2, 8, 9 }, vector<int>{ 3, 2, 5, 8, 9 });
        solution.recoverTree(ret);
        EXPECT_TRUE(solution.isSameTree(ret, exp));
    }
    {
        TreeNode* exp = solution.buildTree(vector<int>{ 5, 2, 3, 8, 9 }, vector<int>{ 2, 3, 5, 8, 9 });
        TreeNode* ret = solution.buildTree(vector<int>{ 2, 5, 3, 8, 9 }, vector<int>{ 5, 3, 2, 8, 9 });
        solution.recoverTree(ret);
        EXPECT_TRUE(solution.isSameTree(ret, exp));
    }
    {
        TreeNode* exp = solution.buildTree(vector<int>{ 5, 2, 3, 8, 9 }, vector<int>{ 2, 3, 5, 8, 9 });
        TreeNode* ret = solution.buildTree(vector<int>{ 5, 8, 3, 2, 9 }, vector<int>{ 8, 3, 5, 2, 9 });
        solution.recoverTree(ret);
        EXPECT_TRUE(solution.isSameTree(ret, exp));
    }
    {
        TreeNode* exp = solution.buildTree(vector<int>{ 5, 2, 3, 8, 9 }, vector<int>{ 2, 3, 5, 8, 9 });
        TreeNode* ret = solution.buildTree(vector<int>{ 5, 2, 8, 3, 9 }, vector<int>{ 2, 8, 5, 3, 9 });
        solution.recoverTree(ret);
        EXPECT_TRUE(solution.isSameTree(ret, exp));
    }
    {
        TreeNode* exp = solution.buildTree(vector<int>{ 5, 2, 3, 8, 9 }, vector<int>{ 2, 3, 5, 8, 9 });
        TreeNode* ret = solution.buildTree(vector<int>{ 9, 2, 3, 8, 5 }, vector<int>{ 2, 3, 9, 8, 5 });
        solution.recoverTree(ret);
        EXPECT_TRUE(solution.isSameTree(ret, exp));
    }
    {
        TreeNode* exp = solution.buildTree(vector<int>{ 5, 2, 3, 8, 9 }, vector<int>{ 2, 3, 5, 8, 9 });
        TreeNode* ret = solution.buildTree(vector<int>{ 5, 9, 3, 8, 2 }, vector<int>{ 9, 3, 5, 8, 2 });
        solution.recoverTree(ret);
        EXPECT_TRUE(solution.isSameTree(ret, exp));
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
        TreeNode* exp = solution.buildTree(vector<int>{ 3, 9, 20, 15, 7 }, vector<int>{ 9, 3, 15, 20, 7 });
        TreeNode* ret = solution.buildTree_in_post(vector<int>{ 9, 3, 15, 20, 7 }, vector<int>{ 9, 15, 7, 20, 3 });
        EXPECT_TRUE(solution.isSameTree(ret, exp));
    }
    {
        TreeNode* exp = solution.buildTree(vector<int>{ 2, 3, 9, 8, 5 }, vector<int>{ 9, 3, 8, 2, 5 });
        TreeNode* ret = solution.buildTree_in_post(vector<int>{ 9, 3, 8, 2, 5 }, vector<int>{ 9, 8, 3, 5, 2 });
        EXPECT_TRUE(solution.isSameTree(ret, exp));
    }
    {
        TreeNode* exp = solution.buildTree(vector<int>{ 1, 2, 3 }, vector<int>{ 2, 3, 1 });
        TreeNode* ret = solution.buildTree_in_post(vector<int>{ 2, 3, 1 }, vector<int>{ 3, 2, 1 });
        EXPECT_TRUE(solution.isSameTree(ret, exp));
    }
}


TEST(LeetCode, 107) {
    Solution solution;
    {
        TreeNode* exp = new TreeNode(0);
        exp->left = new TreeNode(-10);
        exp->right = new TreeNode(5);
        exp->left->right = new TreeNode(-3);
        exp->right->right = new TreeNode(9);
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
        TreeNode* t = solution.buildTree(vector<int>{ 5, 4, 11, 7, 2, 8, 13, 4 },
            vector<int>{ 7, 11, 2, 4, 5, 13, 8, 4 });
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

TEST(LeetCode, 113) {
    Solution solution;
    {
        TreeNode* t = solution.buildTree(vector<int>{ 5, 4, 11, 7, 2, 8, 13, 4, 5, 1 },
            vector<int>{ 7, 11, 2, 4, 5, 13, 8, 5, 4, 1 });
        auto const& exp = vector<vector<int>>{ vector<int>{5, 4, 11, 2}, vector<int>{ 5, 8, 4, 5 } };
        auto const& ret = solution.pathSum(t, 22);
        EXPECT_VECTORS_VAL_EQ(exp, ret);
    }
    {
        TreeNode* t = nullptr;
        auto const& exp = vector<vector<int>>{};
        auto const& ret = solution.pathSum(t, 22);
        EXPECT_VECTORS_VAL_EQ(exp, ret);
    }
    {
        TreeNode* t = new TreeNode(1);
        auto const& exp = vector<vector<int>>{};
        auto const& ret = solution.pathSum(t, 22);
        EXPECT_VECTORS_VAL_EQ(exp, ret);
    }
    {
        TreeNode* t = solution.buildTree(vector<int>{ 1, 2 }, vector<int>{ 1, 2 });
        auto const& exp = vector<vector<int>>{};
        auto const& ret = solution.pathSum(t, 22);
        EXPECT_VECTORS_VAL_EQ(exp, ret);
    }
    {
        TreeNode* t = solution.buildTree(vector<int>{ 3, 9, 20, 15, 7 }, vector<int>{ 9, 3, 15, 20, 7 });
        auto const& exp = vector<vector<int>>{};
        auto const& ret = solution.pathSum(t, 22);
        EXPECT_VECTORS_VAL_EQ(exp, ret);
    }
    {
        TreeNode* t = solution.buildTree(vector<int>{ 1, 2, 3, 4, 4, 3, 2 }, vector<int>{ 4, 3, 4, 2, 3, 1, 2 });
        auto const& exp = vector<vector<int>>{};
        auto const& ret = solution.pathSum(t, 22);
        EXPECT_VECTORS_VAL_EQ(exp, ret);
    }
    {
        TreeNode* t = solution.buildTree(vector<int>{ 1, 2, 3, 4, 5 }, vector<int>{ 5, 4, 3, 2, 1 });
        auto const& exp = vector<vector<int>>{};
        auto const& ret = solution.pathSum(t, 22);
        EXPECT_VECTORS_VAL_EQ(exp, ret);
    }
}

TEST(LeetCode, 114) {
    Solution solution;
    {
        TreeNode* t = solution.buildTree(vector<int>{ 1, 2, 3, 4, 5, 6 }, vector<int>{ 3, 2, 4, 1, 5, 6 });
        TreeNode* exp = solution.buildTree(vector<int>{ 1, 2, 3, 4, 5, 6 }, vector<int>{ 1, 2, 3, 4, 5, 6 });
        solution.flatten(t);
        EXPECT_TRUE(solution.isSameTree(exp, t));
    }
    {
        TreeNode* t = solution.buildTree(vector<int>{ 5, 4, 11, 7, 2, 8, 13, 4, 5, 1 },
            vector<int>{ 7, 11, 2, 4, 5, 13, 8, 5, 4, 1 });
        TreeNode* exp = solution.buildTree(vector<int>{ 5, 4, 11, 7, 2, 8, 13, 4, 5, 1 },
            vector<int>{ 5, 4, 11, 7, 2, 8, 13, 4, 5, 1 });
        solution.flatten(t);
        EXPECT_TRUE(solution.isSameTree(exp, t));
    }
    {
        TreeNode* t = nullptr;
        TreeNode* exp = solution.buildTree(vector<int>{}, vector<int>{});
        solution.flatten(t);
        EXPECT_TRUE(solution.isSameTree(exp, t));
    }
    {
        TreeNode* t = new TreeNode(1);
        TreeNode* exp = solution.buildTree(vector<int>{ 1}, vector<int>{1 });
        solution.flatten(t);
        EXPECT_TRUE(solution.isSameTree(exp, t));
    }
    {
        TreeNode* t = solution.buildTree(vector<int>{ 1, 2 }, vector<int>{ 1, 2 });
        TreeNode* exp = solution.buildTree(vector<int>{ 1, 2}, vector<int>{ 1, 2 });
        solution.flatten(t);
        EXPECT_TRUE(solution.isSameTree(exp, t));
    }
    {
        TreeNode* t = solution.buildTree(vector<int>{ 3, 9, 20, 15, 7 }, vector<int>{ 9, 3, 15, 20, 7 });
        TreeNode* exp = solution.buildTree(vector<int>{ 3, 9, 20, 15, 7 }, vector<int>{ 3, 9, 20, 15, 7 });
        solution.flatten(t);
        EXPECT_TRUE(solution.isSameTree(exp, t));
    }
    {
        TreeNode* t = solution.buildTree(vector<int>{ 1, 2, 3, 4, 40, 30, 20 }, vector<int>{ 4, 3, 40, 2, 30, 1, 20 });
        TreeNode* exp = solution.buildTree(vector<int>{ 1, 2, 3, 4, 40, 30, 20 }, vector<int>{1, 2, 3, 4, 40, 30, 20});
        solution.flatten(t);
        EXPECT_TRUE(solution.isSameTree(exp, t));
    }
    {
        TreeNode* t = solution.buildTree(vector<int>{ 1, 2, 3, 4, 5 }, vector<int>{ 5, 4, 3, 2, 1 });
        TreeNode* exp = solution.buildTree(vector<int>{ 1, 2, 3, 4, 5 }, vector<int>{ 1, 2, 3, 4, 5 });
        solution.flatten(t);
        EXPECT_TRUE(solution.isSameTree(exp, t));
    }
}


TEST(LeetCode, 146) {
    LRUCache cache(2);
    {
        EXPECT_NO_THROW(cache.put(1, 1));
        EXPECT_NO_THROW(cache.put(2, 2));
        EXPECT_EQ(1, cache.get(1));
        EXPECT_NO_THROW(cache.put(3, 3));
        EXPECT_EQ(-1, cache.get(2));
        EXPECT_NO_THROW(cache.put(4, 4));
        EXPECT_EQ(-1, cache.get(1));
        EXPECT_EQ(3, cache.get(3));
        EXPECT_EQ(4, cache.get(4));
        EXPECT_NO_THROW(cache.put(4, 5));
        EXPECT_EQ(5, cache.get(4));
    }
}


TEST(LeetCode, 155) {
    MinStack minStack = MinStack();
    {
        EXPECT_NO_THROW(minStack.push(-2));
        EXPECT_NO_THROW(minStack.push(0));
        EXPECT_NO_THROW(minStack.push(-3));
        EXPECT_EQ(-3, minStack.getMin());
        EXPECT_NO_THROW(minStack.pop());
        EXPECT_EQ(0, minStack.top());
        EXPECT_EQ(-2, minStack.getMin());
    }
}


TEST(LeetCode, 208) {
    Trie trie = Trie();
    {
        EXPECT_NO_THROW(trie.insert("apple"));
        EXPECT_TRUE(trie.search("apple"));
        EXPECT_FALSE(trie.search("app"));
        EXPECT_TRUE(trie.startsWith("app"));
        EXPECT_NO_THROW(trie.insert("app"));
        EXPECT_TRUE(trie.search("app"));
    }
}


TEST(LeetCode, 211) {
    WordDictionary wd = WordDictionary();
    {
        EXPECT_NO_THROW(wd.addWord("bad"));
        EXPECT_NO_THROW(wd.addWord("dad"));
        EXPECT_NO_THROW(wd.addWord("mad"));
        EXPECT_FALSE(wd.search("pad"));
        EXPECT_TRUE(wd.search("bad"));
        EXPECT_TRUE(wd.search(".ad"));
        EXPECT_TRUE(wd.search("b.."));
    }
}

TEST(LeetCode, 225) {
    MyStack stack = MyStack();
    {
        EXPECT_NO_THROW(stack.push(1));
        EXPECT_NO_THROW(stack.push(2));
        EXPECT_EQ(2, stack.top());  // 返回 2
        EXPECT_EQ(2, stack.pop());   // 返回 2
        EXPECT_FALSE(stack.empty()); // 返回 false
    }
}


TEST(LeetCode, 232) {
    MyQueue queue = MyQueue();
    {
        EXPECT_NO_THROW(queue.push(1));
        EXPECT_NO_THROW(queue.push(2));
        EXPECT_EQ(1, queue.peek());  // 返回 1
        EXPECT_EQ(1, queue.pop());   // 返回 1
        EXPECT_FALSE(queue.empty()); // 返回 false
    }
}


TEST(LeetCode, 284) {
#if 0
    PeekingIterator piter = PeekingIterator({ 1, 2, 3 });
    EXPECT_EQ(1, piter.next());
    EXPECT_EQ(2, piter.peek());
    EXPECT_EQ(2, piter.next());
    EXPECT_EQ(3, piter.next());
    EXPECT_FALSE(piter.hasNext());
#endif
}


TEST(LeetCode, 295) {
    {
        MedianFinder mfinder = MedianFinder();
        EXPECT_NO_THROW(mfinder.addNum(6));
        EXPECT_EQ(6.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(10));
        EXPECT_EQ(8.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(2));
        EXPECT_EQ(6.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(6));
        EXPECT_EQ(6.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(5));
        EXPECT_EQ(6.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(0));
        EXPECT_EQ(5.5, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(6));
        EXPECT_EQ(6.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(3));
        EXPECT_EQ(5.5, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(1));
        EXPECT_EQ(5.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(0));
        EXPECT_EQ(4.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(0));
        EXPECT_EQ(3.0, mfinder.findMedian());
    }
    {
        MedianFinder mfinder = MedianFinder();
        EXPECT_NO_THROW(mfinder.addNum(12));
        EXPECT_EQ(12.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(10));
        EXPECT_EQ(11.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(13));
        EXPECT_EQ(12.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(11));
        EXPECT_EQ(11.5, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(5));
        EXPECT_EQ(11.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(15));
        EXPECT_EQ(11.5, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(1));
        EXPECT_EQ(11.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(11));
        EXPECT_EQ(11.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(6));
        EXPECT_EQ(11.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(17));
        EXPECT_EQ(11.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(14));
        EXPECT_EQ(11.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(8));
        EXPECT_EQ(11.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(17));
        EXPECT_EQ(11.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(6));
        EXPECT_EQ(11.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(4));
        EXPECT_EQ(11.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(16));
        EXPECT_EQ(11.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(8));
        EXPECT_EQ(11.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(10));
        EXPECT_EQ(10.5, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(2));
        EXPECT_EQ(10.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(12));
        EXPECT_EQ(10.5, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(0));
        EXPECT_EQ(10.0, mfinder.findMedian());
    }
    {
        MedianFinder mfinder = MedianFinder();
        EXPECT_NO_THROW(mfinder.addNum(78));
        EXPECT_EQ(78.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(14));
        EXPECT_EQ(46.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(50));
        EXPECT_EQ(50.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(20));
        EXPECT_EQ(35.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(13));
        EXPECT_EQ(20.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(9));
        EXPECT_EQ(17.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(25));
        EXPECT_EQ(20.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(8));
        EXPECT_EQ(17.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(13));
        EXPECT_EQ(14.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(37));
        EXPECT_EQ(17.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(29));
        EXPECT_EQ(20.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(33));
        EXPECT_EQ(22.5, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(55));
        EXPECT_EQ(25.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(52));
        EXPECT_EQ(27.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(6));
        EXPECT_EQ(25.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(17));
        EXPECT_EQ(22.5, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(65));
        EXPECT_EQ(25.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(23));
        EXPECT_EQ(24.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(74));
        EXPECT_EQ(25.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(43));
        EXPECT_EQ(27.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(5));
        EXPECT_EQ(25.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(29));
        EXPECT_EQ(27.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(29));
        EXPECT_EQ(29.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(72));
        EXPECT_EQ(29.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(7));
        EXPECT_EQ(29.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(13));
        EXPECT_EQ(27.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(56));
        EXPECT_EQ(29.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(21));
        EXPECT_EQ(27.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(31));
        EXPECT_EQ(29.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(66));
        EXPECT_EQ(29.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(69));
        EXPECT_EQ(29.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(69));
        EXPECT_EQ(29.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(74));
        EXPECT_EQ(29.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(12));
        EXPECT_EQ(29.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(77));
        EXPECT_EQ(29.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(23));
        EXPECT_EQ(29.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(10));
        EXPECT_EQ(29.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(6));
        EXPECT_EQ(29.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(27));
        EXPECT_EQ(29.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(63));
        EXPECT_EQ(29.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(77));
        EXPECT_EQ(29.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(21));
        EXPECT_EQ(29.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(40));
        EXPECT_EQ(29.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(10));
        EXPECT_EQ(29.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(19));
        EXPECT_EQ(29.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(59));
        EXPECT_EQ(29.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(35));
        EXPECT_EQ(29.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(40));
        EXPECT_EQ(29.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(44));
        EXPECT_EQ(29.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(4));
        EXPECT_EQ(29.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(15));
        EXPECT_EQ(29.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(29));
        EXPECT_EQ(29.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(63));
        EXPECT_EQ(29.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(27));
        EXPECT_EQ(29.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(46));
        EXPECT_EQ(29.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(56));
        EXPECT_EQ(29.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(0));
        EXPECT_EQ(29.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(60));
        EXPECT_EQ(29.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(72));
        EXPECT_EQ(29.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(35));
        EXPECT_EQ(30.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(54));
        EXPECT_EQ(31.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(50));
        EXPECT_EQ(32.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(14));
        EXPECT_EQ(31.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(29));
        EXPECT_EQ(30.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(62));
        EXPECT_EQ(31.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(24));
        EXPECT_EQ(30.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(18));
        EXPECT_EQ(29.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(79));
        EXPECT_EQ(30.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(16));
        EXPECT_EQ(29.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(19));
        EXPECT_EQ(29.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(8));
        EXPECT_EQ(29.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(77));
        EXPECT_EQ(29.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(10));
        EXPECT_EQ(29.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(21));
        EXPECT_EQ(29.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(66));
        EXPECT_EQ(29.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(42));
        EXPECT_EQ(29.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(76));
        EXPECT_EQ(29.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(14));
        EXPECT_EQ(29.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(58));
        EXPECT_EQ(29.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(20));
        EXPECT_EQ(29.0, mfinder.findMedian());
        EXPECT_EQ(29.0, mfinder.findMedian());
        EXPECT_NO_THROW(mfinder.addNum(0));
    }
}


TEST(LeetCode, HeapDemo) {
    {
        int a[] = { 11, 31, 5, 7, 9 };
        EXPECT_NO_THROW(HeapDemo::buildMaxHeap(a, LENGTH_OF_ARRAY(a)));
        cout << "buildMaxHeap: ";
        for (auto const& pos : a) {
            cout << pos << ',';
        }
        cout << endl;
        EXPECT_EQ(31, a[0]);
    }
    {
        int a[] = { 100, 2, 3, 8, 0, 1, 2, 3, 11, 31, 5, 7, 9 };
        EXPECT_NO_THROW(HeapDemo::buildMaxHeap(a, LENGTH_OF_ARRAY(a)));
        cout << "buildMaxHeap: ";
        for (auto const& pos : a) {
            cout << pos << ',';
        }
        cout << endl;
        EXPECT_EQ(100, a[0]);
    }
    {
        int a[] = { 11, 31, 5, 7, 9 };
        EXPECT_NO_THROW(HeapDemo::buildMinHeap(a, LENGTH_OF_ARRAY(a)));
        cout << "buildMinHeap: ";
        for (auto const& pos : a) {
            cout << pos << ',';
        }
        cout << endl;
        EXPECT_EQ(5, a[0]);
    }
    {
        int a[] = { 100, 2, 3, 8, 0, 1, 2, 3, 11, 31, 5, 7, 9 };
        EXPECT_NO_THROW(HeapDemo::buildMinHeap(a, LENGTH_OF_ARRAY(a)));
        cout << "buildMinHeap: ";
        for (auto const& pos : a) {
            cout << pos << ',';
        }
        cout << endl;
        EXPECT_EQ(0, a[0]);
    }
}


TEST(LeetCode, 215) {
    {
        Solution s;
        vector<int> nums = { 3, 2, 1, 5, 6, 4 };
        EXPECT_EQ(5, s.findKthLargest(nums, 2));
    }
    {
        Solution s;
        vector<int> nums = { 3, 2, 3, 1, 2, 4, 5, 5, 6 };
        EXPECT_EQ(4, s.findKthLargest(nums, 4));
    }
}


TEST(LeetCode, 239) {
    Solution s;
    {
        vector<int> expect = { 3, 3, 5, 5, 6, 7 };
        vector<int> nums = { 1, 3, -1, -3, 5, 3, 6, 7 };
        int k = 3;
        auto const& res = s.maxSlidingWindow(nums, k);
        EXPECT_VECTOR_VAL_EQ(expect, res);
    }
}


TEST(LeetCode, 264) {
    Solution s;
    vector<int> expect = { 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, 16, 18, 20, 24, 25, 27, 30, 32, 36, 40, 45, 48, 50,
        54, 60, 64, 72, 75, 80, 81, 90, 96, 100 };

    for (size_t i = 1; i <= expect.size(); ++i) {
        EXPECT_EQ(expect[i - 1], s.nthUglyNumber(i));
    }
}


TEST(LeetCode, 313) {
    Solution s;
    {
        vector<int> primes = { 2, 3, 5 };
        vector<int> expect = { 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, 16, 18, 20, 24, 25, 27, 30, 32, 36, 40, 45, 48, 50,
            54, 60, 64, 72, 75, 80, 81, 90, 96, 100 };

        for (size_t i = 1; i <= expect.size(); ++i) {
            EXPECT_EQ(expect[i - 1], s.nthSuperUglyNumber(i, primes));
        }
    }
    {
        vector<int> primes = { 2, 7, 13, 19 };
        EXPECT_EQ(32, s.nthSuperUglyNumber(12, primes));
    }
}


TEST(LeetCode, 622) {
    MyCircularQueue cq(3); // 设置长度为 3
    EXPECT_TRUE(cq.enQueue(1));
    EXPECT_TRUE(cq.enQueue(2));
    EXPECT_TRUE(cq.enQueue(3));
    EXPECT_FALSE(cq.enQueue(4));
    EXPECT_EQ(3, cq.Rear());
    EXPECT_TRUE(cq.isFull());
    EXPECT_TRUE(cq.deQueue());
    EXPECT_TRUE(cq.enQueue(4));
    EXPECT_EQ(4, cq.Rear());
}


#endif



