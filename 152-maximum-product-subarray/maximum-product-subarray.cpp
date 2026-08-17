class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int bestval=nums[0],worstval=nums[0],ans=nums[0];

        for(int i=1;i<nums.size();i++){
            int a=nums[i]*bestval;
            int b=nums[i]*worstval;
            int c=nums[i];

            bestval=max(a,max(b,c));
            worstval=min(a,min(b,c));
            ans=max(ans,bestval);
        }
        return ans;
    }
};