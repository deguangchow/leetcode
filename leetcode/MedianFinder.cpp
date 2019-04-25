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

void MedianFinder::addNum(int num) {
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

double MedianFinder::findMedian() {
    if (bigque.size() == smallque.size()) {
        return (bigque.top() + smallque.top()) / 2.0;
    }
    if (bigque.size() > smallque.size()) {
        return bigque.top();
    }
    if (bigque.size() < smallque.size()) {
        return smallque.top();
    }
    return 0;
}

#endif


