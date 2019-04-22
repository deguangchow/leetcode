///    Copyright (C) 2018 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    MyStack
///
///    \author   deguangchow
///    \version  1.0
///    \2019/04/22

#include "stdafx.h"
#include "MyStack.h"


MyStack::MyStack() {
}

void MyStack::push(int x) {
    m_lstData.push_back(x);
}

int MyStack::pop() {
    auto const& res = top();
    m_lstData.pop_back();
    return res;
}

int MyStack::top() {
    return m_lstData.back();
}

bool MyStack::empty() {
    return m_lstData.empty();
}
