///    Copyright (C) 2018 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    WordDictionary
///
///    \author   deguangchow
///    \version  1.0
///    \2019/04/22

#pragma once
#ifndef WORD_DICTIONARY_H
#define WORD_DICTIONARY_H

/*211
211. 添加与搜索单词 - 数据结构设计
设计一个支持以下两种操作的数据结构：
void addWord(word)
bool search(word)
search(word) 可以搜索文字或正则表达式字符串，字符串只包含字母 . 或 a-z 。 . 可以表示任何一个字母。

示例:
addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true

说明:
你可以假设所有单词都是由小写字母 a-z 组成的。
*/
class WordDictionary {
    map<unsigned, unordered_set<string>> m_mapData;

public:
    /** Initialize your data structure here. */
    WordDictionary();

    /** Adds a word into the data structure. */
    void addWord(string word);

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one
    letter. */
    bool search(string word);
};

/**
* Your WordDictionary object will be instantiated and called as such:
* WordDictionary* obj = new WordDictionary();
* obj->addWord(word);
* bool param_2 = obj->search(word);
*/

#endif  //WORD_DICTIONARY_H
