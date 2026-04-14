// Problem: Longest Common Prefix (LeetCode #14)
// Link: https://leetcode.com/problems/longest-common-prefix/
// Approach: Sort strings; the LCP of the whole array equals the LCP of the first and last after sort
// Time: O(n * m log n) | Space: O(1) auxiliary (output not counted; sort may use extra space)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        sort(strs.begin(), strs.end());
        string s1 = strs[0];
        string s2 = strs[n - 1];
        int idx = 0;
        while (idx < s1.length() && idx < s2.length()) {
            if (s1[idx] == s2[idx]) {
                idx++;
            } else {
                break;
            }
        }
        return s1.substr(0, idx);
    }
};
