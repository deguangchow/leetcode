///    Copyright (C) 2018 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    PeekingIterator
///
///    \author   deguangchow
///    \version  1.0
///    \2019/04/22

#include "stdafx.h"
#include "PeekingIterator.h"


Iterator::Iterator(const Iterator& iter) {
    data = nullptr;
}

Iterator::Iterator(const vector<int>& nums) {
    data = nullptr;
}

Iterator& Iterator::operator=(const Iterator& iter) {
    data = nullptr;
    return *this;
}

Iterator::~Iterator() {
}

int Iterator::next() {
    return -1;
}

bool Iterator::hasNext() const {
    return false;
}



PeekingIterator::PeekingIterator(const vector<int>& nums) : Iterator(nums) {
    // Initialize any member here.
    // **DO NOT** save a copy of nums and manipulate it directly.
    // You should only use the Iterator interface methods.
}

int PeekingIterator::peek() {
    if (m_bFlag) {
        return m_nVal;
    }
    m_bFlag = true;
    m_nVal = Iterator::next();
    return m_nVal;
}

int PeekingIterator::next() {
    if (m_bFlag) {
        m_bFlag = false;
        return m_nVal;
    }
    return Iterator::next();
}

bool PeekingIterator::hasNext() const {
    if (m_bFlag) {
        return true;
    }
    return Iterator::hasNext();
}



