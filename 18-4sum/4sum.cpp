class Solution {
public:
    vector<vector<int>> twosum(vector<int>& nums, long long target,int i){
        vector<vector<int>>t;
        int n=nums.size();
        int l=i;
        int r=n-1;
        
        while(l<r){
            long long sum=(long long)nums[l]+nums[r];
            if(sum==target){
                t.push_back({nums[l],nums[r]});
                int left=nums[l];
                int right=nums[r];
                while(l<r && nums[l]==left){
                    l++;
                }
                while(l<r && nums[r]==right){
                    r--;
                }

            }
            else if(nums[l]+nums[r]<target){
                l++;
            }
            else{
                r--;
            }
        }
        return t;
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>ans;

        for(int i=0;i<n-3;i++){

            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n-2;j++){

                if(j>i+1 && nums[j]==nums[j-1]) continue;

                long long s=(long long)nums[i]+nums[j];

                vector<vector<int>> a=twosum(nums,target-s,j+1);
                
                if(!a.empty()){
                for(int k=0;k<a.size();k++){
                    ans.push_back({nums[i],nums[j],a[k][0],a[k][1]});
                }
                }
            }
        }
        return ans;
    }
};