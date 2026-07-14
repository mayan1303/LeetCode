class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;

        int m=0,ans;

        for(int i=0;i<nums.size();i++){
            if(mp.count(nums[i])){
                mp[nums[i]]+=1;
                if(mp[nums[i]]>m){
                    m=mp[nums[i]];
                }
            }
            mp[nums[i]]++;
            m = max(m, mp[nums[i]]);
        }
        
        if(m> nums.size()/2){
            for(auto it = mp.begin(); it != mp.end(); ++it){
                if(m==(*it).second){
                    ans=(*it).first;
                    break;
                }
            }
        }
        return ans;
    }
};