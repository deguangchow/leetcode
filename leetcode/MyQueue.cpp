///    Copyright (C) 2018 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    MyQueue
///
///    \author   deguangchow
///    \version  1.0
///    \2019/04/22

#include "stdafx.h"
#include "MyQueue.h"



MyQueue::MyQueue() {
}

void MyQueue::push(int x) {
    stack<int> stTemp;
    while (!m_stData.empty()) {
        stTemp.push(m_stData.top());
        m_stData.pop();
    }
    m_stData.push(x);
    while (!stTemp.empty()) {
        m_stData.push(stTemp.top());
        stTemp.pop();
    }
}

int MyQueue::pop() {
    auto const& res = peek();
    m_stData.pop();
    return res;
}

int MyQueue::peek() {
    return m_stData.top();
}

bool MyQueue::empty() {
    return m_stData.empty();
}
