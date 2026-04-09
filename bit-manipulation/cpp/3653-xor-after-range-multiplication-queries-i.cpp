// Problem: xor-after-range-multiplication-queries-i (LeetCode #3653)
// Link: https://leetcode.com/problems/xor-after-range-multiplication-queries-i/
// Approach: Brute Force - process each query and XOR all elements
// Time: O(Q * N) | Space: O(1)

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int ans = 0;
         const int MOD = 1e9 + 7;
        for(int i =0;i<queries.size();i++){
                int l = queries[i][0];
                int r = queries[i][1];
                int k = queries[i][2];
                int v = queries[i][3];
                for(int idx = l;idx<=r;idx+=k){
                   nums[idx] = (int)(((long long)nums[idx] * v) % MOD);
                }
        }
    
        for(int i =0;i<nums.size();i++){
            ans = ans ^ nums[i];
        }
        return ans;
    }
};

