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
}

int LRUCache::get(int key) {
    auto const& posMap = m_mapKeyPos.find(key);
    if (posMap == m_mapKeyPos.end()) {
        return -1;
    }

    auto const value = posMap->second->second;
    m_lstPair.erase(posMap->second);
    m_lstPair.push_front(make_pair(key, value));
    m_mapKeyPos[key] = m_lstPair.begin();
    return posMap->second->second;
}

void LRUCache::put(int key, int value) {
    auto const& posMap = m_mapKeyPos.find(key);
    if (posMap != m_mapKeyPos.end()) {
        m_lstPair.erase(posMap->second);
    }

    m_lstPair.push_front(make_pair(key, value));
    m_mapKeyPos[key] = m_lstPair.begin();

    if (m_lstPair.size() > m_nCapacity) {
        auto const& key = m_lstPair.back().first;
        m_mapKeyPos.erase(key);
        m_lstPair.pop_back();
    }
}
