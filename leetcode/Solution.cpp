///    Copyright (C) 2018 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    Leetcode Solution�����ⷽ��
///
///    \author   deguangchow
///    \version  1.0
///    \2019/01/08

#include "stdafx.h"
#include "Solution.h"


vector<int> Solution::twoSum(vector<int>& nums, int target)
{
#if 0//�����ⷨ
    unsigned len = nums.size();
    for (int i = 0; i < len - 1; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (target == nums[i] + nums[j]) {
                return{ i, j };
            }
        }
    }
    return{ -1,-1 };
#else//map
    unsigned const& len = nums.size();
    map<int, int> mapNumIndex;
    for (int i = 0; i < len; ++i) {
        int const& num = nums[i];
        if (mapNumIndex.find(num) == mapNumIndex.end()) {
            mapNumIndex[num] = i;
        }
        auto const& pos = mapNumIndex.find(target - num);
        if (pos == mapNumIndex.end()) {
            continue;
        }
        if (pos->second == i) {
            continue;
        }
        return{ i, pos->second };
    }
    return{ -1,-1 };
#endif
}

Solution::ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2)
{
    unsigned sum = 0;//ÿλ֮����������֮��
    ListNode* ret = l1;
    ListNode* p = nullptr;
    while (l1 && l2) {
        p = l1;
        sum += l1->val + l2->val;
        l1->val = sum % 10;
        sum = sum / 10;
        l1 = l1->next;
        l2 = l2->next;
    }
    if (l1) {
        p->next = l1;
        while (l1) {
            p = l1;
            sum += l1->val;
            l1->val = sum % 10;
            sum = sum / 10;
            l1 = l1->next;
        }
    }
    if (l2) {
        p->next = l2;
        while (l2) {
            p = l2;
            sum += l2->val;
            l2->val = sum % 10;
            sum = sum / 10;
            l2 = l2->next;
        }
    }
    if (sum) {
        p->next = new ListNode(sum);
    }

    return ret;
}

int Solution::lengthOfLongestSubstring(string s)
{
#if 0//�������ڣ����棩
    unsigned size = s.length();
    int max = 0;
    int len = 0;
    char* p = &s[0];
    map<char, unsigned> mapCharIndex;
    for (auto i = 0; i < size; ++i) {
        char & c = s[i];
        auto const& pos = mapCharIndex.find(s[i]);
        if (pos == mapCharIndex.end()) {
            mapCharIndex[c] = i;
        }
        len = mapCharIndex.size();
        if (len > max) {
            max = len;
        }
        if (pos == mapCharIndex.end()) {
            continue;
        }
        char* end = &s[pos->second];
        ++end;
        while (p && (p != end)) {
            mapCharIndex.erase(*p);
            ++p;
        }
        mapCharIndex[c] = i;
    }

    return max;
#else//�������ڣ��Ż��棩
    int n = s.length();
    int ans = 0;
    map<char, int> mapCharIndex;
    for (auto j = 0, i = 0; j < n; ++j) {
        auto const& pos = mapCharIndex.find(s[j]);
        if (pos != mapCharIndex.end()) {
            i = std::max(i, pos->second);
        }
        ans = std::max(ans, j - i + 1);
        mapCharIndex[s[j]] = j + 1;
    }

    return ans;
#endif
}

double Solution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    double ret = 0.0;
    auto size1 = nums1.size();
    auto size2 = nums2.size();

    nums1[size1 / 2];
    nums2[size2 / 2];

    return ret;

}
