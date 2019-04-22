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
    queue<int> quTemp;
    quTemp.push(x);
    while (!m_quData.empty()) {
        quTemp.push(m_quData.front());
        m_quData.pop();
    }
    while (!quTemp.empty()) {
        m_quData.push(quTemp.front());
        quTemp.pop();
    }
}

int MyStack::pop() {
    auto const& res = top();
    m_quData.pop();
    return res;
}

int MyStack::top() {
    return m_quData.front();
}

bool MyStack::empty() {
    return m_quData.empty();
}
