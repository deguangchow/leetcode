///    Copyright (C) 2019 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    297. 二叉树的序列化与反序列化
///
///    \author   deguangchow
///    \version  1.0
///    \2020/01/21

#include "stdafx.h"
#include "BinaryTreeSerialize.h"

//二叉树层次遍历（非递归：辅助队列）
string CodeC::serialize(TreeNode* root) {
    string data;    queue<TreeNode*> queCache;
    queCache.push(root);

    while (!queCache.empty()) {
        auto *p = queCache.front();
        if (p) {
            data += to_string(p->val);
            queCache.push(p->left);
            queCache.push(p->right);
        } else {
            data += '#';
        }
        data += ',';
        queCache.pop();
    }

    return data;
}

TreeNode* CodeC::deserialize(string data) {
    unsigned i = 0;
    int nextVal = 0;
    bool nextSign = false;
    auto const &lambda_next = [&]()->bool {
        if (data[i] == '#') {
            i += 2;
            return false;
        }
        nextVal = 0;
        while (i < data.length() && data[i] != ',') {
            if (data[i] == '-') {
                nextSign = true;
            } else {
                nextVal = nextVal * 10 + data[i] - '0';
            }
            ++i;
        }
        if (nextSign) {
            nextVal *= -1;
            nextSign = false;
        }
        ++i;
        return true;
    };

    if (!lambda_next()) {
        return nullptr;
    }

    auto *root = new TreeNode(nextVal);
    queue<TreeNode*> queCache;
    queCache.push(root);

    while (!queCache.empty()) {
        auto *p = queCache.front();
        if (lambda_next()) {
            p->left = new TreeNode(nextVal);
            queCache.push(p->left);
        }
        if (lambda_next()) {
            p->right = new TreeNode(nextVal);
            queCache.push(p->right);
        }
        queCache.pop();
    }
    return root;
}

