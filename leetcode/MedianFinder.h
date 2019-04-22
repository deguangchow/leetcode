///    Copyright (C) 2018 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    MedianFinder
///
///    \author   deguangchow
///    \version  1.0
///    \2019/04/22

#pragma once
#ifndef MEDIAN_FINDER_H
#define MEDIAN_FINDER_H

/*295
295. 数据流的中位数
中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。
例如，
[2,3,4] 的中位数是 3
[2,3] 的中位数是 (2 + 3) / 2 = 2.5

设计一个支持以下两种操作的数据结构：
void addNum(int num) - 从数据流中添加一个整数到数据结构中。
double findMedian() - 返回目前所有元素的中位数。

示例：
addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3)
findMedian() -> 2

进阶:
如果数据流中所有整数都在 0 到 100 范围内，你将如何优化你的算法？
如果数据流中 99% 的整数都在 0 到 100 范围内，你将如何优化你的算法？
*/
#if 1
class MedianFinder {
    size_t              m_uTotal = 0;
    map<int, int>       m_mapData;

public:
    /** initialize your data structure here. */
    MedianFinder();

    void addNum(int num);

    double findMedian();
};
#else
class MedianFinder {
    priority_queue<int> bigque;                                 //大顶堆
    priority_queue<int, vector<int>, greater<int>> smallque;    //小顶堆

public:
    /** initialize your data structure here. */
    MedianFinder() {
    }

    void addNum(int num) {
        if (bigque.empty()) {
            bigque.push(num);
        } else if (bigque.size() == smallque.size()) {
            if (bigque.top() < num) {
                smallque.push(num);
            } else {
                bigque.push(num);
            }
        } else if (bigque.size() > smallque.size()) {
            if (bigque.top() < num) {
                smallque.push(num);
            } else {
                smallque.push(bigque.top());
                bigque.pop();
                bigque.push(num);
            }
        } else {
            if (smallque.top() > num) {
                bigque.push(num);
            } else {
                bigque.push(smallque.top());
                smallque.pop(); smallque.push(num);
            }
        }
    }

    double findMedian() {
        if (bigque.size() == smallque.size()) {
            return static_cast<double>((bigque.top() + smallque.top()) / 2);
        }
        if (bigque.size() > smallque.size()) {
            return bigque.top();
        }
        if (bigque.size() < smallque.size()) {
            return smallque.top();
        }
        return 0;
    }
};
#endif

/**
* Your MedianFinder object will be instantiated and called as such:
* MedianFinder* obj = new MedianFinder();
* obj->addNum(num);
* double param_2 = obj->findMedian();
*/

#endif  //MEDIAN_FINDER_H
