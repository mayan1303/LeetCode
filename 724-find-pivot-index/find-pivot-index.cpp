class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0,left=0,right=0,n=nums.size(),ans=-1;

        for(int i=0;i<n;i++){
            sum+=nums[i];
        }

        for(int i=0;i<n;i++){
            right=(sum-left)- nums[i];
            if(left==right){
                ans=i;
                break;
            }
            left+=nums[i];
            

        }

        return ans;
    }
};