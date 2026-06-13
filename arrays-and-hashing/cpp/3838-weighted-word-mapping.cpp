// Problem: weighted-word-mapping (LeetCode #3838)
// Link: https://leetcode.com/problems/weighted-word-mapping/
// Approach: HashMap - sum char weights, map to char via modulo
// Time: O(n*m) | Space: O(n)

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result;

        for (const string& word : words) {
            int totalWeight = 0;

            for (char ch : word) {
                totalWeight += weights[ch - 'a'];
            }

            result += ('z' - (totalWeight % 26));
        }

        return result;
    }
};
