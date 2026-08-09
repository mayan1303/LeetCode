class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        int i=0,j=1,k=0;

        while(j<n || i<n){
            if(nums[k]>0){
                ans[i]=nums[k];
                k++;
                i+=2;
                
            }
            else if(nums[k]<0){
                ans[j]=nums[k];
                k++;
                j+=2;
                
            }
        }
    return ans;

    }
};