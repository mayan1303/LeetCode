class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>s;

        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }

        int i=k;
        int f=-1;
        while(f==-1){
            if(s.count(i)){
                i+=k;
            }
            else{
                f=0;
            }
        }

        return i;
    }
};