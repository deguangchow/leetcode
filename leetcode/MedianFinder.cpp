///    Copyright (C) 2018 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    MedianFinder
///
///    \author   deguangchow
///    \version  1.0
///    \2019/04/22

#include "stdafx.h"
#include "MedianFinder.h"


#if 0

MedianFinder::MedianFinder() {
}

void MedianFinder::addNum(int num) {
    ++m_uTotal;
    auto const& pos = m_mapData.find(num);
    if (pos == m_mapData.end()) {
        m_mapData.insert(make_pair(num, 1));
        return;
    }
    ++pos->second;
}

double MedianFinder::findMedian() {
    bool bFlag = m_uTotal % 2 == 0;
    double nMedian = m_uTotal / 2.0;
    double dRes = 0.0;
    bool bDiv2 = false;
    for (auto const& posMap : m_mapData) {
        auto const& nCount = posMap.second;
        if (nMedian - nCount > 0) {
            nMedian -= nCount;
            continue;
        }
        nMedian -= nCount;
        dRes += posMap.first;
        if (bDiv2) {
            return dRes / 2.0;
        }
        if (!bFlag || nMedian < 0) {
            return dRes;
        }
        bDiv2 = true;
        continue;
    }
    return bDiv2 ? dRes / 2.0 : dRes;
}

#else

MedianFinder::MedianFinder() {
}

//【原理】大根堆的top为左边集合中最大的数，小根堆的top为右边集合中最小的值；
//【建堆】保持大根堆和小根堆size的绝对值<=1；
//【查找】
//（1）当大根堆的size等于小根堆的size时，（大根堆的top和小根堆的top）/2.0 即中位数；
//（2）当大根堆的size大于小根堆的size时，大根堆的top即中位数；
//（3）当大根堆的size小于小根堆的size时，小根堆的top即中位数；
void MedianFinder::addNum(int num) {
    if (maxHeap.empty()) {
        maxHeap.push(num);
    } else if (maxHeap.size() == minHeap.size()) {
        if (maxHeap.top() < num) {
            minHeap.push(num);
        } else {
            maxHeap.push(num);
        }
    } else if (maxHeap.size() > minHeap.size()) {
        if (maxHeap.top() < num) {
            minHeap.push(num);
        } else {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            maxHeap.push(num);
        }
    } else {
        if (minHeap.top() > num) {
            maxHeap.push(num);
        } else {
            maxHeap.push(minHeap.top());
            minHeap.pop();
            minHeap.push(num);
        }
    }
}

double MedianFinder::findMedian() {
    if (maxHeap.size() == minHeap.size()) {
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
    if (maxHeap.size() > minHeap.size()) {
        return maxHeap.top();
    }
    if (maxHeap.size() < minHeap.size()) {
        return minHeap.top();
    }
    return 0;
}

#endif


