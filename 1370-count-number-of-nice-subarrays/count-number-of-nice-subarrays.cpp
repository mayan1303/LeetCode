class Solution {
public:


    int numSum(vector<int>& nums, int t){
        int l=0,sum=0,count=0;

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


    int numberOfSubarrays(vector<int>& nums, int k) {

        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0) nums[i]=0;
            else nums[i]=1;
        }

        return numSum(nums, k) - numSum(nums,k-1);
    }
};