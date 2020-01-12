///    Copyright (C) 2018 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    Leetcode Solution：结题方案
///
///    \author   deguangchow
///    \version  1.0
///    \2019/01/08

#pragma once
#ifndef SOLUTION_H
#define SOLUTION_H



class Solution {
public:
    /*001
    1. 两数之和
    给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
    你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
    
    示例:
    给定 nums = [2, 7, 11, 15], target = 9
    因为 nums[0] + nums[1] = 2 + 7 = 9
    所以返回 [0, 1]
    */
    vector<int> twoSum(vector<int>& nums, int target);


    /*002
    2. 两数相加
    给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
    如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
    您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

    示例：
    输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
    输出：7 -> 0 -> 8
    原因：342 + 465 = 807
    */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);


    /*003
    3. 无重复字符的最长子串
    给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

    示例 1:
    输入: "abcabcbb"
    输出: 3
    解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

    示例 2:
    输入: "bbbbb"
    输出: 1
    解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

    示例 3:
    输入: "pwwkew"
    输出: 3
    解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。

    请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
    */
    int lengthOfLongestSubstring(string s);


    /*004
    4. 寻找两个有序数组的中位数
    给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
    请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
    你可以假设 nums1 和 nums2 不会同时为空。

    示例 1:
    nums1 = [1, 3]
    nums2 = [2]
    则中位数是 2.0

    示例 2:
    nums1 = [1, 2]
    nums2 = [3, 4]
    则中位数是 (2 + 3)/2 = 2.5
    */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);

	/*005
	5. 最长回文子串
	给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

	示例 1：
	输入: "babad"
	输出: "bab"
	注意: "aba" 也是一个有效答案。

	示例 2：
	输入: "cbbd"
	输出: "bb"
	*/
    string longestPalindrome(string s);


    /*006
    6. Z 字形变换
    将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
    比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
    L   C   I   R
    E T O E S I I G
    E   D   H   N
    之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
    请你实现这个将字符串进行指定行数变换的函数：
    string convert(string s, int numRows);

    示例 1:
    输入: s = "LEETCODEISHIRING", numRows = 3
    输出: "LCIRETOESIIGEDHN"

    示例 2:
    输入: s = "LEETCODEISHIRING", numRows = 4
    输出: "LDREOEIIECIHNTSG"
    解释:
    L     D     R
    E   O E   I I
    E C   I H   N
    T     S     G
    */
    string convert(string s, int numRows);


	/*007
	7. 整数反转
	给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

	示例 1:
	输入: 123
	输出: 321

	示例 2:
	输入: -123
	输出: -321

	示例 3:
	输入: 120
	输出: 21

	注意:
	假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  2^31 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。
	*/
    int reverse(int x);


	/*008
	8. 字符串转换整数 (atoi)
	请你来实现一个 atoi 函数，使其能将字符串转换成整数。
	首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。
	当我们寻找到的第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字组合起来，作为该整数的正负号；假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。
	该字符串除了有效的整数部分之后也可能会存在多余的字符，这些字符可以被忽略，它们对于函数不应该造成影响。
	注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换。
	在任何情况下，若函数不能进行有效的转换时，请返回 0。

	说明：
	假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−2^31,  2^31 − 1]。如果数值超过这个范围，请返回  INT_MAX (2^31 − 1) 或 INT_MIN (−2^31) 。

	示例 1:
	输入: "42"
	输出: 42

	示例 2:
	输入: "   -42"
	输出: -42
	解释: 第一个非空白字符为 '-', 它是一个负号。
 		 我们尽可能将负号与后面所有连续出现的数字组合起来，最后得到 -42 。
	
	示例 3:
	输入: "4193 with words"
	输出: 4193
	解释: 转换截止于数字 '3' ，因为它的下一个字符不为数字。
	
	示例 4:
	输入: "words and 987"
	输出: 0
	解释: 第一个非空字符是 'w', 但它不是数字或正、负号。
		 因此无法执行有效的转换。
	
	示例 5:
	输入: "-91283472332"
	输出: -2147483648
	解释: 数字 "-91283472332" 超过 32 位有符号整数范围。
	因此返回 INT_MIN (−2^31) 。
	*/
    int myAtoi(string str);


	/*009
	9. 回文数
	判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

	示例 1:
	输入: 121
	输出: true

	示例 2:
	输入: -121
	输出: false
	解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。

	示例 3:
	输入: 10
	输出: false
	解释: 从右向左读, 为 01 。因此它不是一个回文数。

	进阶:
	你能不将整数转为字符串来解决这个问题吗？
	*/
    bool isPalindrome(int x);


	/*012
	12. 整数转罗马数字
	罗马数字包含以下七种字符： I， V， X， L，C，D 和 M。
	字符          数值
	I             1
	V             5
	X             10
	L             50
	C             100
	D             500
	M             1000
	例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。
	通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
	I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
	X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
	C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
	给定一个整数，将其转为罗马数字。输入确保在 1 到 3999 的范围内。

	示例 1:
	输入: 3
	输出: "III"

	示例 2:
	输入: 4
	输出: "IV"

	示例 3:
	输入: 9
	输出: "IX"
	
	示例 4:
	输入: 58
	输出: "LVIII"
	解释: L = 50, V = 5, III = 3.

	示例 5:
	输入: 1994
	输出: "MCMXCIV"
	解释: M = 1000, CM = 900, XC = 90, IV = 4.
	*/
    string intToRoman(int num);


    /*013
    13. 罗马数字转整数
    罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。
    字符          数值
    I             1
    V             5
    X             10
    L             50
    C             100
    D             500
    M             1000
    例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。
    通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
    I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
    X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
    C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
    给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。

    示例 1:
    输入: "III"
    输出: 3

    示例 2:
    输入: "IV"
    输出: 4

    示例 3:
    输入: "IX"
    输出: 9

    示例 4:
    输入: "LVIII"
    输出: 58
    解释: L = 50, V= 5, III = 3.

    示例 5:
    输入: "MCMXCIV"
    输出: 1994
    解释: M = 1000, CM = 900, XC = 90, IV = 4.
    */
    int romanToInt(string s);


    /*014
    14. 最长公共前缀
    编写一个函数来查找字符串数组中的最长公共前缀。
    如果不存在公共前缀，返回空字符串 ""。

    示例 1:
    输入: ["flower","flow","flight"]
    输出: "fl"

    示例 2:
    输入: ["dog","racecar","car"]
    输出: ""
    解释: 输入不存在公共前缀。

    说明:
    所有输入只包含小写字母 a-z 。
    */
    string longestCommonPrefix(vector<string>& strs);


    /*017
    17. 电话号码的字母组合
    给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
    给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
    https://assets.leetcode-cn.com/aliyun-lc-upload/original_images/17_telephone_keypad.png

    示例:
    输入："23"
    输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

    说明:
    尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
    */
    vector<string> letterCombinations(string digits);

    /*018
    18. 四数之和
    给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，
    使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
    注意：
    答案中不可以包含重复的四元组。

    示例：
    给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
    满足要求的四元组集合为：
    [
      [-1,  0, 0, 1],
      [-2, -1, 1, 2],
      [-2,  0, 0, 2]
    ]
    */
    vector<vector<int>> fourSum(vector<int>& nums, int target);


    /*
    19. 删除链表的倒数第N个节点
    给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

    示例：
    给定一个链表: 1->2->3->4->5, 和 n = 2.
    当删除了倒数第二个节点后，链表变为 1->2->3->5.

    说明：
    给定的 n 保证是有效的。

    进阶：
    你能尝试使用一趟扫描实现吗？
    */
    ListNode* removeNthFromEnd(ListNode* head, int n);


    /*
    20. 有效的括号
    给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
    有效字符串需满足：
    左括号必须用相同类型的右括号闭合。
    左括号必须以正确的顺序闭合。
    注意空字符串可被认为是有效字符串。

    示例 1:
    输入: "()"
    输出: true
    
    示例 2:
    输入: "()[]{}"
    输出: true

    示例 3:
    输入: "(]"
    输出: false

    示例 4:
    输入: "([)]"
    输出: false

    示例 5:
    输入: "{[]}"
    输出: true
    */
    bool isValid(string s);


    /*021
    21. 合并两个有序链表
    将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

    示例：
    输入：1->2->4, 1->3->4
    输出：1->1->2->3->4->4
    */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);


    /*022
    22. 括号生成
    给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

    例如，给出 n = 3，生成结果为：
    [
    "((()))",
    "(()())",
    "(())()",
    "()(())",
    "()()()"
    ]
    */
    vector<string> generateParenthesis(int n);


    /*023
    23. 合并K个排序链表
    题目描述
    合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

    示例:
    输入:
    [
      1->4->5,
      1->3->4,
      2->6
    ]
    输出: 1->1->2->3->4->4->5->6
    */
    ListNode* mergeKLists(vector<ListNode*>& lists);

    /*024
    24. 两两交换链表中的节点
    给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

    示例:
    给定 1->2->3->4, 你应该返回 2->1->4->3.

    说明:
    你的算法只能使用常数的额外空间。
    你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
    */
    ListNode* swapPairs(ListNode* head);


    /*025
    25. k个一组翻转链表
    给出一个链表，每 k 个节点一组进行翻转，并返回翻转后的链表。
    k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么将最后剩余节点保持原有顺序。

    示例 :
    给定这个链表：1->2->3->4->5
    当 k = 2 时，应当返回: 2->1->4->3->5
    当 k = 3 时，应当返回: 3->2->1->4->5

    说明 :
    你的算法只能使用常数的额外空间。
    你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
    */
    ListNode* reverseKGroup(ListNode* head, int k);


    /*028
    28. 实现 strStr()
    实现 strStr() 函数。
    给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

    示例 1:
    输入: haystack = "hello", needle = "ll"
    输出: 2
    
    示例 2:
    输入: haystack = "aaaaa", needle = "bba"
    输出: -1

    说明:
    当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
    对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
    */
    int strStr(string haystack, string needle);


    /*030
    30. 串联所有单词的子串
    给定一个字符串 s 和一些长度相同的单词 words。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。
    注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序。

    示例 1：
    输入：
    s = "barfoothefoobarman",
    words = ["foo","bar"]
    输出：[0,9]
    解释：
    从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar" 。
    输出的顺序不重要, [9,0] 也是有效答案。

    示例 2：
    输入：
    s = "wordgoodgoodgoodbestword",
    words = ["word","good","best","word"]
    输出：[]
    */
    vector<int> findSubstring(string s, vector<string>& words);


	/*032
	32. 最长有效括号
	给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。

	示例 1:
	输入: "(()"
	输出: 2
	解释: 最长有效括号子串为 "()"

	示例 2:
	输入: ")()())"
	输出: 4
	解释: 最长有效括号子串为 "()()"
	*/
	int longestValidParentheses(string s);


	/*038
	38. 外观数列
	「外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。前五项如下：
	1.     1
	2.     11
	3.     21
	4.     1211
	5.     111221
	1 被读作  "one 1"  ("一个一") , 即 11。
	11 被读作 "two 1s" ("两个一"）, 即 21。
	21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。

	给定一个正整数 n（1 ≤ n ≤ 30），输出外观数列的第 n 项。
	注意：整数序列中的每一项将表示为一个字符串。

	示例 1:
	输入: 1
	输出: "1"

	示例 2:
	输入: 4
	输出: "1211"
	*/
	string countAndSay(int n);


    /*036
    36. 有效的数独
    判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。
    1.数字 1-9 在每一行只能出现一次。
    2.数字 1-9 在每一列只能出现一次。
    3.数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。

    https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png
    上图是一个部分填充的有效的数独。

    数独部分空格内已填入了数字，空白格用 '.' 表示。

    示例 1:
    输入:
    [
      ["5","3",".",".","7",".",".",".","."],
      ["6",".",".","1","9","5",".",".","."],
      [".","9","8",".",".",".",".","6","."],
      ["8",".",".",".","6",".",".",".","3"],
      ["4",".",".","8",".","3",".",".","1"],
      ["7",".",".",".","2",".",".",".","6"],
      [".","6",".",".",".",".","2","8","."],
      [".",".",".","4","1","9",".",".","5"],
      [".",".",".",".","8",".",".","7","9"]
    ]
    输出: true

    示例 2:
    输入:
    [
      ["8","3",".",".","7",".",".",".","."],
      ["6",".",".","1","9","5",".",".","."],
      [".","9","8",".",".",".",".","6","."],
      ["8",".",".",".","6",".",".",".","3"],
      ["4",".",".","8",".","3",".",".","1"],
      ["7",".",".",".","2",".",".",".","6"],
      [".","6",".",".",".",".","2","8","."],
      [".",".",".","4","1","9",".",".","5"],
      [".",".",".",".","8",".",".","7","9"]
    ]
    输出: false

    解释: 除了第一行的第一个数字从 5 改为 8 以外，空格内其他数字均与 示例1 相同。
         但由于位于左上角的 3x3 宫内有两个 8 存在, 因此这个数独是无效的。

    说明:
    一个有效的数独（部分已被填充）不一定是可解的。
    只需要根据以上规则，验证已经填入的数字是否有效即可。
    给定数独序列只包含数字 1-9 和字符 '.' 。
    给定数独永远是 9x9 形式的。
    */
    bool isValidSudoku(vector<vector<char>>& board);


    /*037
    37. 解数独
    编写一个程序，通过已填充的空格来解决数独问题。

    一个数独的解法需遵循如下规则：
    数字 1-9 在每一行只能出现一次。
    数字 1-9 在每一列只能出现一次。
    数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
    空白格用 '.' 表示。

    https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png
    一个数独。

    https://upload.wikimedia.org/wikipedia/commons/thumb/3/31/Sudoku-by-L2G-20050714_solution.svg/250px-Sudoku-by-L2G-20050714_solution.svg.png
    答案被标成红色。

    Note:
    给定的数独序列只包含数字 1-9 和字符 '.' 。
    你可以假设给定的数独只有唯一解。
    给定数独永远是 9x9 形式的。
    */
    void solveSudoku(vector<vector<char> > &board);


	/*043
	43. 字符串相乘
	给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

	示例 1:

	输入: num1 = "2", num2 = "3"
	输出: "6"
	示例 2:

	输入: num1 = "123", num2 = "456"
	输出: "56088"
	说明：

	num1 和 num2 的长度小于110。
	num1 和 num2 只包含数字 0-9。
	num1 和 num2 均不以零开头，除非是数字 0 本身。
	不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
	*/
	string multiply(string num1, string num2);


    /*056
    56. 合并区间
    给出一个区间的集合，请合并所有重叠的区间。

    示例 1:
    输入: [[1,3],[2,6],[8,10],[15,18]]
    输出: [[1,6],[8,10],[15,18]]
    解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].

    示例 2:
    输入: [[1,4],[4,5]]
    输出: [[1,5]]
    解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
    */
    vector<vector<int>> merge(vector<vector<int>>& intervals);


    /*057
    57. 插入区间
    给出一个无重叠的 ，按照区间起始端点排序的区间列表。
    在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。

    示例 1:
    输入: intervals = [[1,3],[6,9]], newInterval = [2,5]
    输出: [[1,5],[6,9]]

    示例 2:
    输入: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
    输出: [[1,2],[3,10],[12,16]]
    解释: 这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。
    */
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval);


	/*058
	58. 最后一个单词的长度
	给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。
	如果不存在最后一个单词，请返回 0 。
	说明：一个单词是指由字母组成，但不包含任何空格的字符串。

	示例:
	输入: "Hello World"
	输出: 5
	*/
	int lengthOfLastWord(string s);

    /*061
    61. 旋转链表
    给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

    示例 1:
    输入: 1->2->3->4->5->NULL, k = 2
    输出: 4->5->1->2->3->NULL
    解释:
    向右旋转 1 步: 5->1->2->3->4->NULL
    向右旋转 2 步: 4->5->1->2->3->NULL

    示例 2:
    输入: 0->1->2->NULL, k = 4
    输出: 2->0->1->NULL
    解释:
    向右旋转 1 步: 2->0->1->NULL
    向右旋转 2 步: 1->2->0->NULL
    向右旋转 3 步: 0->1->2->NULL
    向右旋转 4 步: 2->0->1->NULL
    */
    ListNode* rotateRight(ListNode* head, int k);

    /*082
    82. 删除排序链表中的重复元素 II
    给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

    示例 1:
    输入: 1->2->3->3->4->4->5
    输出: 1->2->5

    示例 2:
    输入: 1->1->1->2->3
    输出: 2->3
    */
    ListNode* deleteDuplicates(ListNode* head);

    /*083
    83. 删除排序链表中的重复元素
    给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

    示例 1:
    输入: 1->1->2
    输出: 1->2

    示例 2:
    输入: 1->1->2->3->3
    输出: 1->2->3
    */
    ListNode* deleteDuplicatesOne(ListNode* head);


    /*086
    86. 分隔链表
    给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
    你应当保留两个分区中每个节点的初始相对位置。

    示例:
    输入: head = 1->4->3->2->5->2, x = 3
    输出: 1->2->2->4->3->5
    */
    ListNode* partition(ListNode* head, int x);


    /*092
    92. 反转链表 II
    反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
    说明:
    1 ≤ m ≤ n ≤ 链表长度。

    示例:
    输入: 1->2->3->4->5->NULL, m = 2, n = 4
    输出: 1->4->3->2->5->NULL
    */
    ListNode* reverseBetween(ListNode* head, int m, int n);


    /*94
    94. 二叉树的中序遍历
    给定一个二叉树，返回它的中序 遍历。

    示例:
    输入: [1,null,2,3]
       1
        \
         2
        /
       3
    输出: [1,3,2]

    进阶: 递归算法很简单，你可以通过迭代算法完成吗？
    */
    void inOder(TreeNode* root, vector<int>& ans);
    vector<int> inorderTraversal(TreeNode* root);


    /*95
    95. 不同的二叉搜索树 II
    给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。

    示例:
    输入: 3
    输出:
    [
      [1,null,3,2],
      [3,2,null,1],
      [3,1,null,null,2],
      [2,1,3],
      [1,null,2,null,3]
    ]
    解释:
    以上的输出对应以下 5 种不同结构的二叉搜索树：
       1         3     3      2      1
        \       /     /      / \      \
         3     2     1      1   3      2
        /     /       \                 \
       2     1         2                 3
    */
    vector<TreeNode*>* createBST(int begin, int end);
    vector<TreeNode*> generateTrees(int n);


    /*96
    96. 不同的二叉搜索树
    给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？

    示例:
    输入: 3
    输出: 5
    解释:
    给定 n = 3, 一共有 5 种不同结构的二叉搜索树:

       1         3     3      2      1
        \       /     /      / \      \
         3     2     1      1   3      2
        /     /       \                 \
       2     1         2                 3
    */
    int numTrees(int n);


    /*98
    98. 验证二叉搜索树
    给定一个二叉树，判断其是否是一个有效的二叉搜索树。
    假设一个二叉搜索树具有如下特征：
    节点的左子树只包含小于当前节点的数。
    节点的右子树只包含大于当前节点的数。
    所有左子树和右子树自身必须也是二叉搜索树。

    示例 1:
    输入:
        2
       / \
      1   3
    输出: true

    示例 2:
    输入:
        5
       / \
      1   4
         / \
        3   6
    输出: false

    解释: 输入为: [5,1,4,null,null,3,6]。
         根节点的值为 5 ，但是其右子节点值为 4 。
    */
    bool is_valid_BST;
    void inOderIsValidBST(TreeNode* root);
    bool isValidBST(TreeNode* root);

    /*99
    99. 恢复二叉搜索树
    二叉搜索树中的两个节点被错误地交换。
    请在不改变其结构的情况下，恢复这棵树。

    示例 1:
    输入: [1,3,null,null,2]
       1
      /
     3
      \
       2
    输出: [3,1,null,null,2]
       3
      /
     1
      \
       2

    示例 2:
    输入: [3,1,4,null,null,2]
      3
     / \
    1   4
       /
      2
    输出: [2,1,4,null,null,3]
      2
     / \
    1   4
       /
      3

    进阶:
    使用 O(n) 空间复杂度的解法很容易实现。
    你能想出一个只使用常数空间的解决方案吗？
    */
    TreeNode *p1, *p2, *p3, *p4, *last;
    void inOderRecoverTree(TreeNode* root);
    void recoverTree(TreeNode* root);


    /*100
    100. 相同的树
    给定两个二叉树，编写一个函数来检验它们是否相同。
    如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

    示例 1:
    输入:        1         1
                / \       / \
               2   3     2   3
    [1,2,3],   [1,2,3]
    输出: true

    示例 2:
    输入:        1          1
                /           \
               2             2
    [1,2],     [1,null,2]
    输出: false

    示例 3:
    输入:        1         1
                / \       / \
               2   1     1   2
    [1,2,1],   [1,1,2]
    输出: false
    */
    bool isSameTree(TreeNode* p, TreeNode* q);

    /*101
    101. 对称二叉树
    给定一个二叉树，检查它是否是镜像对称的。
    例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
        1
       / \
      2   2
     / \ / \
    3  4 4  3
    但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
     1
    / \
    2   2
     \   \
      3    3
    说明:
    如果你可以运用递归和迭代两种方法解决这个问题，会很加分。
    */
    bool isMirror(TreeNode* t1, TreeNode *t2);
    bool isSymmetric(TreeNode* root);


    /*102
    102. 二叉树的层次遍历
    给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。

    例如:
    给定二叉树: [3,9,20,null,null,15,7],
     3
    / \
    9  20
      /  \
     15   7
    返回其层次遍历结果：
    [
    [3],
    [9,20],
    [15,7]
    ]
    */
    vector<vector<int>> levelOrder(TreeNode* root);


    /*103
    103. 二叉树的锯齿形层次遍历
    给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

    例如：
    给定二叉树 [3,9,20,null,null,15,7],
        3
       / \
      9  20
        /  \
       15   7
    返回锯齿形层次遍历如下：
    [
      [3],
      [20,9],
      [15,7]
    ]
    */
    vector<vector<int>> zigzagLevelOrder(TreeNode* root);


    /*104
    104. 二叉树的最大深度
    给定一个二叉树，找出其最大深度。
    二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
    说明: 叶子节点是指没有子节点的节点。

    示例：
    给定二叉树 [3,9,20,null,null,15,7]，
        3
       / \
      9  20
        /  \
       15   7
    返回它的最大深度 3 。
    */
    int maxDepth(TreeNode* root);


    /*105
    105. 从前序与中序遍历序列构造二叉树
    根据一棵树的前序遍历与中序遍历构造二叉树。
    注意:
    你可以假设树中没有重复的元素。

    例如，给出
    前序遍历 preorder = [3,9,20,15,7]
    中序遍历 inorder = [9,3,15,20,7]
    返回如下的二叉树：
        3
       / \
      9  20
        /  \
       15   7
    */
    TreeNode* build(vector<int>::const_iterator pre1, vector<int>::const_iterator pre2,
        vector<int>::const_iterator in1, vector<int>::const_iterator in2);
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);


    /*106
    106. 从中序与后序遍历序列构造二叉树
    根据一棵树的中序遍历与后序遍历构造二叉树。
    注意:
    你可以假设树中没有重复的元素。

    例如，给出
    中序遍历 inorder = [9,3,15,20,7]
    后序遍历 postorder = [9,15,7,20,3]
    返回如下的二叉树：
        3
       / \
      9  20
        /  \
       15   7
    */
    TreeNode* buildTree_in_post(vector<int>& inorder, vector<int>& postorder);


    /*107
    107. 二叉树的层次遍历 II
    给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

    例如：
    给定二叉树 [3,9,20,null,null,15,7],
        3
       / \
      9  20
        /  \
       15   7
    返回其自底向上的层次遍历为：
    [
      [15,7],
      [9,20],
      [3]
    ]
    */
    vector<vector<int>> levelOrderBottom(TreeNode* root);


    /*108
    108. 将有序数组转换为二叉搜索树
    将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
    本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

    示例:
    给定有序数组: [-10,-3,0,5,9],
    一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：
          0
         / \
       -3   9
       /   /
     -10  5
    */
    TreeNode* sortedArrayToBST(vector<int>& nums, int const& begin, int const& end);
    TreeNode* sortedArrayToBST(vector<int>& nums);

    /*109
    109. 有序链表转换二叉搜索树
    给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。
    本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

    示例:
    给定的有序链表： [-10, -3, 0, 5, 9],
    一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：

          0
         / \
       -3   9
       /   /
     -10  5
    */
    TreeNode* sortedListToBST(ListNode* head, ListNode* tail);
    TreeNode* sortedListToBST(ListNode* head);


    /*110
    110. 平衡二叉树
    给定一个二叉树，判断它是否是高度平衡的二叉树。
    本题中，一棵高度平衡二叉树定义为：
    一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。

    示例 1:
    给定二叉树 [3,9,20,null,null,15,7]
        3
       / \
      9  20
        /  \
       15   7
    返回 true 。

    示例 2:
    给定二叉树 [1,2,2,3,3,null,null,4,4]
           1
          / \
         2   2
        / \
       3   3
      / \
     4   4
    返回 false 。
    */
    bool isBalanced(TreeNode* root);


    /*111
    111. 二叉树的最小深度
    给定一个二叉树，找出其最小深度。
    最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
    说明: 叶子节点是指没有子节点的节点。

    示例:
    给定二叉树 [3,9,20,null,null,15,7],
        3
       / \
      9  20
        /  \
       15   7
    返回它的最小深度  2.
    */
    int minDepth(TreeNode* root);


    /*112
    112. 路径总和
    给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。
    说明: 叶子节点是指没有子节点的节点。

    示例:
    给定如下二叉树，以及目标和 sum = 22，
                  5
                 / \
                4   8
               /   / \
              11  13  4
             /  \      \
            7    2      1
    返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。
    */
    bool hasPathSum(TreeNode* root, int sum);


    /*113
    113. 路径总和 II
    给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
    说明: 叶子节点是指没有子节点的节点。

    示例:
    给定如下二叉树，以及目标和 sum = 22，
                  5
                 / \
                4   8
               /   / \
              11  13  4
             /  \    / \
            7    2  5   1
    返回:
    [
       [5,4,11,2],
       [5,8,4,5]
    ]
    */
    void dfsPathSum(vector<vector<int>>& res, vector<int>& path, TreeNode* root, int sum);
    vector<vector<int>> pathSum(TreeNode* root, int sum);


    /*114
    114. 二叉树展开为链表
    给定一个二叉树，原地将它展开为链表。

    例如，给定二叉树
        1
       / \
      2   5
     / \   \
    3   4   6
    将其展开为：
    1
     \
      2
       \
        3
         \
          4
           \
            5
             \
              6
    */
    void postOrder(TreeNode* root);
    void flatten(TreeNode* root);


    /*116
    116. 填充每个节点的下一个右侧节点指针
    给定一个完美二叉树，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：
    https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/02/15/116_sample.png
    struct Node {
        int val;
        Node *left;
        Node *right;
        Node *next;
    }
    填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
    初始状态下，所有 next 指针都被设置为 NULL。

    示例：
    输入：{ "$id":"1","left" : {"$id":"2","left" : {"$id":"3","left" : null,"next" : null,"right" : null,"val" : 4},"next" : null,"right" : {"$id":"4","left" : null,"next" : null,"right" : null,"val" : 5},"val" : 2},"next" : null,"right" : {"$id":"5","left" : {"$id":"6","left" : null,"next" : null,"right" : null,"val" : 6},"next" : null,"right" : {"$id":"7","left" : null,"next" : null,"right" : null,"val" : 7},"val" : 3},"val" : 1 }
    输出：{ "$id":"1","left" : {"$id":"2","left" : {"$id":"3","left" : null,"next" : {"$id":"4","left" : null,"next" : {"$id":"5","left" : null,"next" : {"$id":"6","left" : null,"next" : null,"right" : null,"val" : 7},"right" : null,"val" : 6},"right" : null,"val" : 5},"right" : null,"val" : 4},"next" : {"$id":"7","left" : {"$ref":"5"},"next" : null,"right" : {"$ref":"6"},"val" : 3},"right" : {"$ref":"4"},"val" : 2},"next" : null,"right" : {"$ref":"7"},"val" : 1 }

    解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。

    提示：
    你只能使用常量级额外空间。
    使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。
    */
    Node* connect(Node* root);


    /*117
    117. 填充每个节点的下一个右侧节点指针 II
    */
    Node* connect2(Node* root);


    /*124
    124. 二叉树中的最大路径和
    给定一个非空二叉树，返回其最大路径和。
    本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。

    示例 1:
    输入: [1,2,3]

           1
          / \
         2   3

    输出: 6

    示例 2:
    输入: [-10,9,20,null,null,15,7]

       -10
       / \
      9  20
        /  \
       15   7
    输出: 42
    */
    int maxPathSum(TreeNode* root);

    /*129
    129. 求根到叶子节点数字之和
    给定一个二叉树，它的每个结点都存放一个 0-9 的数字，每条从根到叶子节点的路径都代表一个数字。
    例如，从根到叶子节点路径 1->2->3 代表数字 123。
    计算从根到叶子节点生成的所有数字之和。
    说明: 叶子节点是指没有子节点的节点。

    示例 1:
    输入: [1,2,3]
        1
       / \
      2   3
    输出: 25
    解释:
    从根到叶子节点路径 1->2 代表数字 12.
    从根到叶子节点路径 1->3 代表数字 13.
    因此，数字总和 = 12 + 13 = 25.

    示例 2:
    输入: [4,9,0,5,1]
        4
       / \
      9   0
     / \
    5   1
    输出: 1026
    解释:
    从根到叶子节点路径 4->9->5 代表数字 495.
    从根到叶子节点路径 4->9->1 代表数字 491.
    从根到叶子节点路径 4->0 代表数字 40.
    因此，数字总和 = 495 + 491 + 40 = 1026.
    */
    int sumNumbers(TreeNode* root);


    /*133
    133. 克隆图
    给定无向连通图中一个节点的引用，返回该图的深拷贝（克隆）。图中的每个节点都包含它的值 val（Int） 和其邻居的列表（list[Node]）。

    示例：
    https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/02/23/113_sample.png

    输入：
    {
	    "$id": "1",
	    "neighbors": [{
			    "$id": "2",
			    "neighbors": [{
					    "$ref": "1"
				    }, {
					    "$id": "3",
					    "neighbors": [{
							    "$ref": "2"
						    }, {
							    "$id": "4",
							    "neighbors": [{
									    "$ref": "3"
								    }, {
									    "$ref": "1"
								    }
							    ],
							    "val": 4
						    }
					    ],
					    "val": 3
				    }
			    ],
			    "val": 2
		    }, {
			    "$ref": "4"
		    }
	    ],
	    "val": 1
    }

    解释：
    节点 1 的值是 1，它有两个邻居：节点 2 和 4 。
    节点 2 的值是 2，它有两个邻居：节点 1 和 3 。
    节点 3 的值是 3，它有两个邻居：节点 2 和 4 。
    节点 4 的值是 4，它有两个邻居：节点 1 和 3 。

    提示：
    节点数介于 1 到 100 之间。
    无向图是一个简单图，这意味着图中没有重复的边，也没有自环。
    由于图是无向的，如果节点 p 是节点 q 的邻居，那么节点 q 也必须是节点 p 的邻居。
    必须将给定节点的拷贝作为对克隆图的引用返回。
    */
    UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node);

    /*144
    144. 二叉树的前序遍历
    给定一个二叉树，返回它的 前序 遍历。

     示例:
    输入: [1,null,2,3]
       1
        \
         2
        /
       3
    输出: [1,2,3]

    进阶: 递归算法很简单，你可以通过迭代算法完成吗？
    */
    vector<int> preorderTraversal(TreeNode* root);

    /*145
    145. 二叉树的后序遍历
    给定一个二叉树，返回它的 后序 遍历。

    示例:
    输入: [1,null,2,3]
       1
        \
         2
        /
       3
    输出: [3,2,1]
    */
    vector<int> postorderTraversal(TreeNode* root);


    /*199
    199. 二叉树的右视图
    给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

    示例:
    输入: [1,2,3,null,5,null,4]
    输出: [1, 3, 4]
    解释:
       1            <---
     /   \
    2     3         <---
     \     \
      5     4       <---
    */
    vector<int> rightSideView(TreeNode* root);


    /*215
    215. 数组中的第K个最大元素
    在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

    示例 1:
    输入: [3,2,1,5,6,4] 和 k = 2
    输出: 5

    示例 2:
    输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
    输出: 4

    说明:
    你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。
    */
    int findKthLargest(vector<int>& nums, int k);


    /*222
    222. 完全二叉树的节点个数
    给出一个完全二叉树，求出该树的节点个数。
    说明：
    完全二叉树的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~ 2h 个节点。

    示例:
    输入: 
        1
       / \
      2   3
     / \  /
    4  5 6
    输出: 6
    */
    int countNodes(TreeNode* root);


    /*226
    226. 翻转二叉树
    翻转一棵二叉树。

    示例：
    输入：
         4
       /   \
      2     7
     / \   / \
    1   3 6   9
    输出：
         4
       /   \
      7     2
     / \   / \
    9   6 3   1
    */
    TreeNode* invertTree(TreeNode* root);


    /*230
    230. 二叉搜索树中第K小的元素
    给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。
    说明：
    你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。

    示例 1:
    输入: root = [3,1,4,null,2], k = 1
       3
      / \
     1   4
      \
       2
    输出: 1

    示例 2:
    输入: root = [5,3,6,2,4,null,null,1], k = 3
           5
          / \
         3   6
        / \
       2   4
      /
     1
    输出: 3

    进阶：
    如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k 小的值，你将如何优化 kthSmallest 函数？
    */
    int kthSmallest(TreeNode* root, int k);


    /*235
    235. 二叉搜索树的最近公共祖先
    给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
    百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
    例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]
    https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/14/binarysearchtree_improved.png

    示例 1:
    输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
    输出: 6 
    解释: 节点 2 和节点 8 的最近公共祖先是 6。

    示例 2:
    输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
    输出: 2
    解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身。

    说明:
    所有节点的值都是唯一的。
    p、q 为不同节点且均存在于给定的二叉搜索树中。
    */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);


    /*236
    236. 二叉树的最近公共祖先
    给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
    百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
    例如，给定如下二叉树:  root = [3,5,1,6,2,0,8,null,null,7,4]
    https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/15/binarytree.png

    示例 1:
    输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
    输出: 3
    解释: 节点 5 和节点 1 的最近公共祖先是节点 3。

    示例 2:
    输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
    输出: 5
    解释: 节点 5 和节点 4 的最近公共祖先是节点 5。因为根据定义最近公共祖先节点可以为节点本身。
 
    说明:
    所有节点的值都是唯一的。
    p、q 为不同节点且均存在于给定的二叉树中。
    */
    TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q);


    /*239
    239. 滑动窗口最大值
    给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口 k 内的数字。滑动窗口每次只向右移动一位。
    返回滑动窗口最大值。

    示例:
    输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
    输出: [3,3,5,5,6,7]

    解释:
    滑动窗口的位置                最大值
    ---------------               -----
    [1  3  -1] -3  5  3  6  7       3
    1 [3  -1  -3] 5  3  6  7       3
    1  3 [-1  -3  5] 3  6  7       5
    1  3  -1 [-3  5  3] 6  7       5
    1  3  -1  -3 [5  3  6] 7       6
    1  3  -1  -3  5 [3  6  7]      7

    注意：
    你可以假设 k 总是有效的，1 ≤ k ≤ 输入数组的大小，且输入数组不为空。

    进阶：
    你能在线性时间复杂度内解决此题吗？
    */
    vector<int> maxSlidingWindow(vector<int>& nums, size_t k);


    /*257
    257. 二叉树的所有路径
    给定一个二叉树，返回所有从根节点到叶子节点的路径。
    说明: 叶子节点是指没有子节点的节点。

    示例:
    输入:
       1
     /   \
    2     3
     \
      5
    输出: ["1->2->5", "1->3"]

    解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3
    */
    vector<string> binaryTreePaths(TreeNode* root);


    /*264
    264. 丑数 II
    编写一个程序，找出第 n 个丑数。
    丑数就是只包含质因数 2, 3, 5 的正整数。

    示例:
    输入: n = 10
    输出: 12

    解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。

    说明:  
    1 是丑数。
    n 不超过1690。
    */
    int nthUglyNumber(int n);


    /*313
    313. 超级丑数
    编写一段程序来查找第 n 个超级丑数。
    超级丑数是指其所有质因数都是长度为 k 的质数列表 primes 中的正整数。

    示例:
    输入: n = 12, primes = [2,7,13,19]
    输出: 32 

    解释: 给定长度为 4 的质数列表 primes = [2,7,13,19]，前 12 个超级丑数序列为：[1,2,4,7,8,13,14,16,19,26,28,32] 。
    
    说明:
    1 是任何给定 primes 的超级丑数。
     给定 primes 中的数字以升序排列。
    0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000 。
    第 n 个超级丑数确保在 32 位有符整数范围内。
    */
    int nthSuperUglyNumber(int n, vector<int>& primes);
};
#endif  //SOLUTION_H

