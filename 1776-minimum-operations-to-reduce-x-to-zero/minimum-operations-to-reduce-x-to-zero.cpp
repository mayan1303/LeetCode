class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int l=0;
        int sum=0;
        int res=-1;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int sum1=sum-x;
        int curr=0;
        for(int r=0;r<n;r++){
            curr+=nums[r];

            while(curr>sum1 && l<=r){
                curr-=nums[l];
                l++;
            }

            if(sum1==curr){
                res=max(res,r-l+1);
            }
            
        }
        if(res==-1) return res;
        return n-res;

    }
};