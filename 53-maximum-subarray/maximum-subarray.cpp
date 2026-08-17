class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int bestval=nums[0],ans=nums[0];

        for(int i=1;i<nums.size();i++){
            int a=nums[i];
            int b=nums[i]+bestval;

            bestval=max(a,b);
            ans=max(ans,bestval);
        }
        return ans;
    }
};