class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int>s;
        if(k==0){
            return false;
        }
        int l=0,r=0;
        while(l<=r&& r<nums.size()){
            
            while(r-l>k){
                s.erase(nums[l]);
                l++;
                
            }

            if(s.count(nums[r])){
                return true;
            }
            else{
                s.insert(nums[r]);
            }
            r++;
        }
        return false;
    }
};