// Problem: longest-substring-without-repeating-characters (LeetCode #003)
// Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Approach: Sliding Window with frequency map
// Time: O(n) | Space: O(min(n, m)) where m is the charset size

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char,int> freq;                
        int len = 0;
        int i = 0,j=0;
        while(i < n && j < n){
            freq[s[j]]++;
            while(freq[s[j]]>1){
                freq[s[i]]--;
                i++;
            }
            len = max(len, j-i+1);
            j++;

        }
        return len;
    }
};

