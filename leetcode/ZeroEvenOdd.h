///    Copyright (C) 2019 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    1116. 打印零与奇偶数
///
///    \author   deguangchow
///    \version  1.0
///    \2019/12/13
#pragma once
#ifndef ZERO_EVEN_ODD_H
#define ZERO_EVEN_ODD_H


static void printNumber(int n) {
    std::cout << n;
}

class ZeroEvenOdd {
private:
    int n;
    int m_nIndex;
    bool m_bZeroDone;
    std::mutex m_mtx;
    std::condition_variable m_cv;

public:
    explicit ZeroEvenOdd(int n);

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber);

    void even(function<void(int)> printNumber);

    void odd(function<void(int)> printNumber);
};

#endif  //ZERO_EVEN_ODD_H
