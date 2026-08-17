class Solution {
public:
    int numSum(vector<int>& nums, int t){
        int l=0,sum=0,count=0;
        if(t<0) return 0;

        for(int r=0;r<nums.size();r++){
            sum+=nums[r];
            while(sum>t){
                sum-=nums[l];
                l++;
            }
            count+=r-l+1;
        }
        return count;
    }


    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return numSum(nums,goal) - numSum(nums,goal-1);
    }
};