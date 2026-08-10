class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-1,i=n-1;
        vector<int>ans(n);
        while(l<=r){
            if(nums[l]* nums[l] >=nums[r]* nums[r]){
                ans[i]=nums[l]* nums[l];
                l++;
            }
            else{
                ans[i]=nums[r]* nums[r];
                r--;
            }
            i--;
        }
        return ans;
    }
};