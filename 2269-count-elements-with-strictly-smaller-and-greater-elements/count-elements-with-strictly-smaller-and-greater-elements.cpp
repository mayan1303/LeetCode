class Solution {
public:
    int countElements(vector<int>& nums) {
        int n=nums.size();
        int mx=INT_MIN,mn=INT_MAX;
        int ans=0;

        for(int i=0;i<n;i++){
            if(nums[i]<mn){
                mn=min(nums[i],mn);
            }
            if(nums[i]>mx){
                mx=max(nums[i],mx);
            }
        }

        for(int x : nums){
            if(x>mn && x<mx){
                ans++;
            }
        }
    return ans;
    }
};