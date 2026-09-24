class Solution {
public:
    int ma(vector<int>& nums, int s, int e){
        int ans=-1;
        for(int i=s;i<=e;i++){
            ans=max(ans,nums[i]);
        }
        return ans;
    }
    int mi(vector<int>& nums, int s, int e){
        int ans=INT_MAX;
        for(int i=s;i<=e;i++){
            ans=min(ans,nums[i]);
        }
        return ans;
    }

    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            int res=ma(nums,0,i)-mi(nums,i,n-1);
            if(res<=k){
                return i;
            }
        }
        return -1;
    }
};