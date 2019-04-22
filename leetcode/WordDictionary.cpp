///    Copyright (C) 2018 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    WordDictionary
///
///    \author   deguangchow
///    \version  1.0
///    \2019/04/22


#include "stdafx.h"
#include "WordDictionary.h"



WordDictionary::WordDictionary() {
}

void WordDictionary::addWord(string word) {
    auto const& nWordLen = word.length();
    auto const& posMap = m_mapData.find(nWordLen);
    if (posMap == m_mapData.end()) {
        unordered_set<string> setData = { word };
        m_mapData.insert(std::make_pair(nWordLen, setData));
        return;
    }
    auto& setData = posMap->second;
    auto const& posSet = setData.find(word);
    if (posSet != setData.end()) {
        return;
    }
    setData.insert(word);
}

bool WordDictionary::search(string word) {
    auto const& nWordLen = word.length();
    auto const& posMap = m_mapData.find(nWordLen);
    if (posMap == m_mapData.end()) {
        return false;
    }
    auto const& setData = posMap->second;
    for (auto const& sData : setData) {
        unsigned uIndex = 0;
        while (sData[uIndex] != '\0') {
            if (sData[uIndex] != word[uIndex] && word[uIndex] != '.') {
                break;
            }
            ++uIndex;
        }
        if (uIndex == nWordLen) {
            return  true;
        }
    }
    return false;
}


