class Solution {
public:


    int numSum(vector<int>& nums, int t){
        int l=0,sum=0,count=0;

        for(int r=0;r<nums.size();r++){
            sum+=nums[r]%2;
            while(sum>t){
                sum-=nums[l]%2;
                l++;
            }
            count+=r-l+1;
        }
    return count;
    }


    int numberOfSubarrays(vector<int>& nums, int k) {

        return numSum(nums, k) - numSum(nums,k-1);
    }
};