///    Copyright (C) 2018 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    LeetCode No.001 unit test.
///
///    \author   deguangchow
///    \version  1.0
///    \2019/01/08

#include "stdafx.h"
#include <gtest/gtest.h>
#include "Solution.h"

#if 0

TEST(LeetCode, Test003) {
    Solution solution;
    EXPECT_EQ(0, solution.lengthOfLongestSubstring(""));
    EXPECT_EQ(1, solution.lengthOfLongestSubstring(" "));
    EXPECT_EQ(2, solution.lengthOfLongestSubstring("aab"));
    EXPECT_EQ(3, solution.lengthOfLongestSubstring("abcabcbb"));
    EXPECT_EQ(1, solution.lengthOfLongestSubstring("bbbbb"));
    EXPECT_EQ(3, solution.lengthOfLongestSubstring("pwwkew"));
    EXPECT_EQ(5, solution.lengthOfLongestSubstring("qrsvbspk"));
    EXPECT_EQ(3, solution.lengthOfLongestSubstring("aabaab!bb"));
    EXPECT_EQ(5, solution.lengthOfLongestSubstring("12123536216"));
    EXPECT_EQ(4, solution.lengthOfLongestSubstring("',...1212353632.2.16"));
}

#endif

TEST(LeetCode, Test004) {
    Solution solution;
    EXPECT_EQ(0, solution.lengthOfLongestSubstring(""));
}

