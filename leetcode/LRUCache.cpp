///    Copyright (C) 2018 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    LRUCache
///
///    \author   deguangchow
///    \version  1.0
///    \2019/04/18

#include "stdafx.h"
#include "LRUCache.h"


LRUCache::LRUCache(int capacity) : m_nCapacity(capacity) {
    m_mapKeyValue.clear();
}

int LRUCache::get(int key) {
    auto const& pos = m_mapKeyValue.find(key);
    if (pos == m_mapKeyValue.end()) {
        return -1;
    }
    return pos->second;
}

void LRUCache::put(int key, int value) {
    auto const& pos = m_mapKeyValue.find(key);
    if (pos != m_mapKeyValue.end()) {
        pos->second = value;
        ++m_mapKeyTimes[key];
        return;
    }

    if (m_mapKeyValue.size() < m_nCapacity) {
        m_mapKeyValue.insert(std::make_pair(key, value));
        m_mapKeyTimes.insert(std::make_pair(key, 1));
        return;
    }

    //获取LRU的key，
}
