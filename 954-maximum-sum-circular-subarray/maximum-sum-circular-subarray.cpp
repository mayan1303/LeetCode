class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int bestval=nums[0],worstval=nums[0],sum=nums[0],ans=nums[0],minans=nums[0];

        for(int i=1;i<nums.size();i++){
            sum+=nums[i];
            int a=nums[i]+bestval;
            int b=nums[i];
            bestval=max(a,b);
            ans=max(ans,bestval);

            int c=nums[i]+worstval;
            
            worstval=min(b,c);
            minans= min(worstval,minans);
        }

        if(ans<0) return ans;
        return max(ans,sum-minans);
    }
};