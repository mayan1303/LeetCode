class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int ans=0;
        int l=nums.size();
        for(int i=0;i<nums.size();i++){
            int ind=i+1;
            if(l % ind ==0){
                ans+=nums[i]*nums[i];
            }
        }

        return ans;

    }
};