class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(!mp.count(nums[i])){
                mp[nums[i]]=1;
            }
            else mp[nums[i]]++;
        }
        int n=mp.size();
        for (auto &pr : mp) {
            int num=pr.first;
            int freq=pr.second;

            if(mp.count(num+1)){
                int len=freq+mp[num+1];
                ans=max(len,ans);
            }
        }
        
        return ans;

    }
};