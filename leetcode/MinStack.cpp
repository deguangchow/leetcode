///    Copyright (C) 2018 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    MinStack
///
///    \author   deguangchow
///    \version  1.0
///    \2019/04/19

#include "stdafx.h"
#include "MinStack.h"



MinStack::MinStack() {
}

void MinStack::push(int x) {
    m_lstData.push_back(x);
}

void MinStack::pop() {
    m_lstData.pop_back();
}

int MinStack::top() {
    return m_lstData.back();
}

int MinStack::getMin() {
    if (m_lstData.empty()) {
        return 0;
    }
    int nMin = INT_MAX;
    for (auto& pos : m_lstData) {
        if (pos < nMin) {
            nMin = pos;
        }
    }
    return nMin;
}
