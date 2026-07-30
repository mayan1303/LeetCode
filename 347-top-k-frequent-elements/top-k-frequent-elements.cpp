class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n= nums.size();
        vector<int> ans;
        int a=0,b=0;

        unordered_map<int,int> mp;

        if(n<2){
            return nums;
        }

        for(int i=0;i<n;i++){
                mp[nums[i]]+=1;
            
        }
        vector<pair<int,int>> freq;
        for(const auto & [key,value] : mp){
            freq.push_back({value,key});
        }
        int o=freq.size();
        sort(freq.begin(),freq.end());

        for(int i=0;i<k;i++){
            ans.push_back(freq[o-i-1].second);
        }

    return ans;
    }
};