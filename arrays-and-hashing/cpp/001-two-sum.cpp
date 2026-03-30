// Problem: Two Sum (LeetCode #1)
// Link: https://leetcode.com/problems/two-sum/
// Approach: HashMap — store each number's index, check if complement (target - nums[i]) exists
// Time: O(n) | Space: O(n)


class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            map<int, int> mp;
            int n = nums.size();
    
            for (int i = 0; i < n; i++) {
                int diff = target - nums[i];
    
                if (mp.count(diff)) {         
                    return {mp[diff], i};     
                }
    
                mp[nums[i]] = i;              
            }
            return {};
        }
    };