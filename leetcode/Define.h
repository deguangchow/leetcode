///    Copyright (C) 2018 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    defination of common data struct.
///
///    \author   deguangchow
///    \version  1.0
///    \2019/04/16

#pragma once
#ifndef DEFINE_H
#define DEFINE_H

//链表节点
struct ListNode {
    int val;
    ListNode *next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

//二叉树节点
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//完美二叉树节点：116
struct Node {
    int val;
    Node *left;
    Node *right;
    Node *next;
};

//无向图节点
class UndirectedGraphNode {
public:
    int val;
    vector<UndirectedGraphNode*> neighbors;
    UndirectedGraphNode(int _val, vector<UndirectedGraphNode*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


#endif  //DEFINE_H

