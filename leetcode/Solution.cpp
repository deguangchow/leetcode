///    Copyright (C) 2018 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    Leetcode Solution：结题方案
///
///    \author   deguangchow
///    \version  1.0
///    \2019/01/08

#include "stdafx.h"
#include "Solution.h"


//001
vector<int> Solution::twoSum(vector<int>& nums, int target) {
#if 0//暴力解法
    unsigned len = nums.size();
    for (int i = 0; i < len - 1; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (target == nums[i] + nums[j]) {
                return{ i, j };
            }
        }
    }
    return{ -1, -1 };
#else//map
    int const& len = nums.size();
    map<int, int> mapNumIndex;
    for (int i = 0; i < len; ++i) {
        int const& num = nums[i];
        if (mapNumIndex.find(num) == mapNumIndex.end()) {
            mapNumIndex[num] = i;
        }
        auto const& pos = mapNumIndex.find(target - num);
        if (pos == mapNumIndex.end()) {
            continue;
        }
        if (pos->second == i) {
            continue;
        }
        return{ i, pos->second };
    }
    return{ -1, -1 };
#endif
}


//002
ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
    unsigned sum = 0;//每位之间的数字相加之和
    ListNode* ret = l1;
    ListNode* p = nullptr;
    while (l1 && l2) {
        p = l1;
        sum += l1->val + l2->val;
        l1->val = sum % 10;
        sum = sum / 10;
        l1 = l1->next;
        l2 = l2->next;
    }
    if (l1) {
        p->next = l1;
        while (l1) {
            p = l1;
            sum += l1->val;
            l1->val = sum % 10;
            sum = sum / 10;
            l1 = l1->next;
        }
    }
    if (l2) {
        p->next = l2;
        while (l2) {
            p = l2;
            sum += l2->val;
            l2->val = sum % 10;
            sum = sum / 10;
            l2 = l2->next;
        }
    }
    if (sum) {
        p->next = new ListNode(sum);
    }

    return ret;
}


//003
int Solution::lengthOfLongestSubstring(string s) {
#if 0//滑动窗口（初版）
    unsigned size = s.length();
    int max = 0;
    int len = 0;
    char* p = &s[0];
    map<char, unsigned> mapCharIndex;
    for (auto i = 0; i < size; ++i) {
        char & c = s[i];
        auto const& pos = mapCharIndex.find(s[i]);
        if (pos == mapCharIndex.end()) {
            mapCharIndex[c] = i;
        }
        len = mapCharIndex.size();
        if (len > max) {
            max = len;
        }
        if (pos == mapCharIndex.end()) {
            continue;
        }
        char* end = &s[pos->second];
        ++end;
        while (p && (p != end)) {
            mapCharIndex.erase(*p);
            ++p;
        }
        mapCharIndex[c] = i;
    }

    return max;
#else//滑动窗口（优化版）
    int n = s.length();
    int ans = 0;
    map<char, int> mapCharIndex;
    for (auto j = 0, i = 0; j < n; ++j) {
        auto const& pos = mapCharIndex.find(s[j]);
        if (pos != mapCharIndex.end()) {
            i = std::max(i, pos->second);
        }
        ans = std::max(ans, j - i + 1);
        mapCharIndex[s[j]] = j + 1;
    }

    return ans;
#endif
}


//004
double Solution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
#if 0//递归实现（未通过全部单元测试）
    auto size1 = nums1.size();
    auto min1 = nums1[0];
    auto max1 = nums1[size1 - 1];

    auto size2 = nums2.size();
    auto min2 = nums2[0];
    auto max2 = nums2[size2 - 1];

    if (max1 <= min2) {
        if (size1 > size2) {
            auto pos = (size1 - size2) / 2;
            auto mod = (size1 - size2) % 2;
            if (mod) {
                return nums1[size2 + pos];
            } else {
                return (nums1[size2 + pos] + nums1[size2 + pos + 1]) / 2.0;
            }
        } else if (size1 < size2) {
            auto pos = (size2 - size1) / 2;
            auto mod = (size2 - size1) % 2;
            if (mod) {
                return nums2[pos];
            } else {
                return (nums2[pos] + nums2[pos + 1]) / 2.0;
            }
        } else {
            return (max1 + min2) / 2.0;
        }
    } else if (min1 >= max2) {
        return findMedianSortedArrays(nums2, nums1);
    } else {
        auto pos_mid1 = size1 / 2;
        auto mod1 = size1 % 2;
        auto mid1 = nums1[pos_mid1];

        auto pos_mid2 = size2 / 2;
        auto mod2 = size2 % 2;
        auto mid2 = nums2[pos_mid2];

        if (mid1 >= mid2) {
            vector<int> nums1_left;
            nums1_left.insert(nums1_left.end(), nums1.begin(), nums1.begin() + pos_mid1 + mod1);
            vector<int> nums2_right;
            nums2_right.insert(nums2_right.end(), nums2.begin() + pos_mid2, nums2.end());
            return findMedianSortedArrays(nums1_left, nums2_right);
        } else {
            vector<int> nums1_right;
            nums1_right.insert(nums1_right.end(), nums1.begin() + pos_mid1, nums1.end());
            vector<int> nums2_left;
            nums2_left.insert(nums2_left.end(), nums2.begin(), nums2.begin() + pos_mid2 + mod2);
            return findMedianSortedArrays(nums1_right, nums2_left);
        }
    }
#else//官方题解：递归思想，循环实现
    int m = nums1.size();
    int n = nums2.size();
    if (m > n) {
        nums1.swap(nums2);
        m = n;
        n = nums2.size();
    }
    int iMin = 0, iMax = m, halfLen = (m + n + 1) / 2;
    while (iMin <= iMax) {
        int i = (iMin + iMax) / 2;
        int j = halfLen - i;
        if (i<iMax && nums2[j - 1]>nums1[i]) {
            iMin = i + 1;//i is too small
        } else if (i > iMin && nums1[i - 1] > nums2[j]) {
            iMax = i - 1;//i is too big
        } else {//i is perfect
            int maxLeft = 0;
            if (i == 0) {
                maxLeft = nums2[j - 1];
            } else if (j == 0) {
                maxLeft = nums1[i - 1];
            } else {
                maxLeft = std::max(nums1[i - 1], nums2[j - 1]);
            }
            if ((m + n) % 2 == 1) {
                return maxLeft;
            }

            int minRight = 0;
            if (i == m) {
                minRight = nums2[j];
            } else if (j == n) {
                minRight = nums1[i];
            } else {
                minRight = std::min(nums2[j], nums1[i]);
            }

            return (maxLeft + minRight) / 2.0;
        }
    }
    return 0.0;
#endif
}


//005
string Solution::longestPalindrome(string s) {
#if 1
    int nLength = s.length();
    if (nLength <= 1) {
        return s;
    }
    int nPos = 0;
    int nLengthRet = 1;
    int nPos1 = 0;
    int nPos2 = 0;
    int i = 0;
    int j = nLength - 1;
    while (i < nLength - nLengthRet) {
        while (j >= i + nLengthRet) {
            nPos1 = i;
            nPos2 = j;
            while (s[nPos1] == s[nPos2]) {
                if (nPos2 - nPos1 <= 1) {
                    if (j - i + 1 > nLengthRet) {
                        nPos = i;
                        nLengthRet = j - i + 1;
                        i = nPos1 - 1;
                    }
                    break;
                } else {
                    ++nPos1;
                    --nPos2;
                }
            }
            --j;
        }
        ++i;
        j = nLength - 1;
    }
    return s.substr(nPos, nLengthRet);
#else
    if (s.empty()) return "";
    int begin(0);
    int end(0);
    int next(0);
    int m_b(0), m_e(0);
    while (next < s.size() - 1) {
        begin = next;
        end = begin;
        while (s[end + 1] == s[begin] && end < s.size() - 1) {
            end++;
        }
        next = end;
        while (begin > 0 && end < s.size() - 1 && s[begin - 1] == s[end + 1]) {
            begin--;
            end++;
        }
        if (end - begin > m_e - m_b) {
            m_b = begin;
            m_e = end;
        }
        next++;
    }
    return s.substr(m_b, m_e - m_b + 1);
#endif
}


string Solution::convert(string s, int numRows) {
    if (numRows < 2) {
        return s;
    }
    string sRet = "";
    int nLength = s.length();
    for (int i = 0; i < numRows; ++i) {
        bool bLeft = false;
        int m = 2 * (numRows - 1 - i);
        int n = 2 * i;
        if (n == 0) {
            n = m;
        }
        if (m == 0) {
            m = n;
        }
        for (int j = i; j < nLength; j = j + (bLeft ? m : n)) {
            bLeft = !bLeft;
            sRet += s[j];
        }
    }
    return sRet;
}


//007
int Solution::reverse(int x) {
    long long nRet = 0;

    do {
        nRet = nRet * 10 + x % 10;
        x = x / 10;
    } while (x / 10 || x % 10);

    if (nRet < INT_MIN || nRet > INT_MAX) {
        return 0;
    }

    return nRet;
}


//008
int Solution::myAtoi(string str) {
    long long nRet = 0;
    int nSign = 1;
    bool bSignSetted = false;

    for (int i = 0; i < str.length(); ++i) {
        if (!bSignSetted && (str[i] == '-' || str[i] == '+')) {
            bSignSetted = true;
            if (str[i] == '-') {
                nSign = -1;
            }
        } else if (str[i] < '0' || str[i] > '9') {
            if (!bSignSetted && str[i] == ' ') {
                continue;
            } else {
                break;
            }
        } else {
            bSignSetted = true;
            nRet = nRet * 10 + (str[i] - '0');
            if (nRet > INT_MAX) {
                break;
            }
        }
    }

    nRet *= nSign;

    if (nRet < INT_MIN) {
        return INT_MIN;
    }
    if (nRet > INT_MAX) {
        return INT_MAX;
    }

    return nRet;
}


//009
bool Solution::isPalindrome(int x) {
#if 0
    //转字符串
    if (x < 0) {
        return false;
    }
    string s = "";
    do {
        char c = ('0' + x % 10);
        s = c + s;
        x = x / 10;
    } while (x / 10 || x % 10);

    int i = 0;
    int j = s.length() - 1;
    while (i < j) {
        if (s[i] != s[j]) {
            return false;
        }
        ++i;
        --j;
    }
    return true;
#else
    if (x < 0) {
        return false;
    }
    if (x < 10) {
        return true;
    }
    int nDivisor = 10;
    while (x / nDivisor >= 10) {
        nDivisor *= 10;
    }
    while (x > 0) {
        if (x / nDivisor != x % 10) {
            return false;
        }
        x = x%nDivisor / 10;
        nDivisor /= 100;
    }
    return true;
#endif
}


//010
//比较 s 和 p 是否相等：相等的规则即为正则表达式要求。
#if 0
//解答错误。未考虑以下等场景：
/*
"aaa"
"a*a"

"aaa"
"ab*a*c*a"

"bbbba"
".*a*a"

"ab"
".*c"

因为 * 的不确定性，需回溯来试错。
*/
bool Solution::isMatch(string s, string p) {
    int i = 0;
    int j = 0;
    bool bBreak = false;
    while (i < s.length() && j < p.length()) {
        switch (p[j]) {
        case '.':
            ++i;
            ++j;
            break;
        case '*':
            if (j > 0) {
                if (s[i] == p[j - 1] || p[j - 1] == '.') {
                    ++i;
                    if (i == s.length()) {
                        ++j;
                    }
                }
                else {
                    ++j;
                }
            }
            else {
                ++j;
            }
            break;
        default:
            if (s[i] == p[j]) {
                ++i;
                ++j;
            }
            else {
                if (j + 1 < p.length() && p[j + 1] != '*') {
                    bBreak = true;
                }
                else {
                    j += 2;
                }
            }
            break;
        }
        if (bBreak) {
            break;
        }
    }

    return i == s.length() && j == p.length();
}
#else
//递归法
bool doMatch(const char *s, const char *p) {
    if (*p == '\0') {
        return *s == '\0';
    }

    auto bPreMatched = (*s != '\0') && (*s == *p || *p == '.');

    if (*(p + 1) == '*') {
        //先试错：假设 X* 的个数为0的情况。
        //再进行s的下一位 和 X 的比较处理。
        return doMatch(s, p + 2) || (bPreMatched && doMatch(++s, p));
    } else {
        return bPreMatched && doMatch(++s, ++p);
    }
}
bool Solution::isMatch(string s, string p) {
    return doMatch(s.c_str(), p.c_str());
}
#endif


//011
int Solution::maxArea(vector<int>& height) {
	int i = 0, j = height.size() - 1, nMax = 0;
	while (i < j) {
		nMax = max(nMax, (j - i)*min(height[i], height[j]));
		height[i] < height[j] ? ++i : --j;
	}
	return nMax;
}


//012
string Solution::intToRoman(int num) {
    string sRet = "";

    char Roman1[] = { 'M', 'C', 'X', 'I' };
    int Number1[] = { 1000, 100, 10, 1 };

    char Roman5[] = { 'D', 'L', 'V' };
    int Number5[] = { 500, 50, 5 };

    for (int i = 0; i < 4 && num > 0; ++i) {
        int x = num / Number1[i];
        switch (x) {
        case 9:
            num -= x * Number1[i];
            sRet += Roman1[i];
            sRet += Roman1[i - 1];
            break;
        case 8:
        case 7:
        case 6:
        case 5:
            num -= Number5[i - 1];
            sRet += Roman5[i - 1];
            --i;
            break;
        case 4:
            num -= x * Number1[i];
            sRet += Roman1[i];
            sRet += Roman5[i - 1];
            break;
        case 3:
        case 2:
        case 1:
            num -= x * Number1[i];
            while (x-- > 0) {
                sRet += Roman1[i];
            }
            break;
        default:
            break;
        }
    }
    return sRet;
}


//013
int Solution::romanToInt(string s) {
    int nRet = 0;

    int nLength = s.length();
    for (int i = 0; i < nLength; ++i) {
        switch (s[i]) {
        case 'M':
            nRet += 1000;
            break;
        case 'D':
            nRet += 500;
            break;
        case 'C':
            if (s[i + 1] == 'M' || s[i + 1] == 'D') {
                nRet -= 100;
            } else {
                nRet += 100;
            }
            break;
        case 'L':
            nRet += 50;
            break;
        case 'X':
            if (s[i + 1] == 'C' || s[i + 1] == 'L') {
                nRet -= 10;
            } else {
                nRet += 10;
            }
            break;
        case 'V':
            nRet += 5;
            break;
        case 'I':
            if (s[i + 1] == 'X' || s[i + 1] == 'V') {
                nRet -= 1;
            } else {
                nRet += 1;
            }
            break;
        default:
            break;
        }
    }

    return nRet;
}


//014
string Solution::longestCommonPrefix(vector<string>& strs) {
    int nSize = strs.size();
    if (nSize < 1) {
        return "";
    }
    if (nSize == 1) {
        return strs[0];
    }
    string sRet = strs[0];
    int nLength = sRet.length();
    int i = 0;
    int j = 1;
    for (; i < nLength; ++i) {
        for (j = 1; j < nSize; ++j) {
            if (strs[j][i] != sRet[i]) {
                break;
            }
        }
        if (j < nSize) {
            break;
        }
    }
    return sRet.substr(0, i);
}


//015
//排序+三指针
#if 1
vector<vector<int>> Solution::threeSum(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	vector<vector<int>> vctRet;
	for (int i = 0; i < nums.size(); ++i) {
		int a = nums[i];
		if (a > 0) {
			break;
		}
		if (i > 0 && a == nums[i - 1]) {
			continue;
		}
		bool is_reset_a = true;
		int k_end = nums.size();
		for (int j = i + 1; j < k_end; ++j) {
			int b = nums[j];
			if (!is_reset_a && b == nums[j - 1]) {
				continue;
			}
			is_reset_a = false;
			for (int k = k_end - 1; k > j; --k) {
				int c = nums[k];
				if (a + b + c == 0) {
					vctRet.push_back({ a, b, c });
				}
				if (a + b + c <= 0) {
					k_end = k + 1;
					break;
				}
			}
		}
	}
	return vctRet;
}
#else
vector<vector<int>> Solution::threeSum(vector<int>& nums) {
	set<vector<int>> setCache;
	sort(nums.begin(), nums.end());
	vector<vector<int>> vctRet = {};
	int nSize = nums.size();
	int i = 0, j = nSize - 1, k = 1;
	while (k < nSize - 1) {
		while (i < k && k < j) {
			auto &&nSum = nums[i] + nums[k] + nums[j];
			if (nSum == 0) {
				vector<int> &&tmp = { nums[i], nums[k], nums[j] };
				if (setCache.find(tmp) == setCache.end()) {
					vctRet.push_back(tmp);
					setCache.insert(tmp);
				}
				++i;
				--j;
			} else if (nSum < 0) {
				++i;
			} else {
				--j;
			}
		}
		i = 0;
		j = nSize - 1;
		++k;
		while (k + 1 < nSize && nums[k - 1] == nums[k] && nums[k] == nums[k + 1]) {
			if (nums[k] == 0 && setCache.find({0,0,0}) == setCache.end()) {
				vctRet.push_back({ 0,0,0 });
				setCache.insert({ 0,0,0 });
			}
			++k;
		}
	}
	return vctRet;
}
#endif


//016
#if 1
//排序+坐标系（去重）+双指针+双向
int Solution::threeSumClosest(vector<int>& nums, int target) {
	sort(nums.begin(), nums.end());
	int sumI = 0;
	int minI = INT_MAX;
	int i, j, k;
	for (i = 0; i < nums.size() - 2; ++i) {
		int sumJ = 0;
		int minJ = INT_MAX;
		for (j = i + 1; j < nums.size() - 1; ++j) {
			int sumK = 0;
			int minK = INT_MAX;
			for (k = nums.size() - 1; k > j; --k) {
				auto &&tmpSum = nums[i] + nums[j] + nums[k];
				auto &&tmpMin = abs(target - tmpSum);
				if (0 == tmpMin) {
					return target;
				} else if (minK >= tmpMin) {
					sumK = tmpSum;
					minK = tmpMin;
				} else {
					break;
				}
			}
			if (minJ >= minK) {
				minJ = minK;
				sumJ = sumK;
			} else {
				break;
			}
		}
		if (minI >= minJ) {
			minI = minJ;
			sumI = sumJ;
		}
	}
	return sumI;
}
#else
int Solution::threeSumClosest(vector<int>& nums, int target) {
	sort(nums.begin(), nums.end());
	int ans = nums[0] + nums[1] + nums[2];
	for (int i = 0; i < nums.size(); i++) {
		int st = i + 1, ed = nums.size() - 1;
		while (st < ed) {
			int sum = nums[st] + nums[ed] + nums[i];
			if (abs(target - sum) < abs(target - ans)) {
				ans = sum;
			}
			if (sum == target) {
				return ans;
			} else if (sum < target) {
				st++;
			} else {
				ed--;
			}
		}
	}
	return ans;
}
#endif


//017
vector<string> Solution::letterCombinations(string digits) {
    static vector<string> vctPhoneKeys = {
        "abc",  // 电话按键：2
        "def",  // 电话按键：3
        "ghi",  // 电话按键：4
        "jkl",  // 电话按键：5
        "mno",  // 电话按键：6
        "pqrs", // 电话按键：7
        "tuv",  // 电话按键：8
        "wxyz"  // 电话按键：9
    };

    vector<string> vctRet;
    int nLength = digits.length();
    if (nLength < 1) {
        return vctRet;
    }

    int nRows = 1;
    vector<int> vctMod(nLength);
    for (int i = nLength - 1; i >= 0; --i) {
        vctMod[i] = nRows;
        nRows *= vctPhoneKeys[digits[i] - '2'].length();
    }

    for (int row = 0; row < nRows; ++row) {
        string s = "";
        for (int col = 0; col < nLength; ++col) {
            string &sKey = vctPhoneKeys[digits[col] - '2'];
            int index = row / vctMod[col] % sKey.length();
            s += sKey[index];
        }
        vctRet.push_back(s);
    }

    return vctRet;
}


//018
vector<vector<int>> Solution::fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    if (nums.empty()) {
        return res;
    }

    sort(nums.begin(), nums.end());//首先排序
    int const& size = nums.size();
    for (int i1 = 0; i1 < size; ++i1) {
        if (i1 > 0 && nums[i1] == nums[i1 - 1]) {
            continue;
        }

        int target3 = target - nums[i1];//4数变3数
        for (int i2 = i1 + 1; i2 < size; ++i2) {
            if (i2 > i1 + 1 && nums[i2] == nums[i2 - 1]) {
                continue;
            }

            int target2 = target3 - nums[i2];//3数变2数

                                             //2数之和
            int i3 = i2 + 1;
            int i4 = size - 1;
            while (i3 < i4) {
                if (nums[i3] + nums[i4] == target2) {
                    res.push_back({ nums[i1], nums[i2], nums[i3], nums[i4] });

                    //去重
                    while (i3 < i4 && nums[i3] == nums[i3 + 1]) {
                        ++i3;
                    }
                    while (i3 < i4 && nums[i4] == nums[i4 - 1]) {
                        --i4;
                    }
                    ++i3;
                    --i4;
                } else if (nums[i3] + nums[i4] < target2) {
                    ++i3;
                } else {
                    --i4;
                }
            }
        }
    }
    return res;
}


//019
ListNode* Solution::removeNthFromEnd(ListNode* head, int n) {
    ListNode* p_n = head;
    ListNode* p_end = head;
    for (auto i = 0; i < n; ++i) {
        p_end = p_end->next;
    }
    if (nullptr == p_end) {
        return head->next;
    }

    //多移动1个位置
    p_end = p_end->next;

    while (p_end) {
        p_n = p_n->next;
        p_end = p_end->next;
    }
    p_end = p_n->next;
    p_n->next = p_end->next;

    return head;
}



//020
bool Solution::isValid(string s) {
    stack<char> stk;
    char *p = &s[0];
    while (*p != '\0') {
        if (stk.empty() || *p - stk.top() != 1 && *p - stk.top() != 2) {
            stk.push(*p);
        } else {
            stk.pop();
        }
        ++p;
    }
    return stk.empty();
}


//021
ListNode* Solution::mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* ret = nullptr;
    ListNode* p = nullptr;
    while (l1 && l2) {
        if (l1->val <= l2->val) {
            if (nullptr == p) {
                ret = l1;
                p = l1;
            } else {
                p->next = l1;
                p = p->next;
            }
            l1 = l1->next;
        } else {
            if (nullptr == p) {
                ret = l2;
                p = l2;
            } else {
                p->next = l2;
                p = p->next;
            }
            l2 = l2->next;
        }
    }

    if (p) {
        if (l1) {
            p->next = l1;
        }
        if (l2) {
            p->next = l2;
        }
    } else {
        if (l1) {
            ret = l1;
        } else {
            ret = l2;
        }
    }

    return ret;
}


//022
void doGenerateParenthesis(vector<string> &vctRes, string str, int l, int r, int n) {
    if (l > n || r > n || r > l) {
        return;
    }
    if (l == n && r == n) {
        vctRes.push_back(str);
        return;
    }
    doGenerateParenthesis(vctRes, str + '(', l + 1, r, n);
    doGenerateParenthesis(vctRes, str + ')', l, r + 1, n);
    return;
}
vector<string> Solution::generateParenthesis(int n) {
    vector<string> vctRes;
    doGenerateParenthesis(vctRes, "", 0, 0, n);
    return vctRes;
}


//023
ListNode* Solution::mergeKLists(vector<ListNode*>& lists) {
#if 1//023.1：复用021解题思路，多次调用接口mergeTwoLists
    auto const& size = lists.size();
    ListNode* ret = nullptr;
    for (unsigned i = 0; i < size; ++i) {
        ret = mergeTwoLists(ret, lists[i]);
    }
    return ret;
#else//023.2：mergeTwoLists的衍生，一次比较n个数（未实现，但是复杂度应等同023.1）
    ListNode* ret = nullptr;
    ListNode* p = nullptr;
    auto const& size = lists.size();
    auto count_nil = 0;
    while (true) {
        bool flag_break = false;
        for (auto i = 0; i < size; ++i) {
            if (nullptr == lists[i]) {
                ++count_nil;
                continue;
            }
            p = lists[i];
        }
        if (flag_break) {
            break;
        }
    }
    return ret;
#endif
}


//024
ListNode* Solution::swapPairs(ListNode* head) {
    ListNode* dummy = new ListNode(-1);//新增一个哑结点，哑结点的next指向head
    dummy->next = head;

    ListNode* p0 = dummy;
    ListNode* p1 = head;
    ListNode* p2 = nullptr;
    while (p1 && p1->next) {
        p2 = p1->next;
        p1->next = p2->next;
        p2->next = p1;
        p0->next = p2;
        p0 = p1;
        p1 = p1->next;
    }

    return dummy->next;//哑结点的next即返回的结果
}


//025
ListNode* Solution::reverseKGroup(ListNode* head, int k) {
    ListNode* dummy = new ListNode(-1);//新增一个哑结点，哑结点的next指向head
    dummy->next = head;

    ListNode* p0 = dummy;
    ListNode* p0_new = nullptr;
    ListNode* p1 = head;
    ListNode* p2 = nullptr;
    ListNode* p = nullptr;//节点校验指针
    while (p0) {
        p = p0;
        for (int i = 0; i < k; ++i) {
            p = p->next;
            if (!p) {
                break;
            }
        }
        if (!p) {//剩余节点不够k个，不够一组则不做翻转
            break;
        }
        p1 = p0->next;
        p2 = p1->next;
        for (int i = 0; i < k - 1; ++i) {
            if (i % 2 == 0) {
                p1->next = p2->next;
                p2->next = p0->next;
                p0->next = p2;
                p0_new = p1;
                p1 = p1->next;
                while (p2->next != p1) {
                    p2 = p2->next;
                }
            } else {
                p2->next = p1->next;
                p1->next = p0->next;
                p0->next = p1;
                p0_new = p2;
                p2 = p2->next;
                while (p1->next != p2) {
                    p1 = p1->next;
                }
            }
        }
        p0 = p0_new;
    }

    return dummy->next;//哑结点的next即返回的结果
}


//026
int Solution::removeDuplicates(vector<int>& nums) {
	if (nums.size() < 2) {
		return nums.size();
	}
	int i = 0, j = 1;
	for (; j < nums.size(); ++j) {
		if (nums[i] < nums[j]) {
			nums[++i] = nums[j];
		}
	}
	return ++i;
}


//027
int Solution::removeElement(vector<int>& nums, int val) {
	int i = 0, j = 0, k = 0;
	int tmp = 0;
	for (; j < nums.size(); ++j) {
		if (nums[j] != val) {
			if (nums[i] == val) {
				tmp = nums[i];
				nums[i] = nums[j];
				nums[j] = tmp;
			}
			++i;
		} else {
			if (nums[i] != val) {
				i = j;
			}
			++k;
		}
	}
	return nums.size() - k;
}


//028
//获取 next 集合
#if 1
void getNext(string const &s, vector<int> &next) {
    int n = s.length();
    int j = 0;
    int k = -1;
    next[0] = -1;

    while (j < n - 1) {
        if (k == -1 || s[k] == s[j]) {
            ++j;
            ++k;
            //优化 next 取值
            if (s[j] != s[k]) {
                next[j] = k;
            } else {
                next[j] = next[k];
            }
        } else {
            k = next[k];
        }
    }
}
//KMP 算法
int Solution::strStr(string haystack, string needle) {
    int nLenN = needle.length();
    if (0 == nLenN) {
        return 0;
    }

    int nLenH = haystack.length();
    if (nLenH < nLenN) {
        return -1;
    }
    vector<int> vctNext(nLenN);
    getNext(needle, vctNext);

    int i = 0;
    int j = 0;
    while (i < nLenH && j < nLenN) {
        if (j == -1 || haystack[i] == needle[j]) {
            ++i;
            ++j;
        } else {
            j = vctNext[j];
        }
    }

    if (j == nLenN) {
        return i - nLenN;
    }

    return -1;
}
#else
int Solution::strStr(string haystack, string needle) {
    int nLenN = needle.length();
    if (0 == nLenN) {
        return 0;
    }

    int nLenH = haystack.length();
    if (nLenH < nLenN) {
        return -1;
    }

    //暴力法
    int i = 0;
    int j = 0;
    while (i < nLenH && j < nLenN) {
        if (haystack[i] == needle[j]) {
            ++i;
            ++j;
        } else {
            i -= j - 1;//优化 i 的位置
            j = 0;
        }
    }

    if (j == nLenN) {
        return i - nLenN;
    }

    return -1;
}
#endif


//029
unsigned doDivide(unsigned a, unsigned b) {
	if (a < b) {
		return 0;
	}
	unsigned cnt = 1;
	unsigned tmp = b;
	while (tmp < INT_MAX && a >= (tmp + tmp)) {
		tmp += tmp;
		cnt += cnt;
	}
	return cnt + doDivide(a - tmp, b);
}
int Solution::divide(int dividend, int divisor) {
	switch (divisor)
	{
	case 1:
		return dividend;
	case -1:
		return dividend == INT_MIN ? INT_MAX : -dividend;
	case INT_MIN:
		return dividend == INT_MIN ? 1 : 0;
	default:
		unsigned a = 0U;
		unsigned b = 0U;
		bool bSign = false;
		if (dividend > 0) {
			a = dividend;
			if (divisor < 0) {
				b = -divisor;
				bSign = true;
			} else {
				b = divisor;
			}
		} else if (dividend < 0) {
			if (dividend == INT_MIN) {
				a = INT_MAX + 1;
			} else {
				a = -dividend;
			}
			if (divisor > 0) {
				b = divisor;
				bSign = true;
			} else {
				b = -divisor;
			}
		} else {
			return 0;
		}
		int nRet = doDivide(a, b);
		if (bSign) {
			return -nRet;
		}
		return nRet;
	}
}


//030
#if 0
vector<int> Solution::findSubstring(string s, vector<string>& words) {
    if (s.empty() || words.empty()) return{};
    int n = words.size(), m = words[0].size(), j = 0;
    if (s.size() < m * n) return{};
    vector<int> res;
    unordered_map<string, int> mp, tmp;
    for (auto str : words) {
        ++mp[str];
    }
    string str = "";
    for (int i = 0; i + m * n <= s.size(); ++i) {
        for (j = i; j < i + m * n; j += m) {
            str = s.substr(j, m);
            if (mp.find(str) == mp.end()) break;
            ++tmp[str];
        }
        if (j == i + m * n && tmp == mp) res.push_back(i);
        tmp.clear();
    }
    return res;
}
#else
vector<int> Solution::findSubstring(string s, vector<string>& words) {
        vector<int> vctRet;
        int const l = s.length();
        int const n = words.size();
        if (l == 0 || n == 0) {
            return vctRet;
        }
        int const m = words[0].length();
        if (l < m * n) {
            return vctRet;
        }

        //1、hash
        unordered_map<string, int> mapCache;//缓存
        for (auto word : words) {
            ++mapCache[word];
        }

        unordered_map<string, int> mapStatistics;//统计

        //2、滑动窗口
        //搜索 s 中长度为 m 的子串，在缓存 mapCache 中查找并汇总统计信息到 mapStatistics 中
        for (int i = 0; i <= l - m * n; ++i) {
            mapStatistics.clear();
            int j = i;
            for (; j < i + m * n; j += m) {
                auto const &sSub = s.substr(j, m);
                if (mapCache.find(sSub) == mapCache.end()) {
                    break;
                }
                ++mapStatistics[sSub];
            }

            //3、比较统计的 map 和缓存的 map 数据是否一致
            if (mapCache == mapStatistics) {
                vctRet.push_back(i);
            }
        }
        return vctRet;
}
#endif


//031
void Solution::nextPermutation(vector<int>& nums) {
	int nI = -1;
	int nJ = -1;
	for (int i = nums.size() - 1; i > 0; --i) {
		for (int j = i - 1; j >= 0; --j) {
			if (nums[j] < nums[i] && j > nJ) {
				nI = i;
				nJ = j;
			}
		}
	}

	if (nJ != -1) {
		swap(nums[nI], nums[nJ]);
	}

	std::reverse(nums.begin() + (nJ + 1), nums.end());
}


//032
int Solution::longestValidParentheses(string s) {
	int nMax = 0;
	stack<int> stk;
	stk.push(-1);
	for (int i=0; i<s.length(); ++i) {
		if (s[i] == '(') {
			stk.push(i);
		} else {
			stk.pop();
			if (stk.empty()) {
				stk.push(i);
			} else {
				nMax = std::max(nMax, i - stk.top());
			}
		}
	}
	return nMax;
}


//033
int Solution::search(vector<int>& nums, int target) {
	int i = 0, j = nums.size() - 1, m = (i + j) / 2;
	while (i <= m && m <= j) {
		if (nums[m] > target) {
			if (nums[i] < target) {
				j = m - 1;
			} else if (nums[i] > target) {
				++i;
			} else {
				return i;
			}
		} else if (nums[m] < target) {
			if (nums[j] > target) {
				i = m + 1;
			} else if (nums[j] < target) {
				--j;
			} else {
				return j;
			}
		} else {
			return m;
		}
		m = (i + j) / 2;
	}
	return -1;
}


//036
bool Solution::isValidSudoku(vector<vector<char>>& board) {
#if 0
    unordered_map<int, set<char>> mapX;//行对应已填的数
    unordered_map<int, set<char>> mapY;//列对应已填的数
    unordered_map<int, set<char>> mapZ;//宫对应已填的数
    for (auto x = 0; x < 9; ++x) {
        for (auto y = 0; y < 9; ++y) {
            auto const& val = board[x][y];
            if (val == '.') {
                continue;
            }

            //行
            auto const& posX = mapX.find(x);
            if (posX == mapX.end()) {
                mapX[x] = { val };
            } else {
                auto& setChars = posX->second;
                auto const& posFind = setChars.find(val);
                if (posFind != setChars.end()) {
                    return false;
                }
                setChars.insert(val);
            }

            //列
            auto const& posY = mapY.find(y);
            if (posY == mapY.end()) {
                mapY[y] = { val };
            } else {
                auto& setChars = posY->second;
                auto const& posFind = setChars.find(val);
                if (posFind != setChars.end()) {
                    return false;
                }
                setChars.insert(val);
            }

            //宫
            auto const& z = x / 3 * 3 + y / 3;
            auto const& posZ = mapZ.find(z);
            if (posZ == mapZ.end()) {
                mapZ[z] = { val };
            } else {
                auto& setChars = posZ->second;
                auto const& posFind = setChars.find(val);
                if (posFind != setChars.end()) {
                    return false;
                }
                setChars.insert(val);
            }
        }
    }
    return true;
#else
    bool row[9][9] = { 0 };
    bool col[9][9] = { 0 };
    bool box[9][9] = { 0 };
    auto num = 0;

    for (auto x = 0; x < 9; ++x) {
        for (auto y = 0; y < 9; ++y) {
            if (board[x][y] != '.') {
                auto const& z = (x / 3) * 3 + y / 3;
                num = board[x][y] - '1';
                if (row[x][num] || col[y][num] || box[z][num]) {
                    return false;
                }
                row[x][num] = true;
                col[y][num] = true;
                box[z][num] = true;
            }
        }
    }
    return true;
#endif
}

//037
//预处理
void preSolveSudoku(vector<vector<char>>& board) {
    unordered_map<int, set<char>> mapBlockOptions;//空格对应的可选项
    unordered_map<int, set<char>> mapX;//行对应已填的数
    unordered_map<int, set<char>> mapY;//列对应已填的数
    unordered_map<int, set<char>> mapZ;//宫对应已填的数
    for (auto x = 0; x < 9; ++x) {
        for (auto y = 0; y < 9; ++y) {
            auto const& val = board[x][y];
            if (val == '.') {
                mapBlockOptions.insert(make_pair(x * 9 + y, set<char>{}));
                continue;
            }
            //行
            auto const& posX = mapX.find(x);
            if (posX == mapX.end()) {
                mapX[x] = { val };
            } else {
                posX->second.insert(val);
            }

            //列
            auto const& posY = mapY.find(y);
            if (posY == mapY.end()) {
                mapY[y] = { val };
            } else {
                posY->second.insert(val);
            }

            //宫
            auto const& z = x / 3 * 3 + y / 3;
            auto const& posZ = mapZ.find(z);
            if (posZ == mapZ.end()) {
                mapZ[z] = { val };
            } else {
                posZ->second.insert(val);
            }
        }
    }

    size_t sizeOld = INT_MAX;
    while (!mapBlockOptions.empty() && mapBlockOptions.size() < sizeOld) {
        sizeOld = mapBlockOptions.size();
        for (auto posMap = mapBlockOptions.begin(); posMap != mapBlockOptions.end();) {
            auto const& x = posMap->first / 9;
            auto const& y = posMap->first % 9;;
            auto const& z = x / 3 * 3 + y / 3;
            auto const& setX = mapX[x];
            auto const& setY = mapY[y];
            auto const& setZ = mapZ[z];
            auto& setOptions = posMap->second;
            if (setOptions.empty()) {
                for (auto c = '1'; c <= '9'; ++c) {
                    if (setX.find(c) == setX.end() &&
                        setY.find(c) == setY.end() &&
                        setZ.find(c) == setZ.end()) {
                        setOptions.insert(c);
                    }
                }
            } else {
                for (auto posSet = setOptions.begin(); posSet != setOptions.end();) {
                    auto & c = *posSet;
                    if (setX.find(c) == setX.end() &&
                        setY.find(c) == setY.end() &&
                        setZ.find(c) == setZ.end()) {
                        ++posSet;
                        continue;
                    }
                    posSet = setOptions.erase(posSet);
                }
            }

            //可选项集合大小为1时，即此空格为确定值。
            if (setOptions.size() == 1) {
                auto const& c = *setOptions.begin();
                mapX[x].insert(c);
                mapY[y].insert(c);
                mapZ[z].insert(c);
                board[x][y] = c;
                posMap = mapBlockOptions.erase(posMap);
                continue;
            }
            ++posMap;
        }
    }
}
bool row[9][9];
bool col[9][9];
bool box[9][9];
bool done;
void dfs(vector<vector<char> > &board, int const& x, int const& y) {
    if (x > 8) {
        done = true;
        return;
    }
    if (board[x][y] == '.') {
        auto const& z = (x / 3) * 3 + y / 3;
        for (auto i = 0; i < 9; ++i) {
            if (!row[x][i] && !col[y][i] && !box[z][i]) {
                board[x][y] = i + '1';
                row[x][i] = col[y][i] = box[z][i] = true;
                if (y >= 8) {
                    dfs(board, x + 1, 0);
                } else {
                    dfs(board, x, y + 1);
                }
                if (done) {
                    break;
                }
                board[x][y] = '.';
                row[x][i] = col[y][i] = box[z][i] = false;
            }
        }
    } else {
        if (y >= 8) {
            dfs(board, x + 1, 0);
        } else {
            dfs(board, x, y + 1);
        }
    }
}
void Solution::solveSudoku(vector<vector<char> > &board) {
    preSolveSudoku(board);

    memset(row, 0, 9 * 9 * sizeof(bool));
    memset(col, 0, 9 * 9 * sizeof(bool));
    memset(box, 0, 9 * 9 * sizeof(bool));
    done = false;
    auto num = 0;

    for (auto x = 0; x < 9; ++x) {
        for (auto y = 0; y < 9; ++y) {
            if (board[x][y] != '.') {
                auto const& z = (x / 3) * 3 + y / 3;
                num = board[x][y] - '1';
                row[x][num] = true;
                col[y][num] = true;
                box[z][num] = true;
            }
        }
    }
    dfs(board, 0, 0);
}


//038
string Solution::countAndSay(int n) {
	string s = "1";
	string sRet = s;
	while (--n) {
		s = sRet;
		sRet = "";
		int i = 0;
		while (i < s.length()) {
			char c = s[i];
			int cnt = 0;
			int j = i;
			while (s[j] == c) {
				++cnt;
				++j;
			}
			sRet += '0' + cnt;
			sRet += c;
			i += cnt;
		}
	}
	return sRet;
}


//043
string Solution::multiply(string num1, string num2) {
	if (num1 == "0" || num2 == "0") {
		return "0";
	}

	int nLen1 = num1.length();
	int nLen2 = num2.length();
	int i = 0;
	int j = 0;
	int k = 0;
	int *arrCache = new int[nLen1 + nLen2];//缓存计算结果的数组
	while (k < nLen1 + nLen2) {//初始化缓存数组中所有的数据为 0
		arrCache[k++] = 0;
	}

	int nCarry = 0;//缓存进位

	for (j = nLen2 - 1; j >= 0; --j) {
		for (i = nLen1 - 1, k = nLen2 - 1 - j; i >= 0; --i, ++k) {
			int nOld = arrCache[k];
			arrCache[k] = (nOld + (num1[i] - '0') * (num2[j] - '0') + nCarry) % 10;
			nCarry = (nOld + (num1[i] - '0') * (num2[j] - '0') + nCarry) / 10;
		}
		while (nCarry > 0) {
			int nOld = arrCache[k];
			arrCache[k] = (nOld + nCarry) % 10;
			nCarry = (nOld + nCarry) / 10;
			++k;
		}
	}

	string sRet = "";
	for (i = k - 1; i >= 0; --i) {
		sRet += '0' + arrCache[i];
	}

	delete []arrCache;
	arrCache = nullptr;

	return sRet;
}

//056
vector<vector<int>> Solution::merge(vector<vector<int>>& intervals) {
    if (intervals.empty()) {
        return intervals;
    }

    //区间集合按照左值排序
    using Iter = vector<int> const&;
    sort(intervals.begin(), intervals.end(), [](Iter l, Iter r) {
        return l[0] < r[0];
    });

    vector<vector<int>> ans = { intervals[0] };
    auto const& size = intervals.size();

    for (size_t i = 1; i < size; ++i) {
        //比较当前区间的右值和下一个区间的左值
        if (ans.back()[1] < intervals[i][0]) {
            ans.push_back(intervals[i]);
            continue;
        }

        if (intervals[i][1] > ans.back()[1]) {
            ans.back()[1] = intervals[i][1];
        }
    }

    return ans;
}


//057
vector<vector<int>> Solution::insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> res;
    bool bMerge = false;
    for (auto const& val : intervals) {
        if (val[1] < newInterval[0]) {
            res.push_back(val);
        } else if (val[0] > newInterval[1]) {
            if (!bMerge) {
                bMerge = true;
                res.push_back(newInterval);
            }
            res.push_back(val);
        } else {
            if (val[0] < newInterval[0]) {
                newInterval[0] = val[0];
            }
            if (val[1] > newInterval[1]) {
                newInterval[1] = val[1];
            }
        }
    }
    if (!bMerge) {
        res.push_back(newInterval);
    }
    return res;
}


//058
int Solution::lengthOfLastWord(string s) {
	int i = s.length() - 1;
	int j = i;
	while (i >= 0 && s[i] == ' ') {
		--i;
		--j;
	}
	while (i >= 0 && s[i] != ' ') {
		--i;
	}
	return j - i;
}


//061
ListNode* Solution::rotateRight(ListNode* head, int k) {
    if (nullptr == head || nullptr == head->next) {
        return head;
    }

    ListNode* p1 = head;
    ListNode* p2 = head;
    int count = 1;
    while (p2->next) {
        ++count;
        p2 = p2->next;
    }
    p2->next = head;//建环

    int n = count - (k%count);
    for (int i = 0; i < n - 1; ++i) {
        p1 = p1->next;
    }

    ListNode* ret = p1->next;
    p1->next = nullptr;//解环

    return ret;
}


//067
#if 0
//异或
string Solution::addBinary(string a, string b) {
    int nLenA = a.size();
    int nLenB = b.size();
    if (nLenA < nLenB) {
        swap(a, b);
        swap(nLenA, nLenB);
    }
    if (nLenA - nLenB > 0) {
        b.insert(0, nLenA - nLenB, '0');
    }
    int nPre = 0, nCur = 0;
    string sRet;
    for (int i = nLenA - 1; i >= 0; i--) {
        int ia = a[i] - '0';
        int ib = b[i] - '0';
        nCur = ia ^ ib ^ nPre;  // 二进制数相加结果与异或结果相同
        if (ia + ib + nPre >= 2) {
            nPre = 1;
        } else {
            nPre = 0;
        }
        sRet.insert(0, 1, nCur + '0');
    }
    if (nPre) { // 最高位的进位单独处理
        sRet.insert(0, 1, nPre + '0');
    }
    return sRet;
}
#else
//大数加法
string Solution::addBinary(string a, string b) {
    int i = a.length() - 1;
    int j = b.length() - 1;
    int k = 0;
    int nLen = std::max(a.length(), b.length()) + 1;
    int *arrCache = new int[nLen];
    while (k < nLen) {
        arrCache[k++] = 0;
    }
    k = 0;
    int nCarry = 0;//缓存进位

    while (i >= 0 && j >= 0) {
        arrCache[k] = (nCarry + (a[i] - '0') + (b[j] - '0')) % 2;
        nCarry = (nCarry + a[i] - '0' + b[j] - '0') / 2;
        --i;
        --j;
        ++k;
    }
    while (i >= 0) {
        arrCache[k] = (nCarry + (a[i] - '0')) % 2;
        nCarry = (nCarry + a[i] - '0') / 2;
        --i;
        ++k;
    }
    while (j >= 0) {
        arrCache[k] = (nCarry + (b[j] - '0')) % 2;
        nCarry = (nCarry + b[j] - '0') / 2;
        --j;
        ++k;
    }
    if (nCarry > 0) {
        arrCache[k] = nCarry;
    }

    i = k;
    if (arrCache[i] == 0) {
        --i;
    }
    string sRet = "";
    while (i >= 0) {
        sRet += '0' + arrCache[i];
        --i;
    }

    delete[]arrCache;
    arrCache = nullptr;

    return sRet;
}
#endif


//075
void Solution::sortColors(vector<int>& nums) {
#if 1
    //多指针
    int nSize = nums.size();
    int i = 0;//0
    int j = 0;//1
    int k = nSize - 1;//2
    int x = 0;
    while (1) {
        while (i < nSize && nums[i] == 0) {
            ++i;
        }
        j = i;
        while (j < nSize && nums[j] == 1) {
            ++j;
        }
        while (k >= 0 && nums[k] == 2) {
            --k;
        }
        if (j > k) {
            break;
        }
        if (nums[i] == 2 || nums[k] == 0) {
            x = nums[i];
            nums[i] = nums[k];
            nums[k] = x;
        } else {
            if (nums[j] == 0) {
                x = nums[i];
                nums[i] = nums[j];
                nums[j] = x;
            } else {
                x = nums[j];
                nums[j] = nums[k];
                nums[k] = x;
            }
        }
    }
}
#else
void Solution::sortColors(vector<int>& nums) {
    //插入排序
    int arrCache[3] = { 0 };
    for (auto const &pos : nums) {
        ++arrCache[pos];
    }
    int i = -1, j = -1;
    while (++i < 3) {
        while (arrCache[i]--) {
            nums[++j] = i;
        }
    }
}
#endif



//082
ListNode* Solution::deleteDuplicates(ListNode* head) {
    if (nullptr == head || nullptr == head->next) {
        return head;
    }
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode*p0 = dummy;
    ListNode*p1 = head;
    ListNode*p2 = head->next;
    while (p2) {
        if (p1->val == p2->val) {
            p2 = p2->next;
        } else {
            if (p1->next == p2) {
                p0 = p1;
                p1 = p1->next;
                p2 = p2->next;
            } else {
                p0->next = p2;
                p1 = p2;
                p2 = p2->next;
            }
        }
    }
    if (p1->next != p2) {
        p0->next = nullptr == p2 ? nullptr : p2->next;
    }
    return dummy->next;
}

//083
ListNode* Solution::deleteDuplicatesOne(ListNode* head) {
    if (nullptr == head || nullptr == head->next) {
        return head;
    }
    ListNode* p1 = head;
    ListNode* p2 = p1->next;
    while (p2) {
        if (p1->val == p2->val) {
            p2 = p2->next;
        } else {
            if (p1->next != p2) {
                p1->next = p2;
            }
            p1 = p1->next;
            p2 = p1->next;
        }
    }
    if (p1->next != p2) {
        p1->next = nullptr == p2 ? nullptr : p2->next;
    }
    return head;
}

//086
ListNode* Solution::partition(ListNode* head, int x) {
    if (nullptr == head || nullptr == head->next) {
        return head;
    }
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode* p0 = dummy;
    ListNode* p1 = head;
    ListNode* p2 = nullptr;
    while (p1) {
        if (nullptr == p2 && p1->val == x) {
            p2 = p1;
        }
        if (p2 && p1->val < x) {
            p0->next = p1->next;
            p1->next = dummy->next;
            dummy->next = p1;
            p1 = p0->next;
        } else {
            p0 = p1;
            p1 = p1->next;
        }
    }
    return dummy->next;
}

//092
ListNode* Solution::reverseBetween(ListNode* head, int m, int n) {
    if (nullptr == head || nullptr == head->next) {
        return head;
    }
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode* p0 = dummy;
    ListNode* p1 = head;        //第m个节点
    ListNode* p2 = head->next;  //第n个节点

                                //1、确定位置m
    for (auto i = 0; i < m - 1; ++i) {
        p0 = p0->next;
    }
    p1 = p0->next;

    //2、确定位置n
    p2 = p1;
    int len = (n - m);
    for (auto i = 0; i < len; ++i) {
        p2 = p2->next;
    }

    //3、反转从m到n的节点
    for (auto i = 0; i < len; ++i) {
        p0->next = p1->next;
        p1->next = p2->next;
        p2->next = p1;
        p1 = p0->next;
    }
    return dummy->next;
}

//94
void Solution::inOder(TreeNode* root, vector<int>& ans) {
    if (!root) {
        return;
    }
    inOder(root->left, ans);
    ans.push_back(root->val);
    inOder(root->right, ans);
}
vector<int> Solution::inorderTraversal(TreeNode* root) {
    vector<int> ans;
#if 0//递归法
    inOder(root, ans);
#else//迭代法：辅助栈
    stack<TreeNode*> st;
    while (!st.empty() || root) {
        if (root) {
            st.push(root);
            root = root->left;
        } else {
            root = st.top();
            st.pop();
            ans.push_back(root->val);
            root = root->right;
        }
    }
#endif
    return ans;
}

//95
vector<TreeNode*>* Solution::createBST(int begin, int end) {
    vector<TreeNode*>* ans = new vector<TreeNode*>();
    if (begin > end) {
        ans->push_back(nullptr);
    } else {
        for (int i = begin; i <= end; ++i) {
            vector<TreeNode*>* left = createBST(begin, i - 1);
            vector<TreeNode*>* right = createBST(i + 1, end);
            for (size_t l = 0; l < left->size(); ++l) {
                for (size_t r = 0; r < right->size(); ++r) {//构建二叉查找树
                    TreeNode* node = new TreeNode(i);//不同的根结点
                    node->left = (*left)[l];
                    node->right = (*right)[r];
                    ans->push_back(node);
                }
            }
        }
    }
    return ans;
}
vector<TreeNode*> Solution::generateTrees(int n) {
    return *createBST(1, n);
}

//96
int Solution::numTrees(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            dp[i] += (dp[j] * dp[i - 1 - j]);
        }
    }

    return dp[n];
}

//98
void Solution::inOderIsValidBST(TreeNode* root) {
    if (!root || !is_valid_BST) {
        return;
    }
    inOderIsValidBST(root->left);
    if (last && last->val >= root->val) {
        is_valid_BST = false;
    }
    last = root;
    inOderIsValidBST(root->right);
}
bool Solution::isValidBST(TreeNode* root) {
    //初始化
    last = nullptr;
    is_valid_BST = true;

    //中序遍历
    inOderIsValidBST(root);

    //返回结果
    return is_valid_BST;
}


//99
void Solution::inOderRecoverTree(TreeNode* root) {
    if (!root || p1 && p3) {
        return;
    }
    inOderRecoverTree(root->left);
    if (last && last->val > root->val) {
        if (!p1) {
            p1 = last;
            p2 = root;
        } else {
            p3 = last;
            p4 = root;
        }
    }
    last = root;
    inOderRecoverTree(root->right);
}
void Solution::recoverTree(TreeNode* root) {
    //初始化
    p1 = p2 = p3 = p4 = last = nullptr;

    //中序遍历
    inOderRecoverTree(root);

    //交换节点值
    TreeNode* t1 = p1;
    TreeNode* t2 = !p3 ? p2 : p4;
    swap(t1->val, t2->val);
}

//100
bool Solution::isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) {
        return true;
    }
    if (!p || !q || p->val != q->val) {
        return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);//递归比较两棵树的左、右子树
}


//101
bool Solution::isMirror(TreeNode* t1, TreeNode *t2) {
    if (!t1 && !t2) {
        return true;
    }
    if (!t1 || !t2 || t1->val != t2->val) {
        return false;
    }
    return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
}
bool Solution::isSymmetric(TreeNode* root) {
    return isMirror(root, root);
}


//102
vector<vector<int>> Solution::levelOrder(TreeNode* root) {
    if (!root) {
        return{};
    }

    vector<vector<int>> ret;
    TreeNode *p = root;
    queue<TreeNode*> nodes;
    nodes.push(p);
    int count = 1;
    int count_next = 0;

    while (!nodes.empty()) {
        vector<int> nodes_level;
        for (int i = 0; i < count; ++i) {
            p = nodes.front();
            if (p->left) {
                nodes.push(p->left);
                ++count_next;
            }
            if (p->right) {
                nodes.push(p->right);
                ++count_next;
            }
            nodes.pop();
            nodes_level.push_back(p->val);
        }

        count = count_next;
        count_next = 0;
        ret.push_back(nodes_level);
    }

    return ret;
}


//103
vector<vector<int>> Solution::zigzagLevelOrder(TreeNode* root) {
    if (!root) {
        return{};
    }

    vector<vector<int>> ret;
    unsigned count = 1;
    unsigned count_next = 0;
    queue<TreeNode*> nodes;
    nodes.push(root);
    bool left2right = true;//从左到右的标识

    while (!nodes.empty()) {
        vector<int> nodes_level;
        for (unsigned i = 0; i < count; ++i) {
            TreeNode* p = nodes.front();
            if (p->left) {
                nodes.push(p->left);
                ++count_next;
            }
            if (p->right) {
                nodes.push(p->right);
                ++count_next;
            }
            nodes.pop();
            if (left2right) {
                nodes_level.push_back(p->val);
            } else {
                nodes_level.insert(nodes_level.begin(), p->val);
            }
        }
        count = count_next;
        count_next = 0;
        left2right = !left2right;
        ret.push_back(nodes_level);
    }
    return move(ret);
}


//104
int Solution::maxDepth(TreeNode* root) {
#if 0//迭代法：辅助队列
    if (!root) {
        return 0;
    }
    unsigned depth = 0;
    unsigned count = 1;
    unsigned count_next = 0;
    queue<TreeNode*> nodes;
    nodes.push(root);
    while (!nodes.empty()) {
        for (unsigned i = 0; i < count; ++i) {
            TreeNode* p = nodes.front();
            if (p->left || p->right) {
                if (p->left) {
                    nodes.push(p->left);
                    ++count_next;
                }
                if (p->right) {
                    ++count_next;
                    nodes.push(p->right);
                }
            }
            nodes.pop();
        }
        ++depth;
        count = count_next;
        count_next = 0;
    }
    return depth;
#else//递归法
    return !root ? 0 : 1 + std::max(maxDepth(root->left), maxDepth(root->right));
#endif
}


//105
TreeNode* Solution::build(vector<int>::const_iterator pre1, vector<int>::const_iterator pre2,
    vector<int>::const_iterator in1, vector<int>::const_iterator in2) {
    if (pre1 > pre2 || in1 > in2) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(*pre1);
    auto const& pos = std::find(in1, in2, root->val);
    root->left = build(pre1 + 1, pre2, in1, pos - 1);
    root->right = build(pre1 + (pos - in1) + 1, pre2, pos + 1, in2);
    return root;
}
TreeNode* Solution::buildTree(vector<int>& preorder, vector<int>& inorder) {
#if 0//递归法
    if (preorder.empty() || inorder.empty()) {
        return nullptr;
    }
    return build(preorder.begin(), preorder.end() - 1, inorder.begin(), inorder.end() - 1);
#else//迭代法：使用辅助栈
    unsigned const& size = preorder.size();
    if (size == 0) {
        return nullptr;
    }
    unsigned pre_index = 0, in_index = 0;
    TreeNode* root = new TreeNode(preorder[pre_index++]);
    TreeNode* cur = root;
    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        //创建左子树：压栈
        while (st.top()->val != inorder[in_index]) {
            st.top()->left = new TreeNode(preorder[pre_index++]);
            st.push(st.top()->left);
        }
        //定位当前右子树所在的跟节点：出栈
        while (!st.empty() && st.top()->val == inorder[in_index]) {
            cur = st.top();
            st.pop();
            ++in_index;
        }
        //创建右子树：压栈
        if (pre_index < size) {
            cur->right = new TreeNode(preorder[pre_index++]);
            cur = cur->right;
            st.push(cur);
        }
    }

    return root;
#endif
}


//106
TreeNode* Solution::buildTree_in_post(vector<int>& inorder, vector<int>& postorder) {
    unsigned const& size = postorder.size();
    if (size == 0) {
        return nullptr;
    }
    unsigned post_index = size, in_index = size - 1;
    TreeNode* root = new TreeNode(postorder[--post_index]);
    TreeNode* cur = root;
    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        //创建右子树：压栈
        while (st.top()->val != inorder[in_index]) {
            st.top()->right = new TreeNode(postorder[--post_index]);
            st.push(st.top()->right);
        }
        //定位当前左子树所在的跟节点：出栈
        while (!st.empty() && st.top()->val == inorder[in_index]) {
            cur = st.top();
            st.pop();
            --in_index;
        }
        //创建左子树：压栈
        if (post_index > 0) {
            cur->left = new TreeNode(postorder[--post_index]);
            cur = cur->left;
            st.push(cur);
        }
    }

    return root;
}


//107
vector<vector<int>> Solution::levelOrderBottom(TreeNode* root) {
    if (!root) {
        return{};
    }

    vector<vector<int>> ret;
    TreeNode *p = root;
    queue<TreeNode*> nodes;
    nodes.push(p);
    int count = 1;
    int count_next = 0;

    while (!nodes.empty()) {
        vector<int> nodes_level;
        for (int i = 0; i < count; ++i) {
            p = nodes.front();
            if (p->left) {
                nodes.push(p->left);
                ++count_next;
            }
            if (p->right) {
                nodes.push(p->right);
                ++count_next;
            }
            nodes.pop();
            nodes_level.push_back(p->val);
        }

        count = count_next;
        count_next = 0;
        ret.insert(ret.begin(), nodes_level);
    }

    return ret;
}


//108
TreeNode* Solution::sortedArrayToBST(vector<int>& nums, int const& begin, int const& end) {
    if (begin > end) {
        return nullptr;
    }
    unsigned mid = (begin + end) / 2;
    TreeNode* t = new TreeNode(nums[mid]);
    t->left = sortedArrayToBST(nums, begin, mid - 1);
    t->right = sortedArrayToBST(nums, mid + 1, end);
    return t;
}
TreeNode* Solution::sortedArrayToBST(vector<int>& nums) {
    unsigned const& size = nums.size();
    if (0 == size) {
        return nullptr;
    }
    return sortedArrayToBST(nums, 0, size - 1);
}


//109
TreeNode* Solution::sortedListToBST(ListNode* head, ListNode* tail) {
    if (head == tail) {
        return nullptr;
    }

    //快慢指针，查找链表的中间点位置
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast != tail && fast->next != tail) {
        fast = fast->next->next;
        slow = slow->next;
    }

    TreeNode* root = new TreeNode(slow->val);
    root->left = sortedListToBST(head, slow);
    root->right = sortedListToBST(slow->next, tail);
    return root;
}
TreeNode* Solution::sortedListToBST(ListNode* head) {
    if (!head) {
        return nullptr;
    }
    return sortedListToBST(head, nullptr);
}


//110
bool Solution::isBalanced(TreeNode* root) {
    //递归法：双递归
    if (!root || !root->left && !root->right) {
        return true;
    }
    if (abs(maxDepth(root->left) - maxDepth(root->right)) > 1) {
        return false;//比较子树是否平衡
    }
    return isBalanced(root->left) && isBalanced(root->right);
}


//111
int Solution::minDepth(TreeNode* root) {
    if (!root) {
        return 0;
    }
    int left = minDepth(root->left);
    int right = minDepth(root->right);
    return (left && right) ? 1 + std::min(left, right) : 1 + left + right;
}


//112
bool Solution::hasPathSum(TreeNode* root, int sum) {
    if (!root) {
        return false;
    }
    if (!root->left && !root->right) {
        return sum == root->val;
    }
    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}


//113
void Solution::dfsPathSum(vector<vector<int>>& res, vector<int>& path, TreeNode* root, int sum) {
    if (!root) {
        return;
    }
    path.push_back(root->val);
    if (!root->left && !root->right && root->val == sum) {
        res.push_back(path);
    }
    dfsPathSum(res, path, root->left, sum - root->val);
    dfsPathSum(res, path, root->right, sum - root->val);
    path.pop_back();
}
vector<vector<int>> Solution::pathSum(TreeNode* root, int sum) {
    vector<vector<int>> res;
    vector<int> path;
    dfsPathSum(res, path, root, sum);
    return res;
}


//114
void Solution::postOrder(TreeNode* root) {
    if (!root) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    TreeNode* r = root->right;
    root->right = root->left;
    root->left = nullptr;
    while (root->right) {
        root = root->right;
    }
    root->right = r;
}
void Solution::flatten(TreeNode* root) {
#if 0//迭代法：辅助栈
    if (!root) {
        return;
    }
    stack<TreeNode*> st;
    st.push(root);
    TreeNode* cur = root;

    while (!st.empty()) {
        while (!st.empty() && st.top()->left) {
            st.push(st.top()->left);
        }
        cur = st.top();
        while (!st.empty() && !st.top()->right) {
            st.pop();
        }
        if (!st.empty()) {
            cur->left = st.top()->right;
            st.top()->right = nullptr;
            st.push(cur->left);
        }
    }
    cur = root;
    while (cur) {
        cur->right = cur->left;
        cur->left = nullptr;
        cur = cur->right;
    }
#else//递归法：后续遍历
    postOrder(root);
#endif
}


//116
void do_connect(Node *root) {
    if (nullptr == root) {
        return;
    }

    //如果是叶子结点
    if (nullptr == root->right && nullptr == root->left) {
        return;
    }

    root->left->next = root->right;
    if (nullptr != root->next) {
        root->right->next = root->next->left;
    } else {
        root->right->next = nullptr;
    }

    do_connect(root->left);
    do_connect(root->right);
}
Node* Solution::connect(Node* root) {
    do_connect(root);
    return root;
}


//117
void do_connect2(Node *root) {
    if (nullptr == root) {
        return;
    }

    //如果是叶子结点
    if (nullptr == root->right && nullptr == root->left) {
        return;
    }

    //设置左节点的next
    if (root->left && root->right) {
        root->left->next = root->right;
    } else if (root->left) {
        Node* next_tmp = root->next;
        while (next_tmp) {
            if (nullptr != next_tmp->left) {
                root->left->next = next_tmp->left;
                break;
            } else if (nullptr != next_tmp->right) {
                root->left->next = next_tmp->right;
                break;
            } else {
                next_tmp = next_tmp->next;
            }
        }
        if (nullptr == next_tmp) {
            root->left->next = nullptr;
        }
    }

    //设置右节点的next
    if (root->right) {
        Node* next_tmp = root->next;
        while (next_tmp) {
            if (nullptr != next_tmp->left) {
                root->right->next = next_tmp->left;
                break;
            } else  if (nullptr != next_tmp->right) {
                root->right->next = next_tmp->right;
                break;
            } else {
                next_tmp = next_tmp->next;
            }
        }
        if (nullptr == next_tmp) {
            root->right->next = nullptr;
        }
    }

    //先右后左
    do_connect2(root->right);
    do_connect2(root->left);
}
Node* Solution::connect2(Node* root) {
    do_connect2(root);
    return root;
}

//124
//先考虑子问题：求解以每一个节点为上端点的情况下，最大的路径和。即路径只能左右拐弯，而不能上下拐弯。此时子问题和最大和子数组很相似。
//然后本体就很好做了。
int maxsum(TreeNode* root, int& ans) {
    if (!root) {
        return 0;
    }

    int max_left = maxsum(root->left, ans);
    int max_right = maxsum(root->right, ans);
    int max_son = std::max(max_left, max_right);
    int res = 0;
    int tmp = root->val;

    if (max_son > 0) {
        res = max_son + root->val;
        if (max_left > 0) {
            tmp += max_left;
        }
        if (max_right > 0) {
            tmp += max_right;
        }
    } else {
        res = root->val;
    }

    if (tmp > ans) {
        ans = tmp;
    }
    return res;
}
int Solution::maxPathSum(TreeNode* root) {
    int ans = INT_MIN;
    maxsum(root, ans);
    return ans;
}


//129
int do_sumNumbers(TreeNode* root, int base) {
    if (!root) {
        return 0;
    }
    base = base * 10 + root->val;
    if (!root->left && !root->right) {
        return base;
    }
    return do_sumNumbers(root->left, base) + do_sumNumbers(root->right, base);
}
int Solution::sumNumbers(TreeNode* root) {
    return do_sumNumbers(root, 0);
}


//133
UndirectedGraphNode* clone(UndirectedGraphNode* node, unordered_map<int, UndirectedGraphNode*>& mapValueNode) {
    if (!node) {
        return nullptr;
    }

    //1、查找缓存的节点：已存在，则直接返回；
    auto const& posMap = mapValueNode.find(node->val);
    if (posMap != mapValueNode.end()) {
        return posMap->second;
    }

    //2、不存在则新建图节点res，并缓存；
    auto* res = new UndirectedGraphNode(node->val, vector<UndirectedGraphNode*>{});
    mapValueNode.insert(make_pair(node->val, res));

    //3、遍历 node 节点的邻居节点集合：将邻居节点进行克隆，并将克隆节点添加到res的邻居节点集合中；
    for (auto const& neighbor : node->neighbors) {
        res->neighbors.push_back(clone(neighbor, mapValueNode));
    }

    return res;
}
UndirectedGraphNode* Solution::cloneGraph(UndirectedGraphNode* node) {
#if 0
    //DFS
    unordered_map<int, UndirectedGraphNode*> mapValueNode;//缓存值对应的图节点
    return clone(node, mapValueNode);
#else
    //BFS
    if (!node) {
        return nullptr;
    }
    map<UndirectedGraphNode*, UndirectedGraphNode*> mapNodeClone;
    map<UndirectedGraphNode*, bool> mapNodeVisited;
    queue<UndirectedGraphNode*> queNodes;
    queNodes.push(node);

    while (!queNodes.empty()) {
        UndirectedGraphNode* front = queNodes.front();
        queNodes.pop();
        if (mapNodeVisited[front]) {
            continue;
        }

        mapNodeVisited[front] = true;
        UndirectedGraphNode* cur = nullptr;
        auto posMap = mapNodeClone.find(front);
        if (posMap == mapNodeClone.end()) {
            cur = new UndirectedGraphNode(front->val, vector<UndirectedGraphNode*>{});
            mapNodeClone.insert(make_pair(front, cur));
        } else {
            cur = posMap->second;
        }

        for (auto const& neighbor : front->neighbors) {
            posMap = mapNodeClone.find(neighbor);
            if (posMap == mapNodeClone.end()) {
                UndirectedGraphNode* temp = new UndirectedGraphNode(neighbor->val, vector<UndirectedGraphNode*>{});
                mapNodeClone.insert(make_pair(neighbor, temp));
                cur->neighbors.push_back(temp);
                queNodes.push(neighbor);
            } else {
                cur->neighbors.push_back(posMap->second);
            }
        }
    }

    return mapNodeClone[node];
#endif
}

//144
void do_preorderTraversal(TreeNode*root, vector<int>& vct) {
    if (!root) {
        return;
    }
    vct.push_back(root->val);
    do_preorderTraversal(root->left, vct);
    do_preorderTraversal(root->right, vct);
}
vector<int> Solution::preorderTraversal(TreeNode* root) {
    vector<int> res;
#if 0
    //递归法
    do_preorderTraversal(root, res);
#else
    //迭代法：辅助栈
    stack<TreeNode*> st;
    TreeNode* cur = root;
    while (cur || !st.empty()) {
        if (cur) {
            res.push_back(cur->val);
            st.push(cur);
            cur = cur->left;
        } else {
            cur = st.top();
            st.pop();
            cur = cur->right;
        }
    }
#endif
    return res;
}


//145
void do_postorderTraversal(TreeNode*root, vector<int>& vct) {
    if (!root) {
        return;
    }
    do_postorderTraversal(root->left, vct);
    do_postorderTraversal(root->right, vct);
    vct.push_back(root->val);
}
vector<int> Solution::postorderTraversal(TreeNode* root) {
    vector<int> res;
#if 0
    //递归法
    do_postorderTraversal(root, res);
#else
#if 0
    //迭代法1：辅助栈，bool类型为节点已遍历过的标识。
    stack<pair<TreeNode*, bool>> st;
    TreeNode* cur = root;
    while (cur || !st.empty()) {
        if (cur) {
            st.push(pair<TreeNode*, bool>(cur, false));
            cur = cur->left;
        } else {
            cur = st.top().first;
            if (st.top().second) {
                st.pop();
                res.push_back(cur->val);
                cur = nullptr;
            } else {
                st.top().second = true;
                cur = cur->right;
            }
        }
    }
#else
    //迭代法2：辅助栈，“根右左”顺序遍历，然后反转集合（反转后：左右根）
    stack<TreeNode*> st;
    TreeNode* cur = root;
    while (cur || !st.empty()) {
        if (cur) {
            res.push_back(cur->val);
            st.push(cur);
            cur = cur->right;
        } else {
            cur = st.top();
            st.pop();
            cur = cur->left;
        }
    }
    std::reverse(res.begin(), res.end());
#endif
#endif
    return res;
}


//119
vector<int> Solution::rightSideView(TreeNode* root) {
    //BFS，参考二叉树层次遍历
    if (!root) {
        return{};
    }

    queue<TreeNode*> que;
    vector<int> res;
    que.push(root);
    int size = que.size();
    while (!que.empty()) {
        TreeNode* tmp = que.front();
        que.pop();
        if (tmp->left) {
            que.push(tmp->left);
        }
        if (tmp->right) {
            que.push(tmp->right);
        }
        if (0 == --size) {
            size = que.size();
            res.push_back(tmp->val);
        }
    }
    return res;
}


//147
#if 1
//缓存法
ListNode* Solution::insertionSortList(ListNode* head) {
    map<int, unsigned> mapCache;
    ListNode *p = head;
    while (p) {
        ++mapCache[p->val];
        p = p->next;
    }
    p = head;
    for (auto &pos : mapCache) {
        while (pos.second--) {
            p->val = pos.first;
            p = p->next;
        }
    }
    return  head;
}
#else
//哑结点法
ListNode* Solution::insertionSortList(ListNode* head) {
    ListNode *pDummy = new ListNode(0);//哑结点
    ListNode *p = nullptr;
    ListNode *pNext = nullptr;
    
    while (head) {
        p = pDummy;
        while (p->next && p->next->val < head->val) {
            p = p->next;
        }
        pNext = p->next;
        p->next = head;
        head = head->next;
        p->next->next = pNext;
    }

    p = pDummy->next;
    
    delete pDummy;
    pDummy = nullptr;

    return  p;
}
#endif


//148
ListNode* Solution::sortList(ListNode* head) {
    //缓存法
    return insertionSortList(head);
}


//164
#if 1
//桶排序
class Bucket {
public:
    bool bUsed = false;
    int nMinVal = INT_MAX;        // same as INT_MAX
    int nMaxVal = INT_MIN;        // same as INT_MIN
};
int Solution::maximumGap(vector<int>& nums) {
    if (nums.empty() || nums.size() < 2) {
        return 0;
    }

    //1.建桶
    int const nMin = *min_element(nums.begin(), nums.end());
    int const nMax = *max_element(nums.begin(), nums.end());
    int nBucketSize = max(1, (nMax - nMin) / ((int)nums.size() - 1));   //桶的大小
    int nBucketNum = (nMax - nMin) / nBucketSize + 1;                   //桶的个数
    vector<Bucket> vctBuckets(nBucketNum);
    for (auto&& num : nums) {
        int nBucketIndex = (num - nMin) / nBucketSize;                  //放入哪个桶
        vctBuckets[nBucketIndex].bUsed = true;
        vctBuckets[nBucketIndex].nMinVal = min(num, vctBuckets[nBucketIndex].nMinVal);
        vctBuckets[nBucketIndex].nMaxVal = max(num, vctBuckets[nBucketIndex].nMaxVal);
    }

    //2.查桶
    int nMaxGap = 0;
    int nPrevBucketMaxVal = nMin;
    for (auto&& bucket : vctBuckets) {
        if (!bucket.bUsed) {
            continue;
        }
        nMaxGap = max(nMaxGap, bucket.nMinVal - nPrevBucketMaxVal);
        nPrevBucketMaxVal = bucket.nMaxVal;
    }

    return nMaxGap;
}
#elif 0
//std::sort
int Solution::maximumGap(vector<int>& nums) {
    if (nums.size() < 2) {
        return 0;
    }
    sort(nums.begin(), nums.end());
    int nMaxGap = 0;
    for (int i = 1; i < nums.size(); i++) {
        nMaxGap = max(nums[i] - nums[i - 1], nMaxGap);
    }
    return nMaxGap;
}
#else
//先排序去重，再计算排序后相邻之间的间距（性能差）
int Solution::maximumGap(vector<int>& nums) {
    if (nums.size() < 2) {
        return 0;
    }
    map<int, unsigned> mapCache;
    for (auto const &num : nums) {
        ++mapCache[num];
    }
    auto pos = mapCache.cbegin();
    int nPre = pos->first;
    ++pos;
    int nRet = 0;
    int nTmp = 0;
    while (pos != mapCache.cend()) {
        nTmp = abs(pos->first - nPre);
        if (nRet < nTmp) {
            nRet = nTmp;
        }
        nPre = pos->first;
        ++pos;
    }
    return nRet;
}
#endif


//171
//二十六进制
int Solution::titleToNumber(string s) {
    int nRet = 0;
    int i = 0;
    while (i < s.length()) {
        nRet += (s[i] - 'A' + 1) * pow(26, s.length() - 1 - i);
        ++i;
    }
    return nRet;
}


//179
//重写 std::sort() 的比较函数
string Solution::largestNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end(), [](int const &l, int const &r) {
        auto &&s1 = to_string(l);
        auto &&s2 = to_string(r);
        return s1 + s2 > s2 + s1;
    });
    string s = "";
    for (auto &&num : nums) {
        s += to_string(num);
    }
    return s[0] == '0' ? "0" : s;
}



//215
int Solution::findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;     //小根堆

    for (int i = 0; i < k; ++i) {
        minHeap.push(nums[i]);
    }
    auto const& size = nums.size();
    for (size_t i = k - 1; i < size; ++i) {
        if (minHeap.top() <= nums[i]) {
            minHeap.pop();
            minHeap.push(nums[i]);
        }
    }
    return minHeap.top();
}


//220
bool Solution::containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
	set<long> setCache;
	for (int i = 0; i < nums.size(); ++i) {
		auto s = setCache.lower_bound(long(nums[i]) - long(t));
		if (s != setCache.end() && *s <= long(nums[i]) + long(t)) {
			return true;
		}
		setCache.insert(nums[i]);
		if (setCache.size() > k) {
			setCache.erase(nums[i - k]);
		}
	}
	return false;
}


//222
int do_countNodes(TreeNode* root) {
    if (!root) {
        return 0;
    }
    return (nullptr != root->left) + (nullptr != root->right) +
        do_countNodes(root->left) + do_countNodes(root->right);
}
int Solution::countNodes(TreeNode* root) {
    if (!root) {
        return 0;
    }
#if 1
    return 1 + do_countNodes(root);
#else
    return 1 + countNodes(root->left) + countNodes(root->right);
#endif
}


//226
TreeNode* Solution::invertTree(TreeNode* root) {
    if (!root) {
        return nullptr;
    }
    TreeNode* p = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(p);
    return root;
}


//230
void do_kthSmallest(TreeNode* root, int& k, int& ans) {
    if (!root || k < 0) {
        return;
    }
    do_kthSmallest(root->left, k, ans);
    if (0 == --k) {
        ans = root->val;
        return;
    }
    do_kthSmallest(root->right, k, ans);
}
int Solution::kthSmallest(TreeNode* root, int k) {
    //中序遍历，左根右，返回第k个节点的值
    int res = 0;
    do_kthSmallest(root, k, res);
    return res;
}


//235
TreeNode* Solution::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //二叉搜索树的后续遍历
    if (p->val < root->val && q->val < root->val) {
        return lowestCommonAncestor(root->left, p, q);
    }
    if (p->val > root->val && q->val > root->val) {
        return lowestCommonAncestor(root->right, p, q);
    }
    return root;
}


//236
TreeNode* Solution::lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
    //二叉树的后序遍历
    if (!root) {
        return nullptr;
    }
    if (root == p || root == q) {
        return root;
    }
    TreeNode* left = lowestCommonAncestor2(root->left, p, q);
    TreeNode* right = lowestCommonAncestor2(root->right, p, q);
    if (left && right) {
        return root;
    } else if (left) {
        return left;
    } else {
        return right;
    }
    return nullptr;
}


//239
vector<int> Solution::maxSlidingWindow(vector<int>& nums, size_t k) {
    vector<int> ans(0);
    priority_queue<pair<int, int>> maxHeap; // 大根堆
    for (size_t i = 0; i < k - 1; ++i) {
        maxHeap.push(make_pair(nums[i], i));
    }
    for (size_t i = k - 1; i < nums.size(); ++i) {
        while (!maxHeap.empty() && (i - maxHeap.top().second >= k || maxHeap.top().first <= nums[i])) {
            //删除过期的或者不可能称为最大值的值
            maxHeap.pop();
        }
        maxHeap.push(make_pair(nums[i], i));
        ans.push_back(maxHeap.top().first);
    }
    return ans;
}


//242
#if 1
bool Solution::isAnagram(string s, string t) {
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	return s == t;
}
#elif 0
bool Solution::isAnagram(string s, string t) {
	if (s.length() != t.length()) {
		return false;
	}
	int arrCache[26] = { 0 };//26个英文字母
	for (int i = 0; i < s.length(); ++i) {
		++arrCache[s[i] - 'a'];
	}
	for (int i = 0; i < s.length(); ++i) {
		if (--arrCache[t[i] - 'a'] < 0) {
			return false;
		}
	}
	return true;
}
#elif 0
bool Solution::isAnagram(string s, string t) {
	if (s.length() != t.length()) {
		return false;
	}
	int arrCache[26] = { 0 };//26个英文字母
	for (int i = 0; i < s.length(); ++i) {
		++arrCache[s[i] - 'a'];
		--arrCache[t[i] - 'a'];
	}
	for (auto &&count : arrCache) {
		if (count != 0) {
			return false;
		}
	}
	return true;
}
#else
bool Solution::isAnagram(string s, string t) {
	if (s.length() != t.length()) {
		return false;
	}
	map<char, int> mapCache;
	int i = 0;
	while (i < s.length()) {
		++mapCache[s[i++]];
	}
	i = 0;
	while (i < t.length()) {
		if (--mapCache[t[i++]] < 0) {
			return false;
		}
	}
	return true;
}
#endif


//257
vector<string> Solution::binaryTreePaths(TreeNode* root) {
    if (!root) {
        return{};
    }
    if (!root->left && !root->right) {
        return vector<string>({ to_string(root->val) });
    }
    vector<string> left = binaryTreePaths(root->left);
    vector<string> right = binaryTreePaths(root->right);
    string cur = to_string(root->val) + "->";
    for (auto& s : left) {
        s = cur + s;
    }
    for (auto& s : right) {
        s = cur + s;
    }
    left.insert(left.end(), right.begin(), right.end());
    return left;
}


//264
int Solution::nthUglyNumber(int n) {
    vector<int> ans(n, 1);

    //三指针法
    vector<int> index(3, 0);

    for (int i = 1; i < n; ++i) {
        int a = ans[index[0]] * 2;
        int b = ans[index[1]] * 3;
        int c = ans[index[2]] * 5;
        int min = std::min(a, std::min(b, c));

        ans[i] = min;

        if (min == a) {
            ++index[0];
        }
        if (min == b) {
            ++index[1];
        }
        if (min == c) {
            ++index[2];
        }
    }
    return ans.back();
}


//313
int Solution::nthSuperUglyNumber(int n, vector<int>& primes) {
    vector<int> ans(n, 1);

    //多指针法
    auto const& primesSize = primes.size();
    vector<int> index(primesSize, 0);

    for (int i = 1; i < n; ++i) {
        int min = INT_MAX;

        for (size_t j = 0; j < primesSize; ++j) {
            auto const& temp = ans[index[j]] * primes[j];
            if (temp < min) {
                min = temp;
            }
        }

        ans[i] = min;

        for (size_t j = 0; j < primesSize; ++j) {
            if (ans[index[j]] * primes[j] == min) {
                ++index[j];
            }
        }
    }
    return ans.back();
}


//315
#if 1
//二叉搜索树
// binary search tree
struct BSTNode {
    int val;
    int smaller;//小于当前树节点的树节点个数：默认为0
    BSTNode *left, *right;
    BSTNode(int v) : val(v), smaller(0), left(nullptr), right(nullptr) {}
};
//建树
int insertBST(BSTNode *&root, int v) {
    if (!root) {
        root = new BSTNode(v);
        return 0;
    }
    if (v < root->val) {
        root->smaller++;
        return insertBST(root->left, v);
    } else {
        return insertBST(root->right, v) + root->smaller + (root->val < v ? 1 : 0);
    }
}
vector<int> Solution::countSmaller(vector<int>& nums) {
    vector<int> res(nums.size());
    BSTNode *root = nullptr;
    for (int i = nums.size() - 1; i >= 0; --i) {
        res[i] = insertBST(root, nums[i]);
    }
    return res;
}
#elif 0
//暴力法（超时）
vector<int> Solution::countSmaller(vector<int>& nums) {
    if (nums.size() == 0) {
        return {};
    }
    vector<int> vctRet(nums.size());
    int i, nCount;
    for (i = 0; i < nums.size() - 1; ++i) {
        nCount = 0;
        for (int j = i + 1; j < nums.size(); ++j) {
            nCount += nums[i] > nums[j];
        }
        vctRet[i] = nCount;
    }
    vctRet[i] = 0;
    return vctRet;
}
#else
//map::lower_bound（超时）
vector<int> Solution::countSmaller(vector<int>& nums) {
    vector<int> vctRet = {};
    map<int, unsigned> mapCache;
    int nCount;

    for (auto &&posVct = nums.rbegin(); posVct != nums.rend(); ++posVct) {
        nCount = 0;
        for (auto &&posMap = mapCache.begin(); posMap != mapCache.lower_bound(*posVct); ++posMap) {
            nCount += posMap->second;
        }
        vctRet.push_back(nCount);
        ++mapCache[*posVct];
    }

    std::reverse(vctRet.begin(), vctRet.end());
    return vctRet;
}
#endif


//324
#if 1
void Solution::wiggleSort(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	vector<int> a(nums);
	int i = 0;
	int m = (nums.size() / 2) - 1;
	int j = m;
	int k = nums.size() - 1;
	for (i = 0; i < nums.size();) {
		if (j >= 0) {
			nums[i++] = a[j--];
		}
		if (k >= m) {
			nums[i++] = a[k--];
		}
	}
}
#else
void Solution::wiggleSort(vector<int>& nums) {
	map<int, unsigned> mapCache;
	for (auto &&num : nums) {
		++mapCache[num];
	}

	auto pos1 = mapCache.begin();
	auto pos2 = mapCache.rbegin();
	for (int i = 0; i < nums.size(); ++i) {
		if (i % 2 == 0)	{
			while (pos1->second <= 0) {
				pos1 == mapCache.end() ? pos1 = mapCache.begin() : ++pos1;
			}
			nums[i] = pos1->first;
			pos1->second--;
			pos1 == mapCache.end() ? pos1 = mapCache.begin() : ++pos1;
		} else {
			while (pos2->second <= 0) {
				++pos2;
			}
			nums[i] = pos2->first;
			pos2->second--;
		}
	}
}
#endif



