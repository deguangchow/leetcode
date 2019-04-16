///    Copyright (C) 2018 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    binary search tree iteartor.
///
///    \author   deguangchow
///    \version  1.0
///    \2019/04/16


#include "stdafx.h"
#include "BSTIterator.h"
#include "Solution.h"


BSTIterator::BSTIterator(TreeNode* root) {
    m_nCur = 0;
    m_vctData = Solution().inorderTraversal(root);//中序遍历
}
int BSTIterator::next() {
    if (m_nCur < m_vctData.size()) {
        return m_vctData[m_nCur++];
    } else {
        return -1;
    }
}
bool BSTIterator::hasNext() {
    return m_nCur < m_vctData.size();
}
