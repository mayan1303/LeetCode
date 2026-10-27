class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        int n=nums1.size();
        int m=nums2.size();
        vector<int>ans(n,-1);
        for(int i=0;i<m;i++){
            mp[nums2[i]]=i;
        }

        for(int i=0;i<n;i++){
            int k=1;
            int j=mp[nums1[i]];
            while(j+k<m  ){
                if(nums2[j+k]>nums1[i]){
                    ans[i]=nums2[j+k];
                    break;
                }
                else k++;
            }
        }
        return ans;
    }
};