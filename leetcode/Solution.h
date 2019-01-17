///    Copyright (C) 2018 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    Leetcode Solution：结题方案
///
///    \author   deguangchow
///    \version  1.0
///    \2019/01/08

#pragma once
#ifndef SOLUTION_H
#define SOLUTION_H

//链表节点
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//二叉树节点
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    /*001
    1. 两数之和
    给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
    你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
    
    示例:
    给定 nums = [2, 7, 11, 15], target = 9
    因为 nums[0] + nums[1] = 2 + 7 = 9
    所以返回 [0, 1]
    */
    vector<int> twoSum(vector<int>& nums, int target);


    /*002
    2. 两数相加
    给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
    如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
    您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

    示例：
    输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
    输出：7 -> 0 -> 8
    原因：342 + 465 = 807
    */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);


    /*003
    3. 无重复字符的最长子串
    给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

    示例 1:
    输入: "abcabcbb"
    输出: 3
    解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

    示例 2:
    输入: "bbbbb"
    输出: 1
    解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

    示例 3:
    输入: "pwwkew"
    输出: 3
    解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。

    请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
    */
    int lengthOfLongestSubstring(string s);


    /*004
    4. 寻找两个有序数组的中位数
    给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
    请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
    你可以假设 nums1 和 nums2 不会同时为空。

    示例 1:
    nums1 = [1, 3]
    nums2 = [2]
    则中位数是 2.0

    示例 2:
    nums1 = [1, 2]
    nums2 = [3, 4]
    则中位数是 (2 + 3)/2 = 2.5
    */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);


    /*
    19. 删除链表的倒数第N个节点
    给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

    示例：
    给定一个链表: 1->2->3->4->5, 和 n = 2.
    当删除了倒数第二个节点后，链表变为 1->2->3->5.

    说明：
    给定的 n 保证是有效的。

    进阶：
    你能尝试使用一趟扫描实现吗？
    */
    ListNode* removeNthFromEnd(ListNode* head, int n);


    /*021
    21. 合并两个有序链表
    将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

    示例：
    输入：1->2->4, 1->3->4
    输出：1->1->2->3->4->4
    */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);

    /*023
    23. 合并K个排序链表
    题目描述
    合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

    示例:
    输入:
    [
      1->4->5,
      1->3->4,
      2->6
    ]
    输出: 1->1->2->3->4->4->5->6
    */
    ListNode* mergeKLists(vector<ListNode*>& lists);

    /*024
    24. 两两交换链表中的节点
    给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

    示例:
    给定 1->2->3->4, 你应该返回 2->1->4->3.

    说明:
    你的算法只能使用常数的额外空间。
    你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
    */
    ListNode* swapPairs(ListNode* head);


    /*025
    25. k个一组翻转链表
    给出一个链表，每 k 个节点一组进行翻转，并返回翻转后的链表。
    k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么将最后剩余节点保持原有顺序。

    示例 :
    给定这个链表：1->2->3->4->5
    当 k = 2 时，应当返回: 2->1->4->3->5
    当 k = 3 时，应当返回: 3->2->1->4->5

    说明 :
    你的算法只能使用常数的额外空间。
    你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
    */
    ListNode* reverseKGroup(ListNode* head, int k);


    /*061
    61. 旋转链表
    给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

    示例 1:
    输入: 1->2->3->4->5->NULL, k = 2
    输出: 4->5->1->2->3->NULL
    解释:
    向右旋转 1 步: 5->1->2->3->4->NULL
    向右旋转 2 步: 4->5->1->2->3->NULL

    示例 2:
    输入: 0->1->2->NULL, k = 4
    输出: 2->0->1->NULL
    解释:
    向右旋转 1 步: 2->0->1->NULL
    向右旋转 2 步: 1->2->0->NULL
    向右旋转 3 步: 0->1->2->NULL
    向右旋转 4 步: 2->0->1->NULL
    */
    ListNode* rotateRight(ListNode* head, int k);

    /*082
    82. 删除排序链表中的重复元素 II
    给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

    示例 1:
    输入: 1->2->3->3->4->4->5
    输出: 1->2->5

    示例 2:
    输入: 1->1->1->2->3
    输出: 2->3
    */
    ListNode* deleteDuplicates(ListNode* head);

    /*083
    83. 删除排序链表中的重复元素
    给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

    示例 1:
    输入: 1->1->2
    输出: 1->2

    示例 2:
    输入: 1->1->2->3->3
    输出: 1->2->3
    */
    ListNode* deleteDuplicatesOne(ListNode* head);


    /*086
    86. 分隔链表
    给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
    你应当保留两个分区中每个节点的初始相对位置。

    示例:
    输入: head = 1->4->3->2->5->2, x = 3
    输出: 1->2->2->4->3->5
    */
    ListNode* partition(ListNode* head, int x);


    /*092
    92. 反转链表 II
    反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
    说明:
    1 ≤ m ≤ n ≤ 链表长度。

    示例:
    输入: 1->2->3->4->5->NULL, m = 2, n = 4
    输出: 1->4->3->2->5->NULL
    */
    ListNode* reverseBetween(ListNode* head, int m, int n);


    /*100
    100. 相同的树
    给定两个二叉树，编写一个函数来检验它们是否相同。
    如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

    示例 1:
    输入:        1         1
                / \       / \
               2   3     2   3
    [1,2,3],   [1,2,3]
    输出: true

    示例 2:
    输入:        1          1
                /           \
               2             2
    [1,2],     [1,null,2]
    输出: false

    示例 3:
    输入:        1         1
                / \       / \
               2   1     1   2
    [1,2,1],   [1,1,2]
    输出: false
    */
    bool isSameTree(TreeNode* p, TreeNode* q);

    /*101
    101. 对称二叉树
    给定一个二叉树，检查它是否是镜像对称的。
    例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
        1
       / \
      2   2
     / \ / \
    3  4 4  3
    但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
     1
    / \
    2   2
     \   \
      3    3
    说明:
    如果你可以运用递归和迭代两种方法解决这个问题，会很加分。
    */
    bool isMirror(TreeNode* t1, TreeNode *t2);
    bool isSymmetric(TreeNode* root);


    /*102
    102. 二叉树的层次遍历
    给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。

    例如:
    给定二叉树: [3,9,20,null,null,15,7],
     3
    / \
    9  20
      /  \
     15   7
    返回其层次遍历结果：
    [
    [3],
    [9,20],
    [15,7]
    ]
    */
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vv;

        if (root == nullptr)
            return vv;

        TreeNode *node = root;
        queue<TreeNode *> nodeq;

        nodeq.push(node);

        int count = 1;
        int nextcount = 0;

        while (!nodeq.empty()) {
            vector<int> v;
            for (int i = 0; i < count; i++) {
                node = nodeq.front();
                if (node->left != nullptr) {
                    nodeq.push(node->left);
                    nextcount++;
                }

                if (node->right != nullptr) {
                    nodeq.push(node->right);
                    nextcount++;
                }

                nodeq.pop();
                v.push_back(node->val);
            }

            count = nextcount;
            nextcount = 0;
            vv.push_back(v);
        }

        return vv;
    }


    /*109
    109. 有序链表转换二叉搜索树
    给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。
    本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

    示例:
    给定的有序链表： [-10, -3, 0, 5, 9],
    一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：

          0
         / \
       -3   9
       /   /
     -10  5
    */
    TreeNode* sortedListToBST(ListNode* head);
};
#endif  //SOLUTION_H

