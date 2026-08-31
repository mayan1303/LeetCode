class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int tot=0;
        int left=0;
        for(int i=0;i<n;i++){
            tot+=nums[i];
        }
        for(int i=0;i<n;i++){
            int right=tot-left-nums[i];
            if(right==left) return i;

            left+=nums[i];
        }

    return -1;
    }
};