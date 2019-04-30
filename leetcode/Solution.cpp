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
vector<int> Solution::twoSum(vector<int>& nums, int target) {
#if 0//暴力解法
    unsigned len = nums.size();
    for (int i = 0; i < len - 1; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (target == nums[i] + nums[j]) {
                return{ i, j };
            }
        }
    }
    return{ -1, -1 };
#else//map
    int const& len = nums.size();
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
    return{ -1, -1 };
#endif
}


//002
ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
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
int Solution::lengthOfLongestSubstring(string s) {
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
double Solution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
#if 0//递归实现（未通过全部单元测试）
    auto size1 = nums1.size();
    auto min1 = nums1[0];
    auto max1 = nums1[size1 - 1];

    auto size2 = nums2.size();
    auto min2 = nums2[0];
    auto max2 = nums2[size2 - 1];

    if (max1 <= min2) {
        if (size1 > size2) {
            auto pos = (size1 - size2) / 2;
            auto mod = (size1 - size2) % 2;
            if (mod) {
                return nums1[size2 + pos];
            } else {
                return (nums1[size2 + pos] + nums1[size2 + pos + 1]) / 2.0;
            }
        } else if (size1 < size2) {
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
    if (m > n) {
        nums1.swap(nums2);
        m = n;
        n = nums2.size();
    }
    int iMin = 0, iMax = m, halfLen = (m + n + 1) / 2;
    while (iMin <= iMax) {
        int i = (iMin + iMax) / 2;
        int j = halfLen - i;
        if (i<iMax && nums2[j - 1]>nums1[i]) {
            iMin = i + 1;//i is too small
        } else if (i > iMin && nums1[i-1] > nums2[j]) {
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
ListNode* Solution::removeNthFromEnd(ListNode* head, int n) {
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
ListNode* Solution::mergeTwoLists(ListNode* l1, ListNode* l2) {
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
ListNode* Solution::mergeKLists(vector<ListNode*>& lists) {
#if 1//023.1：复用021解题思路，多次调用接口mergeTwoLists
    auto const& size = lists.size();
    ListNode* ret = nullptr;
    for (unsigned i = 0; i < size; ++i) {
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
ListNode* Solution::swapPairs(ListNode* head) {
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
ListNode* Solution::reverseKGroup(ListNode* head, int k) {
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

ListNode* Solution::rotateRight(ListNode* head, int k) {
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
ListNode* Solution::deleteDuplicates(ListNode* head) {
    if (nullptr == head || nullptr == head->next) {
        return head;
    }
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode*p0 = dummy;
    ListNode*p1 = head;
    ListNode*p2 = head->next;
    while (p2) {
        if (p1->val == p2->val) {
            p2 = p2->next;
        } else {
            if (p1->next == p2) {
                p0 = p1;
                p1 = p1->next;
                p2 = p2->next;
            } else {
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
ListNode* Solution::deleteDuplicatesOne(ListNode* head) {
    if (nullptr == head || nullptr == head->next) {
        return head;
    }
    ListNode* p1 = head;
    ListNode* p2 = p1->next;
    while (p2) {
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
ListNode* Solution::partition(ListNode* head, int x) {
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
        } else {
            p0 = p1;
            p1 = p1->next;
        }
    }
    return dummy->next;
}

//092
ListNode* Solution::reverseBetween(ListNode* head, int m, int n) {
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

//94
void Solution::inOder(TreeNode* root, vector<int>& ans) {
    if (!root) {
        return;
    }
    inOder(root->left, ans);
    ans.push_back(root->val);
    inOder(root->right, ans);
}
vector<int> Solution::inorderTraversal(TreeNode* root) {
    vector<int> ans;
#if 0//递归法
    inOder(root, ans);
#else//迭代法：辅助栈
    stack<TreeNode*> st;
    while (!st.empty() || root) {
        if (root) {
            st.push(root);
            root = root->left;
        } else {
            root = st.top();
            st.pop();
            ans.push_back(root->val);
            root = root->right;
        }
    }
#endif
    return ans;
}

//95
vector<TreeNode*>* Solution::createBST(int begin, int end) {
    vector<TreeNode*>* ans = new vector<TreeNode*>();
    if (begin > end) {
        ans->push_back(nullptr);
    } else {
        for (int i = begin; i <= end; ++i) {
            vector<TreeNode*>* left = createBST(begin, i - 1);
            vector<TreeNode*>* right = createBST(i + 1, end);
            for (int l = 0; l < left->size(); ++l) {
                for (int r = 0; r < right->size(); ++r) {//构建二叉查找树
                    TreeNode* node = new TreeNode(i);//不同的根结点
                    node->left = (*left)[l];
                    node->right = (*right)[r];
                    ans->push_back(node);
                }
            }
        }
    }
    return ans;
}
vector<TreeNode*> Solution::generateTrees(int n) {
    return *createBST(1, n);
}

//96
int Solution::numTrees(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            dp[i] += (dp[j] * dp[i - 1 - j]);
        }
    }

    return dp[n];
}

//98
void Solution::inOderIsValidBST(TreeNode* root) {
    if (!root || !is_valid_BST) {
        return;
    }
    inOderIsValidBST(root->left);
    if (last && last->val >= root->val) {
        is_valid_BST = false;
    }
    last = root;
    inOderIsValidBST(root->right);
}
bool Solution::isValidBST(TreeNode* root) {
    //初始化
    last = nullptr;
    is_valid_BST = true;

    //中序遍历
    inOderIsValidBST(root);

    //返回结果
    return is_valid_BST;
}


//99
void Solution::inOderRecoverTree(TreeNode* root) {
    if (!root || p1 && p3) {
        return;
    }
    inOderRecoverTree(root->left);
    if (last && last->val > root->val) {
        if (!p1) {
            p1 = last;
            p2 = root;
        } else {
            p3 = last;
            p4 = root;
        }
    }
    last = root;
    inOderRecoverTree(root->right);
}
void Solution::recoverTree(TreeNode* root) {
    //初始化
    p1 = p2 = p3 = p4 = last = nullptr;

    //中序遍历
    inOderRecoverTree(root);

    //交换节点值
    TreeNode* t1 = p1;
    TreeNode* t2 = !p3 ? p2 : p4;
    swap(t1->val, t2->val);
}

//100
bool Solution::isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) {
        return true;
    }
    if (!p || !q || p->val != q->val) {
        return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);//递归比较两棵树的左、右子树
}


//101
bool Solution::isMirror(TreeNode* t1, TreeNode *t2) {
    if (!t1 && !t2) {
        return true;
    }
    if (!t1 || !t2 || t1->val != t2->val) {
        return false;
    }
    return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
}
bool Solution::isSymmetric(TreeNode* root) {
    return isMirror(root, root);
}


//102
vector<vector<int>> Solution::levelOrder(TreeNode* root) {
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


//103
vector<vector<int>> Solution::zigzagLevelOrder(TreeNode* root) {
    if (!root) {
        return{};
    }

    vector<vector<int>> ret;
    unsigned count = 1;
    unsigned count_next = 0;
    queue<TreeNode*> nodes;
    nodes.push(root);
    bool left2right = true;//从左到右的标识

    while (!nodes.empty()) {
        vector<int> nodes_level;
        for (unsigned i = 0; i < count; ++i) {
            TreeNode* p = nodes.front();
            if (p->left) {
                nodes.push(p->left);
                ++count_next;
            }
            if (p->right) {
                nodes.push(p->right);
                ++count_next;
            }
            nodes.pop();
            if (left2right) {
                nodes_level.push_back(p->val);
            } else {
                nodes_level.insert(nodes_level.begin(), p->val);
            }
        }
        count = count_next;
        count_next = 0;
        left2right = !left2right;
        ret.push_back(nodes_level);
    }
    return move(ret);
}


//104
int Solution::maxDepth(TreeNode* root) {
#if 0//迭代法：辅助队列
    if (!root) {
        return 0;
    }
    unsigned depth = 0;
    unsigned count = 1;
    unsigned count_next = 0;
    queue<TreeNode*> nodes;
    nodes.push(root);
    while (!nodes.empty()) {
        for (unsigned i = 0; i < count; ++i) {
            TreeNode* p = nodes.front();
            if (p->left || p->right) {
                if (p->left) {
                    nodes.push(p->left);
                    ++count_next;
                }
                if (p->right) {
                    ++count_next;
                    nodes.push(p->right);
                }
            }
            nodes.pop();
        }
        ++depth;
        count = count_next;
        count_next = 0;
    }
    return depth;
#else//递归法
    return !root ? 0 : 1 + std::max(maxDepth(root->left), maxDepth(root->right));
#endif
}


//105
TreeNode* Solution::build(vector<int>::const_iterator pre1, vector<int>::const_iterator pre2,
    vector<int>::const_iterator in1, vector<int>::const_iterator in2) {
    if (pre1 > pre2 || in1 > in2) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(*pre1);
    auto const& pos = std::find(in1, in2, root->val);
    root->left = build(pre1 + 1, pre2, in1, pos - 1);
    root->right = build(pre1 + (pos - in1) + 1, pre2, pos + 1, in2);
    return root;
}
TreeNode* Solution::buildTree(vector<int>& preorder, vector<int>& inorder) {
#if 0//递归法
    if (preorder.empty() || inorder.empty()) {
        return nullptr;
    }
    return build(preorder.begin(), preorder.end() - 1, inorder.begin(), inorder.end() - 1);
#else//迭代法：使用辅助栈
    unsigned const& size = preorder.size();
    if (size == 0) {
        return nullptr;
    }
    unsigned pre_index = 0, in_index = 0;
    TreeNode* root = new TreeNode(preorder[pre_index++]);
    TreeNode* cur = root;
    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        //创建左子树：压栈
        while (st.top()->val != inorder[in_index]) {
            st.top()->left = new TreeNode(preorder[pre_index++]);
            st.push(st.top()->left);
        }
        //定位当前右子树所在的跟节点：出栈
        while (!st.empty() && st.top()->val == inorder[in_index]) {
            cur = st.top();
            st.pop();
            ++in_index;
        }
        //创建右子树：压栈
        if (pre_index < size) {
            cur->right = new TreeNode(preorder[pre_index++]);
            cur = cur->right;
            st.push(cur);
        }
    }

    return root;
#endif
}


//106
TreeNode* Solution::buildTree_in_post(vector<int>& inorder, vector<int>& postorder) {
    unsigned const& size = postorder.size();
    if (size == 0) {
        return nullptr;
    }
    unsigned post_index = size, in_index = size - 1;
    TreeNode* root = new TreeNode(postorder[--post_index]);
    TreeNode* cur = root;
    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        //创建右子树：压栈
        while (st.top()->val != inorder[in_index]) {
            st.top()->right = new TreeNode(postorder[--post_index]);
            st.push(st.top()->right);
        }
        //定位当前左子树所在的跟节点：出栈
        while (!st.empty() && st.top()->val == inorder[in_index]) {
            cur = st.top();
            st.pop();
            --in_index;
        }
        //创建左子树：压栈
        if (post_index > 0) {
            cur->left = new TreeNode(postorder[--post_index]);
            cur = cur->left;
            st.push(cur);
        }
    }

    return root;
}


//107
vector<vector<int>> Solution::levelOrderBottom(TreeNode* root) {
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
        ret.insert(ret.begin(), nodes_level);
    }

    return ret;
}


//108
TreeNode* Solution::sortedArrayToBST(vector<int>& nums, int const& begin, int const& end) {
    if (begin > end) {
        return nullptr;
    }
    unsigned mid = (begin + end) / 2;
    TreeNode* t = new TreeNode(nums[mid]);
    t->left = sortedArrayToBST(nums, begin, mid - 1);
    t->right = sortedArrayToBST(nums, mid + 1, end);
    return t;
}
TreeNode* Solution::sortedArrayToBST(vector<int>& nums) {
    unsigned const& size = nums.size();
    if (0 == size) {
        return nullptr;
    }
    return sortedArrayToBST(nums, 0, size - 1);
}


//109
TreeNode* Solution::sortedListToBST(ListNode* head, ListNode* tail) {
    if (head == tail) {
        return nullptr;
    }

    //快慢指针，查找链表的中间点位置
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast != tail && fast->next != tail) {
        fast = fast->next->next;
        slow = slow->next;
    }

    TreeNode* root = new TreeNode(slow->val);
    root->left = sortedListToBST(head, slow);
    root->right = sortedListToBST(slow->next, tail);
    return root;
}
TreeNode* Solution::sortedListToBST(ListNode* head) {
    if (!head) {
        return nullptr;
    }
    return sortedListToBST(head, nullptr);
}


//110
bool Solution::isBalanced(TreeNode* root) {
    //递归法：双递归
    if (!root || !root->left && !root->right) {
        return true;
    }
    if (abs(maxDepth(root->left) - maxDepth(root->right)) > 1) {
        return false;//比较子树是否平衡
    }
    return isBalanced(root->left) && isBalanced(root->right);
}


//111
int Solution::minDepth(TreeNode* root) {
    if (!root) {
        return 0;
    }
    int left = minDepth(root->left);
    int right = minDepth(root->right);
    return (left && right) ? 1 + std::min(left, right) : 1 + left + right;
}


//112
bool Solution::hasPathSum(TreeNode* root, int sum) {
    if (!root) {
        return false;
    }
    if (!root->left && !root->right) {
        return sum == root->val;
    }
    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}


//113
void Solution::dfsPathSum(vector<vector<int>>& res, vector<int>& path, TreeNode* root, int sum) {
    if (!root) {
        return;
    }
    path.push_back(root->val);
    if (!root->left && !root->right && root->val == sum) {
        res.push_back(path);
    }
    dfsPathSum(res, path, root->left, sum - root->val);
    dfsPathSum(res, path, root->right, sum - root->val);
    path.pop_back();
}
vector<vector<int>> Solution::pathSum(TreeNode* root, int sum) {
    vector<vector<int>> res;
    vector<int> path;
    dfsPathSum(res, path, root, sum);
    return res;
}


//114
void Solution::postOrder(TreeNode* root) {
    if (!root) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    TreeNode* r = root->right;
    root->right = root->left;
    root->left = nullptr;
    while (root->right) {
        root = root->right;
    }
    root->right = r;
}
void Solution::flatten(TreeNode* root) {
#if 0//迭代法：辅助栈
    if (!root) {
        return;
    }
    stack<TreeNode*> st;
    st.push(root);
    TreeNode* cur = root;

    while (!st.empty()) {
        while (!st.empty() && st.top()->left) {
            st.push(st.top()->left);
        }
        cur = st.top();
        while (!st.empty() && !st.top()->right) {
            st.pop();
        }
        if (!st.empty()) {
            cur->left = st.top()->right;
            st.top()->right = nullptr;
            st.push(cur->left);
        }
    }
    cur = root;
    while (cur) {
        cur->right = cur->left;
        cur->left = nullptr;
        cur = cur->right;
    }
#else//递归法：后续遍历
    postOrder(root);
#endif
}


//116
void do_connect(Node *root) {
    if (nullptr == root) {
        return;
    }

    //如果是叶子结点
    if (nullptr == root->right && nullptr == root->left) {
        return;
    }

    root->left->next = root->right;
    if (nullptr != root->next) {
        root->right->next = root->next->left;
    } else {
        root->right->next = nullptr;
    }

    do_connect(root->left);
    do_connect(root->right);
}
Node* Solution::connect(Node* root) {
    do_connect(root);
    return root;
}


//117
void do_connect2(Node *root) {
    if (nullptr == root) {
        return;
    }

    //如果是叶子结点
    if (nullptr == root->right && nullptr == root->left) {
        return;
    }

    //设置左节点的next
    if (root->left && root->right) {
        root->left->next = root->right;
    } else if (root->left) {
        Node* next_tmp = root->next;
        while (next_tmp) {
            if (nullptr != next_tmp->left) {
                root->left->next = next_tmp->left;
                break;
            } else if (nullptr != next_tmp->right) {
                root->left->next = next_tmp->right;
                break;
            } else {
                next_tmp = next_tmp->next;
            }
        }
        if (nullptr == next_tmp) {
            root->left->next = nullptr;
        }
    }

    //设置右节点的next
    if (root->right) {
        Node* next_tmp = root->next;
        while (next_tmp) {
            if (nullptr != next_tmp->left) {
                root->right->next = next_tmp->left;
                break;
            } else  if (nullptr != next_tmp->right) {
                root->right->next = next_tmp->right;
                break;
            } else {
                next_tmp = next_tmp->next;
            }
        }
        if (nullptr == next_tmp) {
            root->right->next = nullptr;
        }
    }

    //先右后左
    do_connect2(root->right);
    do_connect2(root->left);
}
Node* Solution::connect2(Node* root) {
    do_connect2(root);
    return root;
}

//124
//先考虑子问题：求解以每一个节点为上端点的情况下，最大的路径和。即路径只能左右拐弯，而不能上下拐弯。此时子问题和最大和子数组很相似。
//然后本体就很好做了。
int maxsum(TreeNode* root, int& ans) {
    if (!root) {
        return 0;
    }

    int max_left    = maxsum(root->left, ans);
    int max_right   = maxsum(root->right, ans);
    int max_son     = std::max(max_left, max_right);
    int res         = 0;
    int tmp         = root->val;

    if (max_son > 0) {
        res = max_son + root->val;
        if (max_left > 0) {
            tmp += max_left;
        }
        if (max_right > 0) {
            tmp += max_right;
        }
    } else {
        res = root->val;
    }

    if (tmp > ans) {
        ans = tmp;
    }
    return res;
}
int Solution::maxPathSum(TreeNode* root) {
    int ans = INT_MIN;
    maxsum(root, ans);
    return ans;
}


//129
int do_sumNumbers(TreeNode* root, int base) {
    if (!root) {
        return 0;
    }
    base = base * 10 + root->val;
    if (!root->left && !root->right) {
        return base;
    }
    return do_sumNumbers(root->left, base) + do_sumNumbers(root->right, base);
}
int Solution::sumNumbers(TreeNode* root) {
    return do_sumNumbers(root, 0);
}


//133
UndirectedGraphNode* clone(UndirectedGraphNode* node, unordered_map<int, UndirectedGraphNode*>& mapValueNode) {
    if (!node) {
        return nullptr;
    }

    //1、查找缓存的节点：已存在，则直接返回；
    auto const& posMap = mapValueNode.find(node->val);
    if (posMap != mapValueNode.end()) {
        return posMap->second;
    }

    //2、不存在则新建图节点res，并缓存；
    auto* res = new UndirectedGraphNode(node->val, vector<UndirectedGraphNode*>{});
    mapValueNode.insert(make_pair(node->val, res));

    //3、遍历 node 节点的邻居节点集合：将邻居节点进行克隆，并将克隆节点添加到res的邻居节点集合中；
    for (auto const& neighbor : node->neighbors) {
        res->neighbors.push_back(clone(neighbor, mapValueNode));
    }

    return res;
}
UndirectedGraphNode* Solution::cloneGraph(UndirectedGraphNode* node) {
#if 0
    //DFS
    unordered_map<int, UndirectedGraphNode*> mapValueNode;//缓存值对应的图节点
    return clone(node, mapValueNode);
#else
    //BFS
    if (!node) {
        return nullptr;
    }
    map<UndirectedGraphNode*, UndirectedGraphNode*> mapNodeClone;
    map<UndirectedGraphNode*, bool> mapNodeVisited;
    queue<UndirectedGraphNode*> queNodes;
    queNodes.push(node);

    while (!queNodes.empty()) {
        UndirectedGraphNode* front = queNodes.front();
        queNodes.pop();
        if (mapNodeVisited[front]) {
            continue;
        }

        mapNodeVisited[front] = true;
        UndirectedGraphNode* cur = nullptr;
        auto posMap = mapNodeClone.find(front);
        if (posMap == mapNodeClone.end()) {
            cur = new UndirectedGraphNode(front->val, vector<UndirectedGraphNode*>{});
            mapNodeClone.insert(make_pair(front, cur));
        } else {
            cur = posMap->second;
        }

        for (auto const& neighbor : front->neighbors) {
            posMap = mapNodeClone.find(neighbor);
            if (posMap == mapNodeClone.end()) {
                UndirectedGraphNode* temp = new UndirectedGraphNode(neighbor->val, vector<UndirectedGraphNode*>{});
                mapNodeClone.insert(make_pair(neighbor, temp));
                cur->neighbors.push_back(temp);
                queNodes.push(neighbor);
            } else {
                cur->neighbors.push_back(posMap->second);
            }
        }
    }

    return mapNodeClone[node];
#endif
}

//144
void do_preorderTraversal(TreeNode*root, vector<int>& vct) {
    if (!root) {
        return;
    }
    vct.push_back(root->val);
    do_preorderTraversal(root->left, vct);
    do_preorderTraversal(root->right, vct);
}
vector<int> Solution::preorderTraversal(TreeNode* root) {
    vector<int> res;
#if 0
    //递归法
    do_preorderTraversal(root, res);
#else
    //迭代法：辅助栈
    stack<TreeNode*> st;
    TreeNode* cur = root;
    while (cur || !st.empty()) {
        if (cur) {
            res.push_back(cur->val);
            st.push(cur);
            cur = cur->left;
        } else {
            cur = st.top();
            st.pop();
            cur = cur->right;
        }
    }
#endif
    return res;
}


//145
void do_postorderTraversal(TreeNode*root, vector<int>& vct) {
    if (!root) {
        return;
    }
    do_postorderTraversal(root->left, vct);
    do_postorderTraversal(root->right, vct);
    vct.push_back(root->val);
}
vector<int> Solution::postorderTraversal(TreeNode* root) {
    vector<int> res;
#if 0
    //递归法
    do_postorderTraversal(root, res);
#else
#if 0
    //迭代法1：辅助栈，bool类型为节点已遍历过的标识。
    stack<pair<TreeNode*, bool>> st;
    TreeNode* cur = root;
    while (cur || !st.empty()) {
        if (cur) {
            st.push(pair<TreeNode*, bool>(cur, false));
            cur = cur->left;
        } else {
            cur = st.top().first;
            if (st.top().second) {
                st.pop();
                res.push_back(cur->val);
                cur = nullptr;
            } else {
                st.top().second = true;
                cur = cur->right;
            }
        }
    }
#else
    //迭代法2：辅助栈，“根右左”顺序遍历，然后反转集合（反转后：左右根）
    stack<TreeNode*> st;
    TreeNode* cur = root;
    while (cur || !st.empty()) {
        if (cur) {
            res.push_back(cur->val);
            st.push(cur);
            cur = cur->right;
        } else {
            cur = st.top();
            st.pop();
            cur = cur->left;
        }
    }
    reverse(res.begin(), res.end());
#endif
#endif
    return res;
}


//119
vector<int> Solution::rightSideView(TreeNode* root) {
    //BFS，参考二叉树层次遍历
    if (!root) {
        return{};
    }

    queue<TreeNode*> que;
    vector<int> res;
    que.push(root);
    int size = que.size();
    while (!que.empty()) {
        TreeNode* tmp = que.front();
        que.pop();
        if (tmp->left) {
            que.push(tmp->left);
        }
        if (tmp->right) {
            que.push(tmp->right);
        }
        if (0 == --size) {
            size = que.size();
            res.push_back(tmp->val);
        }
    }
    return res;
}



int Solution::findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;     //小根堆

    for (int i = 0; i < k; ++i) {
        minHeap.push(nums[i]);
    }
    auto const& size = nums.size();
    for (int i = k - 1; i < size; ++i) {
        if (minHeap.top() <= nums[i]) {
            minHeap.pop();
            minHeap.push(nums[i]);
        }
    }
    return minHeap.top();
}


//222
int do_countNodes(TreeNode* root) {
    if (!root) {
        return 0;
    }
    return (nullptr != root->left) + (nullptr != root->right) +
        do_countNodes(root->left) + do_countNodes(root->right);
}

int Solution::countNodes(TreeNode* root) {
    if (!root) {
        return 0;
    }
#if 1
    return 1 + do_countNodes(root);
#else
    return 1 + countNodes(root->left) + countNodes(root->right);
#endif
}


//226
TreeNode* Solution::invertTree(TreeNode* root) {
    if (!root) {
        return nullptr;
    }
    TreeNode* p = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(p);
    return root;
}


//230
void do_kthSmallest(TreeNode* root, int& k, int& ans) {
    if (!root || k < 0) {
        return;
    }
    do_kthSmallest(root->left, k, ans);
    if (0 == --k) {
        ans = root->val;
        return;
    }
    do_kthSmallest(root->right, k, ans);
}
int Solution::kthSmallest(TreeNode* root, int k) {
    //中序遍历，左根右，返回第k个节点的值
    int res = 0;
    do_kthSmallest(root, k, res);
    return res;
}


//235
TreeNode* Solution::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //二叉搜索树的后续遍历
    if (p->val < root->val && q->val < root->val) {
        return lowestCommonAncestor(root->left, p, q);
    }
    if (p->val > root->val && q->val > root->val) {
        return lowestCommonAncestor(root->right, p, q);
    }
    return root;
}


//236
TreeNode* Solution::lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
    //二叉树的后序遍历
    if (!root) {
        return nullptr;
    }
    if (root == p || root == q) {
        return root;
    }
    TreeNode* left = lowestCommonAncestor2(root->left, p, q);
    TreeNode* right = lowestCommonAncestor2(root->right, p, q);
    if (left && right) {
        return root;
    } else if (left) {
        return left;
    } else {
        return right;
    }
    return nullptr;
}


//239
vector<int> Solution::maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans(0);
    priority_queue<pair<int, int>> maxHeap; // 大根堆
    for (int i = 0; i < k - 1; i++) {
        maxHeap.push(make_pair(nums[i], i));
    }
    for (int i = k - 1; i < nums.size(); i++) {
        while (!maxHeap.empty() && (i - maxHeap.top().second >= k || maxHeap.top().first <= nums[i])) {
            //删除过期的或者不可能称为最大值的值
            maxHeap.pop();
        }
        maxHeap.push(make_pair(nums[i], i));
        ans.push_back(maxHeap.top().first);
    }
    return ans;
}


//257
vector<string> Solution::binaryTreePaths(TreeNode* root) {
    if (!root) {
        return{};
    }
    if (!root->left && !root->right) {
        return vector<string>({ to_string(root->val) });
    }
    vector<string> left = binaryTreePaths(root->left);
    vector<string> right = binaryTreePaths(root->right);
    string cur = to_string(root->val) + "->";
    for (auto& s : left) {
        s = cur + s;
    }
    for (auto& s : right) {
        s = cur + s;
    }
    left.insert(left.end(), right.begin(), right.end());
    return left;
}


//264
int Solution::nthUglyNumber(int n) {
    vector<int> ans(n, 1);

    //三指针法
    vector<int> index(3, 0);

    for (int i = 1; i < n; ++i) {
        int a = ans[index[0]] * 2;
        int b = ans[index[1]] * 3;
        int c = ans[index[2]] * 5;
        int min = std::min(a, std::min(b, c));

        ans[i] = min;

        if (min == a) {
            ++index[0];
        }
        if (min == b) {
            ++index[1];
        }
        if (min == c) {
            ++index[2];
        }
    }
    return ans.back();
}


//313
int Solution::nthSuperUglyNumber(int n, vector<int>& primes) {
    vector<int> ans(n, 1);

    //多指针法
    auto const& primesSize = primes.size();
    vector<int> index(primesSize, 0);

    for (int i = 1; i < n; ++i) {
        int min = INT_MAX;

        for (int j = 0; j < primesSize; ++j) {
            auto const& temp = ans[index[j]] * primes[j];
            if (temp < min) {
                min = temp;
            }
        }

        ans[i] = min;

        for (int j = 0; j < primesSize; ++j) {
            if (ans[index[j]] * primes[j] == min) {
                ++index[j];
            }
        }
    }
    return ans.back();
}

