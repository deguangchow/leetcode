///    Copyright (C) 2018 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    Trie
///
///    \author   deguangchow
///    \version  1.0
///    \2019/04/22

#include "stdafx.h"
#include "Trie.h"

Trie::Trie() {
}

void Trie::insert(string word) {
    auto const& cFirst = word[0];
    if (cFirst == '\0') {
        return;
    }
    auto const& posMap = m_mapData.find(cFirst);
    if (posMap == m_mapData.end()) {
        set<string> setData = { word };
        m_mapData.insert(std::make_pair(cFirst, setData));
        return;
    }
    auto& setData = posMap->second;
    auto const& posSet = setData.find(word);
    if (posSet != setData.end()) {
        return;
    }
    setData.insert(word);
}

bool Trie::search(string word) {
    auto const& cFirst = word[0];
    if (cFirst == '\0') {
        return false;
    }
    auto const& posMap = m_mapData.find(cFirst);
    if (posMap == m_mapData.end()) {
        return false;
    }
    auto const& setData = posMap->second;
    auto const& posSet = setData.find(word);
    return posSet != setData.end();
}

bool Trie::startsWith(string prefix) {
    auto const& cFirst = prefix[0];
    if (cFirst == '\0') {
        return false;
    }
    auto const& posMap = m_mapData.find(cFirst);
    if (posMap == m_mapData.end()) {
        return false;
    }
    auto const& setData = posMap->second;
    for (auto const& sData : setData) {
        auto const& cData = sData.c_str();
        auto const& cPrefix = prefix.c_str();
        if (strncmp(cData, cPrefix, strlen(cPrefix)) == 0) {
            return true;
        }
    }
    return false;
}


