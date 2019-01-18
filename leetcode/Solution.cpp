///    Copyright (C) 2018 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    Leetcode Solution：结题方案
///
///    \author   deguangchow
///    \version  1.0
///    \2019/01/08

#include "stdafx.h"
#include "Solution.h"


//001
vector<int> Solution::twoSum(vector<int>& nums, int target)
{
#if 0//暴力解法
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


//002
ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2)
{
    unsigned sum = 0;//每位之间的数字相加之和
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


//003
int Solution::lengthOfLongestSubstring(string s)
{
#if 0//滑动窗口（初版）
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
#else//滑动窗口（优化版）
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


//004
double Solution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
#if 0//递归实现（未通过全部单元测试）
    auto size1 = nums1.size();
    auto min1 = nums1[0];
    auto max1 = nums1[size1 - 1];

    auto size2 = nums2.size();
    auto min2 = nums2[0];
    auto max2 = nums2[size2 - 1];

    if (max1 <= min2) {
        if (size1>size2) {
            auto pos = (size1 - size2) / 2;
            auto mod = (size1 - size2) % 2;
            if (mod) {
                return nums1[size2 + pos];
            } else {
                return (nums1[size2 + pos] + nums1[size2 + pos + 1]) / 2.0;
            }
        } else if (size1<size2) {
            auto pos = (size2 - size1) / 2;
            auto mod = (size2 - size1) % 2;
            if (mod) {
                return nums2[pos];
            } else {
                return (nums2[pos] + nums2[pos + 1]) / 2.0;
            }
        } else {
            return (max1 + min2) / 2.0;
        }
    } else if (min1 >= max2) {
        return findMedianSortedArrays(nums2, nums1);
    } else {
        auto pos_mid1 = size1 / 2;
        auto mod1 = size1 % 2;
        auto mid1 = nums1[pos_mid1];

        auto pos_mid2 = size2 / 2;
        auto mod2 = size2 % 2;
        auto mid2 = nums2[pos_mid2];

        if (mid1 >= mid2) {
            vector<int> nums1_left;
            nums1_left.insert(nums1_left.end(), nums1.begin(), nums1.begin() + pos_mid1 + mod1);
            vector<int> nums2_right;
            nums2_right.insert(nums2_right.end(), nums2.begin() + pos_mid2 , nums2.end());
            return findMedianSortedArrays(nums1_left, nums2_right);
        } else {
            vector<int> nums1_right;
            nums1_right.insert(nums1_right.end(), nums1.begin() + pos_mid1, nums1.end());
            vector<int> nums2_left;
            nums2_left.insert(nums2_left.end(), nums2.begin(), nums2.begin() + pos_mid2 + mod2);
            return findMedianSortedArrays(nums1_right, nums2_left);
        }
    }
#else//官方题解：递归思想，循环实现
    int m = nums1.size();
    int n = nums2.size();
    if (m>n) {
        nums1.swap(nums2);
        m = n;
        n = nums2.size();
    }
    int iMin = 0, iMax = m, halfLen = (m + n + 1) / 2;
    while (iMin<=iMax) {
        int i = (iMin + iMax) / 2;
        int j = halfLen - i;
        if (i<iMax && nums2[j - 1]>nums1[i]) {
            iMin = i + 1;//i is too small
        } else if (i>iMin && nums1[i-1] > nums2[j]) {
            iMax = i - 1;//i is too big
        } else {//i is perfect
            int maxLeft = 0;
            if (i == 0) {
                maxLeft = nums2[j - 1];
            } else if (j == 0) {
                maxLeft = nums1[i - 1];
            } else {
                maxLeft = std::max(nums1[i - 1], nums2[j - 1]);
            }
            if ((m + n) % 2 == 1) {
                return maxLeft;
            }

            int minRight = 0;
            if (i == m) {
                minRight = nums2[j];
            } else if (j == n) {
                minRight = nums1[i];
            } else {
                minRight = std::min(nums2[j], nums1[i]);
            }

            return (maxLeft + minRight) / 2.0;
        }
    }
    return 0.0;
#endif
}


//019
ListNode* Solution::removeNthFromEnd(ListNode* head, int n)
{
    ListNode* p_n = head;
    ListNode* p_end = head;
    for (auto i = 0; i < n; ++i) {
        p_end = p_end->next;
    }
    if (nullptr == p_end) {
        return head->next;
    }

    //多移动1个位置
    p_end = p_end->next;

    while (p_end) {
        p_n = p_n->next;
        p_end = p_end->next;
    }
    p_end = p_n->next;
    p_n->next = p_end->next;

    return head;
}


//021
ListNode* Solution::mergeTwoLists(ListNode* l1, ListNode* l2)
{
    ListNode* ret = nullptr;
    ListNode* p = nullptr;
    while (l1 && l2) {
        if (l1->val <= l2->val) {
            if (nullptr == p) {
                ret = l1;
                p = l1;
            } else {
                p->next = l1;
                p = p->next;
            }
            l1 = l1->next;
        } else {
            if (nullptr == p) {
                ret = l2;
                p = l2;
            } else {
                p->next = l2;
                p = p->next;
            }
            l2 = l2->next;
        }
    }

    if (p) {
        if (l1) {
            p->next = l1;
        }
        if (l2) {
            p->next = l2;
        }
    } else {
        if (l1) {
            ret = l1;
        } else {
            ret = l2;
        }
    }

    return ret;
}


//023
ListNode* Solution::mergeKLists(vector<ListNode*>& lists)
{
#if 1//023.1：复用021解题思路，多次调用接口mergeTwoLists
    auto const& size = lists.size();
    ListNode* ret = nullptr;
    for (auto i = 0; i < size; ++i) {
        ret = mergeTwoLists(ret, lists[i]);
    }
    return ret;
#else//023.2：mergeTwoLists的衍生，一次比较n个数（未实现，但是复杂度应等同023.1）
    ListNode* ret = nullptr;
    ListNode* p = nullptr;
    auto const& size = lists.size();
    auto count_nil = 0;
    while (true) {
        bool flag_break = false;
        for (auto i = 0; i < size; ++i) {
            if (nullptr == lists[i]) {
                ++count_nil;
                continue;
            }
            p = lists[i];
        }
        if (flag_break) {
            break;
        }
    }
    return ret;
#endif
}


//024
ListNode* Solution::swapPairs(ListNode* head)
{
    ListNode* dummy = new ListNode(-1);//新增一个哑结点，哑结点的next指向head
    dummy->next = head;

    ListNode* p0 = dummy;
    ListNode* p1 = head;
    ListNode* p2 = nullptr;
    while (p1 && p1->next) {
        p2 = p1->next;
        p1->next = p2->next;
        p2->next = p1;
        p0->next = p2;
        p0 = p1;
        p1 = p1->next;
    }

    return dummy->next;//哑结点的next即返回的结果
}


//025
ListNode* Solution::reverseKGroup(ListNode* head, int k)
{
    ListNode* dummy = new ListNode(-1);//新增一个哑结点，哑结点的next指向head
    dummy->next = head;

    ListNode* p0 = dummy;
    ListNode* p0_new = nullptr;
    ListNode* p1 = head;
    ListNode* p2 = nullptr;
    ListNode* p = nullptr;//节点校验指针
    while (p0) {
        p = p0;
        for (int i = 0; i < k; ++i) {
            p = p->next;
            if (!p) {
                break;
            }
        }
        if (!p) {//剩余节点不够k个，不够一组则不做翻转
            break;
        }
        p1 = p0->next;
        p2 = p1->next;
        for (int i = 0; i < k - 1; ++i) {
            if (i % 2 == 0) {
                p1->next = p2->next;
                p2->next = p0->next;
                p0->next = p2;
                p0_new = p1;
                p1 = p1->next;
                while (p2->next != p1) {
                    p2 = p2->next;
                }
            } else {
                p2->next = p1->next;
                p1->next = p0->next;
                p0->next = p1;
                p0_new = p2;
                p2 = p2->next;
                while (p1->next != p2) {
                    p1 = p1->next;
                }
            }
        }
        p0 = p0_new;
    }

    return dummy->next;//哑结点的next即返回的结果
}

ListNode* Solution::rotateRight(ListNode* head, int k)
{
    if (nullptr == head || nullptr == head->next) {
        return head;
    }

    ListNode* p1 = head;
    ListNode* p2 = head;
    int count = 1;
    while (p2->next) {
        ++count;
        p2 = p2->next;
    }
    p2->next = head;//建环

    int n = count - (k%count);
    for (int i = 0; i < n - 1; ++i) {
        p1 = p1->next;
    }

    ListNode* ret = p1->next;
    p1->next = nullptr;//解环

    return ret;
}

//082
ListNode* Solution::deleteDuplicates(ListNode* head)
{
    if (nullptr == head || nullptr == head->next) {
        return head;
    }
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode*p0 = dummy;
    ListNode*p1 = head;
    ListNode*p2 = head->next;
    while (p1 && p2) {
        if (p1->val == p2->val) {
            p2 = p2->next;
        } else {
            if (p1->next == p2) {
                p0 = p1;
                p1 = p1->next;
                p2 = p2->next;
            }
            else {
                p0->next = p2;
                p1 = p2;
                p2 = p2->next;
            }
        }
    }
    if (p1->next != p2) {
        p0->next = nullptr == p2 ? nullptr : p2->next;
    }
    return dummy->next;
}

//083
ListNode* Solution::deleteDuplicatesOne(ListNode* head)
{
    if (nullptr == head || nullptr == head->next) {
        return head;
    }
    ListNode* p1 = head;
    ListNode* p2 = p1->next;
    while (p1 && p2) {
        if (p1->val == p2->val) {
            p2 = p2->next;
        } else {
            if (p1->next != p2) {
                p1->next = p2;
            }
            p1 = p1->next;
            p2 = p1->next;
        }
    }
    if (p1->next != p2) {
        p1->next = nullptr == p2 ? nullptr : p2->next;
    }
    return head;
}

//086
ListNode* Solution::partition(ListNode* head, int x)
{
    if (nullptr == head || nullptr == head->next) {
        return head;
    }
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode* p0 = dummy;
    ListNode* p1 = head;
    ListNode* p2 = nullptr;
    while (p1) {
        if (nullptr == p2 && p1->val == x) {
            p2 = p1;
        }
        if (p2 && p1->val < x) {
            p0->next = p1->next;
            p1->next = dummy->next;
            dummy->next = p1;
            p1 = p0->next;
        }
        else {
            p0 = p1;
            p1 = p1->next;
        }
    }
    return dummy->next;
}

//092
ListNode* Solution::reverseBetween(ListNode* head, int m, int n)
{
    if (nullptr == head || nullptr == head->next) {
        return head;
    }
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode* p0 = dummy;
    ListNode* p1 = head;        //第m个节点
    ListNode* p2 = head->next;  //第n个节点

    //1、确定位置m
    for (auto i = 0; i < m - 1; ++i) {
        p0 = p0->next;
    }
    p1 = p0->next;

    //2、确定位置n
    p2 = p1;
    int len = (n - m);
    for (auto i = 0; i < len; ++i) {
        p2 = p2->next;
    }
    
    //3、反转从m到n的节点
    for (auto i = 0; i < len; ++i) {
        p0->next = p1->next;
        p1->next = p2->next;
        p2->next = p1;
        p1 = p0->next;
    }
    return dummy->next;
}

//100
bool Solution::isSameTree(TreeNode* p, TreeNode* q)
{
    if (!p && !q) {
        return true;
    }
    if (!p || !q || p->val != q->val) {
        return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);//递归比较两棵树的左、右子树
}


//101
bool Solution::isMirror(TreeNode* t1, TreeNode *t2)
{
    if (!t1 && !t2) {
        return true;
    }
    if (!t1 || !t2 || t1->val != t2->val) {
        return false;
    }
    return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
}
bool Solution::isSymmetric(TreeNode* root)
{
    return isMirror(root, root);
}


//102
vector<vector<int>> Solution::levelOrder(TreeNode* root)
{
    if (!root) {
        return{};
    }

    vector<vector<int>> ret;
    TreeNode *p = root;
    queue<TreeNode*> nodes;
    nodes.push(p);
    int count = 1;
    int count_next = 0;

    while (!nodes.empty()) {
        vector<int> nodes_level;
        for (int i = 0; i < count; ++i) {
            p = nodes.front();
            if (p->left) {
                nodes.push(p->left);
                ++count_next;
            }
            if (p->right) {
                nodes.push(p->right);
                ++count_next;
            }
            nodes.pop();
            nodes_level.push_back(p->val);
        }

        count = count_next;
        count_next = 0;
        ret.push_back(nodes_level);
    }

    return ret;
}


//109
TreeNode* Solution::sortedListToBST(ListNode* head)
{
    if (nullptr == head) {
        return nullptr;
    }
    TreeNode* ret = new TreeNode(head->val);
    ListNode* p1 = head->next;
    TreeNode* p2 = ret;
    while (p1) {
        if (ret->val >= p1->val) {
            if (ret->left && ret->left->val >= p1->val) {

            }
            else {
                ret->left = new TreeNode(p1->val);
                p1 = p1->next;
            }
        }
    }
}

