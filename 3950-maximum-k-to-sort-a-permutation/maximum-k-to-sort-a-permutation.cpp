class Solution {
public:

    int sortPermutation(vector<int>& nums) {
        int n=nums.size();
        int f=0;
        int ans=INT_MAX;

        for(int i=0;i<n;i++){
            if(nums[i]!=i){
                f=1;
                ans&=nums[i];
            }
            else continue;
        }
        if(f==0) return f;
        else return ans;
    }
};