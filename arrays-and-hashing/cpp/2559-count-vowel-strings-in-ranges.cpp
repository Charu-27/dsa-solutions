// Problem: count-vowel-strings-in-ranges (LeetCode #2559)
// Link: https://leetcode.com/problems/count-vowel-strings-in-ranges/
// Approach: Prefix Sum
// Time: O(n + q) | Space: O(n)

class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    bool startsAndEndsWithVowel(const string& word) {
        return isVowel(word.front()) && isVowel(word.back());
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();

        // prefix sum
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + startsAndEndsWithVowel(words[i]);
        }

        //count of vowel strings in range [l, r]
        vector<int> ans;
        ans.reserve(queries.size());
        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];
            ans.push_back(prefix[r + 1] - prefix[l]);
        }

        return ans;
    }
};

