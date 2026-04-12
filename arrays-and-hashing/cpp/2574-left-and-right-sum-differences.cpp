// Problem: left-and-right-sum-differences (LeetCode #2574)
// Link: https://leetcode.com/problems/left-and-right-sum-differences/
// Approach: Prefix Sum (left and right)
// Time: O(n) | Space: O(n)

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSum(n,0);
        vector<int> rightSum(n,0);
        vector<int> ans;
        leftSum[0]=nums[0];
        for(int i =1;i<n;i++){
            leftSum[i]=leftSum[i-1]+nums[i];
        }
        rightSum[0]=nums[n-1];
        for(int i = 1;i<n;i++){
            rightSum[i]=rightSum[i-1]+nums[n-(i+1)];
        }
        reverse(rightSum.begin(),rightSum.end());

        for(int i = 0;i<n;i++){
            ans.push_back(abs(leftSum[i]-rightSum[i]));
        }
        return ans;
        
    }
};

