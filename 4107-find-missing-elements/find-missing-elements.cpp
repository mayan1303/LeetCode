class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>s;
        vector<int>ans;
        int max=*max_element(nums.begin(),nums.end());
        int min=*min_element(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        for(int j=min;j<=max;j++){
            if(!s.count(j)){
                ans.push_back(j);
            }
        }
        return ans;
            
    }
};