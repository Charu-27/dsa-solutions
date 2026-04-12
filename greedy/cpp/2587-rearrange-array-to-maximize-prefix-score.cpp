// Problem: rearrange-array-to-maximize-prefix-score (LeetCode #2587)
// Link: https://leetcode.com/problems/rearrange-array-to-maximize-prefix-score/
// Approach: Greedy - sort descending + prefix sum
// Time: O(n log n) | Space: O(n)

class Solution {
public:
    int maxScore(vector<int>& nums) {
       int n = nums.size();
       int ans = 0;
       sort(nums.begin(),nums.end());
       reverse(nums.begin(),nums.end());
       vector<long long> prefix(n);     
       prefix[0]=nums[0];
       if(prefix[0]>0){
        ans++;
       }
       for(int i =1;i<n;i++){
           prefix[i]=prefix[i-1]+nums[i]; 
          if(prefix[i]>0){
            ans++;
          }
       }
       return ans;
    }
};

