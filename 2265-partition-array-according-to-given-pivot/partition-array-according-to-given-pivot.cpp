class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int> ans(n);
        int l=0,e=0,g=0;
        for(int i=0;i<n;i++){
            if(nums[i]==pivot) e++;
            else if(nums[i]<pivot) l++;
            else g++;
        }

        int i=0;
        int j=i+l;
        int k=j+e;

        for(int a=0;a<n;a++){
            if(nums[a]==pivot){
                ans[j]=nums[a];
                j++;
            }
            else if(nums[a]<pivot){
                 ans[i]=nums[a];
                 i++;
            }
            else{
                ans[k]=nums[a];
                k++;
            }
        }
    return ans;
    }
};