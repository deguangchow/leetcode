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


    /*94
    94. 二叉树的中序遍历
    给定一个二叉树，返回它的中序 遍历。

    示例:
    输入: [1,null,2,3]
       1
        \
         2
        /
       3
    输出: [1,3,2]

    进阶: 递归算法很简单，你可以通过迭代算法完成吗？
    */
    void inOder(TreeNode* root, vector<int>& ans);
    vector<int> inorderTraversal(TreeNode* root);


    /*95
    95. 不同的二叉搜索树 II
    给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。

    示例:
    输入: 3
    输出:
    [
      [1,null,3,2],
      [3,2,null,1],
      [3,1,null,null,2],
      [2,1,3],
      [1,null,2,null,3]
    ]
    解释:
    以上的输出对应以下 5 种不同结构的二叉搜索树：
       1         3     3      2      1
        \       /     /      / \      \
         3     2     1      1   3      2
        /     /       \                 \
       2     1         2                 3
    */
    vector<TreeNode*>* createBST(int begin, int end);
    vector<TreeNode*> generateTrees(int n);


    /*96
    96. 不同的二叉搜索树
    给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？

    示例:
    输入: 3
    输出: 5
    解释:
    给定 n = 3, 一共有 5 种不同结构的二叉搜索树:

       1         3     3      2      1
        \       /     /      / \      \
         3     2     1      1   3      2
        /     /       \                 \
       2     1         2                 3
    */
    int numTrees(int n);


    /*98
    98. 验证二叉搜索树
    给定一个二叉树，判断其是否是一个有效的二叉搜索树。
    假设一个二叉搜索树具有如下特征：
    节点的左子树只包含小于当前节点的数。
    节点的右子树只包含大于当前节点的数。
    所有左子树和右子树自身必须也是二叉搜索树。

    示例 1:
    输入:
        2
       / \
      1   3
    输出: true

    示例 2:
    输入:
        5
       / \
      1   4
         / \
        3   6
    输出: false

    解释: 输入为: [5,1,4,null,null,3,6]。
         根节点的值为 5 ，但是其右子节点值为 4 。
    */
    bool is_valid_BST;
    void inOderIsValidBST(TreeNode* root);
    bool isValidBST(TreeNode* root);

    /*99
    99. 恢复二叉搜索树
    二叉搜索树中的两个节点被错误地交换。
    请在不改变其结构的情况下，恢复这棵树。

    示例 1:
    输入: [1,3,null,null,2]
       1
      /
     3
      \
       2
    输出: [3,1,null,null,2]
       3
      /
     1
      \
       2

    示例 2:
    输入: [3,1,4,null,null,2]
      3
     / \
    1   4
       /
      2
    输出: [2,1,4,null,null,3]
      2
     / \
    1   4
       /
      3

    进阶:
    使用 O(n) 空间复杂度的解法很容易实现。
    你能想出一个只使用常数空间的解决方案吗？
    */
    TreeNode *p1, *p2, *p3, *p4, *last;
    void inOderRecoverTree(TreeNode* root);
    void recoverTree(TreeNode* root);


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
    vector<vector<int>> levelOrder(TreeNode* root);


    /*103
    103. 二叉树的锯齿形层次遍历
    给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

    例如：
    给定二叉树 [3,9,20,null,null,15,7],
        3
       / \
      9  20
        /  \
       15   7
    返回锯齿形层次遍历如下：
    [
      [3],
      [20,9],
      [15,7]
    ]
    */
    vector<vector<int>> zigzagLevelOrder(TreeNode* root);


    /*104
    104. 二叉树的最大深度
    给定一个二叉树，找出其最大深度。
    二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
    说明: 叶子节点是指没有子节点的节点。

    示例：
    给定二叉树 [3,9,20,null,null,15,7]，
        3
       / \
      9  20
        /  \
       15   7
    返回它的最大深度 3 。
    */
    int maxDepth(TreeNode* root);


    /*105
    105. 从前序与中序遍历序列构造二叉树
    根据一棵树的前序遍历与中序遍历构造二叉树。
    注意:
    你可以假设树中没有重复的元素。

    例如，给出
    前序遍历 preorder = [3,9,20,15,7]
    中序遍历 inorder = [9,3,15,20,7]
    返回如下的二叉树：
        3
       / \
      9  20
        /  \
       15   7
    */
    TreeNode* build(vector<int>::const_iterator pre1, vector<int>::const_iterator pre2,
        vector<int>::const_iterator in1, vector<int>::const_iterator in2);
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);


    /*106
    106. 从中序与后序遍历序列构造二叉树
    根据一棵树的中序遍历与后序遍历构造二叉树。
    注意:
    你可以假设树中没有重复的元素。

    例如，给出
    中序遍历 inorder = [9,3,15,20,7]
    后序遍历 postorder = [9,15,7,20,3]
    返回如下的二叉树：
        3
       / \
      9  20
        /  \
       15   7
    */
    TreeNode* buildTree_in_post(vector<int>& inorder, vector<int>& postorder);


    /*107
    107. 二叉树的层次遍历 II
    给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

    例如：
    给定二叉树 [3,9,20,null,null,15,7],
        3
       / \
      9  20
        /  \
       15   7
    返回其自底向上的层次遍历为：
    [
      [15,7],
      [9,20],
      [3]
    ]
    */
    vector<vector<int>> levelOrderBottom(TreeNode* root);


    /*108
    108. 将有序数组转换为二叉搜索树
    将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
    本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

    示例:
    给定有序数组: [-10,-3,0,5,9],
    一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：
          0
         / \
       -3   9
       /   /
     -10  5
    */
    TreeNode* sortedArrayToBST(vector<int>& nums, int const& begin, int const& end);
    TreeNode* sortedArrayToBST(vector<int>& nums);

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
    TreeNode* sortedListToBST(ListNode* head, ListNode* tail);
    TreeNode* sortedListToBST(ListNode* head);


    /*110
    110. 平衡二叉树
    给定一个二叉树，判断它是否是高度平衡的二叉树。
    本题中，一棵高度平衡二叉树定义为：
    一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。

    示例 1:
    给定二叉树 [3,9,20,null,null,15,7]
        3
       / \
      9  20
        /  \
       15   7
    返回 true 。

    示例 2:
    给定二叉树 [1,2,2,3,3,null,null,4,4]
           1
          / \
         2   2
        / \
       3   3
      / \
     4   4
    返回 false 。
    */
    bool isBalanced(TreeNode* root);


    /*111
    111. 二叉树的最小深度
    给定一个二叉树，找出其最小深度。
    最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
    说明: 叶子节点是指没有子节点的节点。

    示例:
    给定二叉树 [3,9,20,null,null,15,7],
        3
       / \
      9  20
        /  \
       15   7
    返回它的最小深度  2.
    */
    int minDepth(TreeNode* root);


    /*112
    112. 路径总和
    给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。
    说明: 叶子节点是指没有子节点的节点。

    示例:
    给定如下二叉树，以及目标和 sum = 22，
                  5
                 / \
                4   8
               /   / \
              11  13  4
             /  \      \
            7    2      1
    返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。
    */
    bool hasPathSum(TreeNode* root, int sum);


    /*113
    113. 路径总和 II
    给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
    说明: 叶子节点是指没有子节点的节点。

    示例:
    给定如下二叉树，以及目标和 sum = 22，
                  5
                 / \
                4   8
               /   / \
              11  13  4
             /  \    / \
            7    2  5   1
    返回:
    [
       [5,4,11,2],
       [5,8,4,5]
    ]
    */
    void dfsPathSum(vector<vector<int>>& res, vector<int>& path, TreeNode* root, int sum);
    vector<vector<int>> pathSum(TreeNode* root, int sum);


    /*114
    114. 二叉树展开为链表
    给定一个二叉树，原地将它展开为链表。

    例如，给定二叉树
        1
       / \
      2   5
     / \   \
    3   4   6
    将其展开为：
    1
     \
      2
       \
        3
         \
          4
           \
            5
             \
              6
    */
    void postOrder(TreeNode* root);
    void flatten(TreeNode* root);


    /*116
    116. 填充每个节点的下一个右侧节点指针
    给定一个完美二叉树，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：
    https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/02/15/116_sample.png
    struct Node {
        int val;
        Node *left;
        Node *right;
        Node *next;
    }
    填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
    初始状态下，所有 next 指针都被设置为 NULL。

    示例：
    输入：{ "$id":"1","left" : {"$id":"2","left" : {"$id":"3","left" : null,"next" : null,"right" : null,"val" : 4},"next" : null,"right" : {"$id":"4","left" : null,"next" : null,"right" : null,"val" : 5},"val" : 2},"next" : null,"right" : {"$id":"5","left" : {"$id":"6","left" : null,"next" : null,"right" : null,"val" : 6},"next" : null,"right" : {"$id":"7","left" : null,"next" : null,"right" : null,"val" : 7},"val" : 3},"val" : 1 }
    输出：{ "$id":"1","left" : {"$id":"2","left" : {"$id":"3","left" : null,"next" : {"$id":"4","left" : null,"next" : {"$id":"5","left" : null,"next" : {"$id":"6","left" : null,"next" : null,"right" : null,"val" : 7},"right" : null,"val" : 6},"right" : null,"val" : 5},"right" : null,"val" : 4},"next" : {"$id":"7","left" : {"$ref":"5"},"next" : null,"right" : {"$ref":"6"},"val" : 3},"right" : {"$ref":"4"},"val" : 2},"next" : null,"right" : {"$ref":"7"},"val" : 1 }

    解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。

    提示：
    你只能使用常量级额外空间。
    使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。
    */
    Node* connect(Node* root);


    /*117
    117. 填充每个节点的下一个右侧节点指针 II
    */
    Node* connect2(Node* root);


    /*124
    124. 二叉树中的最大路径和
    给定一个非空二叉树，返回其最大路径和。
    本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。

    示例 1:
    输入: [1,2,3]

           1
          / \
         2   3

    输出: 6

    示例 2:
    输入: [-10,9,20,null,null,15,7]

       -10
       / \
      9  20
        /  \
       15   7
    输出: 42
    */
    int maxPathSum(TreeNode* root);

    /*129
    129. 求根到叶子节点数字之和
    给定一个二叉树，它的每个结点都存放一个 0-9 的数字，每条从根到叶子节点的路径都代表一个数字。
    例如，从根到叶子节点路径 1->2->3 代表数字 123。
    计算从根到叶子节点生成的所有数字之和。
    说明: 叶子节点是指没有子节点的节点。

    示例 1:
    输入: [1,2,3]
        1
       / \
      2   3
    输出: 25
    解释:
    从根到叶子节点路径 1->2 代表数字 12.
    从根到叶子节点路径 1->3 代表数字 13.
    因此，数字总和 = 12 + 13 = 25.

    示例 2:
    输入: [4,9,0,5,1]
        4
       / \
      9   0
     / \
    5   1
    输出: 1026
    解释:
    从根到叶子节点路径 4->9->5 代表数字 495.
    从根到叶子节点路径 4->9->1 代表数字 491.
    从根到叶子节点路径 4->0 代表数字 40.
    因此，数字总和 = 495 + 491 + 40 = 1026.
    */
    int sumNumbers(TreeNode* root);


    /*144
    144. 二叉树的前序遍历
    给定一个二叉树，返回它的 前序 遍历。

     示例:
    输入: [1,null,2,3]
       1
        \
         2
        /
       3
    输出: [1,2,3]

    进阶: 递归算法很简单，你可以通过迭代算法完成吗？
    */
    vector<int> preorderTraversal(TreeNode* root);

    /*145
    145. 二叉树的后序遍历
    给定一个二叉树，返回它的 后序 遍历。

    示例:
    输入: [1,null,2,3]
       1
        \
         2
        /
       3
    输出: [3,2,1]
    */
    vector<int> postorderTraversal(TreeNode* root);
};
#endif  //SOLUTION_H

