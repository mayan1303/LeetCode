class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size(),sum=0,psum=0,ans=0;

        
            

        for(int i=0;i<n;i++){
            mp[sum]++;
            sum+=nums[i];
        
            if(mp.count(sum-k)){
                ans+=mp[sum-k];
            }
            
        }
        return ans;

      }
};