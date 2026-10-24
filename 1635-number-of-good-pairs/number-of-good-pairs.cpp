class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        int ans=0;

        for(int i=0;i<nums.size();i++){
            if(!mp.count(nums[i])){
                mp[nums[i]]=1;
            }
            else mp[nums[i]]++;
        }
        for(auto &pr : mp){
            if(pr.second==1){
                continue;
            }
            else{
                int a=pr.second;
                int b= (a* (a-1))/2;
                ans+=b;
            }
        }
        return ans;
    }
};