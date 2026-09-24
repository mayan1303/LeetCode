class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>s;

        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }

        int i=k;
        
        while(s.count(i)){
            
                i+=k;
            
        }

        return i;
    }
};