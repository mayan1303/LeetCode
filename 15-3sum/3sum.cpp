class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();

        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++){
            int c=-1 * nums[i];

            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int l=i+1,r=n-1;

            while(l<r){


                if(nums[l]+ nums[r]==c){
                    vector<int> temp = {nums[i], nums[l], nums[r]};

                    ans.push_back(temp);
                    l++;
                    r--;

                    while (l < r && nums[l] == nums[l - 1]) l++;
                    while (l < r && nums[r] == nums[r + 1]) r--;
                }
                else if(nums[l]+ nums[r]<c){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        
    return ans;
    }
};