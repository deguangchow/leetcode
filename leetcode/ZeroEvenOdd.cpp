///    Copyright (C) 2019 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    1116. 打印零与奇偶数
///
///    \author   deguangchow
///    \version  1.0
///    \2019/12/13
#include "stdafx.h"
#include "ZeroEvenOdd.h"

ZeroEvenOdd::ZeroEvenOdd(int n) {
    this->n = n;
    this->m_nIndex = 1;
    this->m_bZeroDone = false;
}

void ZeroEvenOdd::zero(function<void(int)> printNumber) {
    while (true) {
        std::unique_lock<std::mutex> lock(m_mtx);
        m_cv.wait(lock, [&]() {
            return this->m_nIndex > n || !this->m_bZeroDone;
        });
        if (m_nIndex > n) {
            return;
        }
        printNumber(0);
        m_bZeroDone = true;
        m_cv.notify_all();
    }
}

void ZeroEvenOdd::even(function<void(int)> printNumber) {
    while (true) {
        std::unique_lock<std::mutex> lock(m_mtx);
        m_cv.wait(lock, [&]() {
            return this->m_nIndex > n || this->m_bZeroDone && !(m_nIndex % 2);
        });
        if (m_nIndex > n) {
            return;
        }
        printNumber(m_nIndex++);
        m_bZeroDone = false;
        m_cv.notify_all();
    }
}

void ZeroEvenOdd::odd(function<void(int)> printNumber) {
    while (true) {
        std::unique_lock<std::mutex> lock(m_mtx);
        m_cv.wait(lock, [&]() {
            return this->m_nIndex > n || this->m_bZeroDone && m_nIndex % 2;
        });
        if (m_nIndex > n) {
            return;
        }
        printNumber(m_nIndex++);
        m_bZeroDone = false;
        m_cv.notify_all();
    }
}

