class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>pre(n+1);
        unordered_map<int,int>mp;
        mp[0]=0;
        
        for(int i=0;i<n;i++){
            pre[i+1] = pre[i] + nums[i];
             cout<<pre[i]<<" ";
        }

        for(int i=1;i<=n;i++){
            int rem=pre[i]%k;

            if(mp.count(rem)){
                if(i-mp[rem]>=2)return true;
            }
            else{
                mp[rem]=i;
            }
        }
           
        
        return false;
    }
};