class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            if(!mp.count(nums[i])){
                mp[nums[i]]=1;
            }
            else{
                mp[nums[i]]++;
            }
            if(mp[nums[i]]==3){
                mp.erase(nums[i]);
            }
        }
        return mp.begin()->first;
    }
};