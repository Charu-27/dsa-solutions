// Problem: minimum-distance-between-three-equal-elements-i (LeetCode #3740)
// Link: https://leetcode.com/problems/minimum-distance-between-three-equal-elements-i/
// Approach: HashMap to group indices, sliding window of 3 equal elements
// Time: O(n) | Space: O(n)

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int sum = 0, ans = INT_MAX;  
        map<int, vector<int>> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        for (auto& it : mp) {
            vector<int>& idx = it.second; 
            if (idx.size() >= 3) {
                for (int i = 0; i < idx.size() - 2; i++) {
                    sum = abs(idx[i] - idx[i+1]) + abs(idx[i+1] - idx[i+2]) + abs(idx[i] - idx[i+2]);
                    ans = min(sum, ans);  
                }
            }
        }
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};

